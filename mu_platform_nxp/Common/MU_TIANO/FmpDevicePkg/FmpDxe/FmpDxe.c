/** @file
  Produces a Firmware Management Protocol that supports updates to a firmware
  image stored in a firmware device with platform and firmware device specific
  information provided through PCDs and libraries.

// MU_CHANGE Starts
  Copyright (c) Microsoft Corporation.<BR>
// MU_CHANGE Ends
  Copyright (c) 2018 - 2020, Intel Corporation. All rights reserved.<BR>

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "FmpDxe.h"
#include "VariableSupport.h"
#include "Dependency.h"

///
/// FILE_GUID from FmpDxe.inf.  When FmpDxe.inf is used in a platform, the
/// FILE_GUID must always be overridden in the <Defines> section to provide
/// the ESRT GUID value associated with the updatable firmware image.  A
/// check is made in this module's driver entry point to verify that a
/// new FILE_GUID value has been defined.
///
const EFI_GUID  mDefaultModuleFileGuid = {
  0x78ef0a56, 0x1cf0, 0x4535, { 0xb5, 0xda, 0xf6, 0xfd, 0x2f, 0x40, 0x5a, 0x11 }
};

///
/// TRUE if FmpDeviceLib manages a single firmware storage device.
///
BOOLEAN  mFmpSingleInstance = FALSE;

///
/// Firmware Management Protocol instance that is initialized in the entry
/// point from PCD settings.
///
EDKII_FIRMWARE_MANAGEMENT_PROGRESS_PROTOCOL  mFmpProgress;

//
// Template of the private context structure for the Firmware Management
// Protocol instance
//
const FIRMWARE_MANAGEMENT_PRIVATE_DATA  mFirmwareManagementPrivateDataTemplate = {
  FIRMWARE_MANAGEMENT_PRIVATE_DATA_SIGNATURE,  // Signature
  NULL,                                        // Handle
  {                                            // Fmp
    GetTheImageInfo,
    GetTheImage,
    SetTheImage,
    CheckTheImage,
    GetPackageInfo,
    SetPackageInfo
  },
  FALSE,                                       // DescriptorPopulated
  {                                            // Desc
    1,     // ImageIndex
    //
    // ImageTypeId
    //
    { 0x00000000, 0x0000, 0x0000, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} },
    1,     // ImageId
    NULL,  // ImageIdName
    0,     // Version
    NULL,  // VersionName
    0,     // Size
    0,     // AttributesSupported
    0,     // AttributesSetting
    0,     // Compatibilities
    0,     // LowestSupportedImageVersion
    0,     // LastAttemptVersion
    0,     // LastAttemptStatus
    0      // HardwareInstance
  },
  NULL,                                        // ImageIdName
  NULL,                                        // VersionName
  TRUE,                                        // RuntimeVersionSupported
  NULL,                                        // FmpDeviceLockEvent
  FALSE,                                       // FmpDeviceLocked
  NULL,                                        // FmpDeviceContext
  NULL,                                        // VersionVariableName
  NULL,                                        // LsvVariableName
  NULL,                                        // LastAttemptStatusVariableName
  NULL,                                        // LastAttemptVersionVariableName
  NULL                                         // FmpStateVariableName
};

///
/// GUID that is used to create event used to lock the firmware storage device.
///
EFI_GUID  *mLockGuid = NULL;

///
/// Progress() function pointer passed into SetTheImage()
///
EFI_FIRMWARE_MANAGEMENT_UPDATE_IMAGE_PROGRESS  mProgressFunc = NULL;

///
/// Null-terminated Unicode string retrieved from PcdFmpDeviceImageIdName.
///
CHAR16  *mImageIdName = NULL;

/**
  Callback function to report the process of the firmware updating.

  Wrap the caller's version in this so that progress from the device lib is
  within the expected range.  Convert device lib 0% - 100% to 6% - 98%.

  FmpDxe        1% -   5%  for validation
  FmpDeviceLib  6% -  98%  for flashing/update
  FmpDxe       99% - 100%  finish

  @param[in] Completion  A value between 1 and 100 indicating the current
                         completion progress of the firmware update. Completion
                         progress is reported as from 1 to 100 percent. A value
                         of 0 is used by the driver to indicate that progress
                         reporting is not supported.

  @retval  EFI_SUCCESS      The progress was updated.
  @retval  EFI_UNSUPPORTED  Updating progress is not supported.

**/
EFI_STATUS
EFIAPI
FmpDxeProgress (
  IN UINTN  Completion
  )
{
  EFI_STATUS Status;

  Status = EFI_UNSUPPORTED;

  if (mProgressFunc == NULL) {
    return Status;
  }

  //
  // Reserve 6% - 98% for the FmpDeviceLib.  Call the real progress function.
  //
  Status = mProgressFunc (((Completion * 92) / 100) + 6);

  if (Status == EFI_UNSUPPORTED) {
    mProgressFunc = NULL;
  }

  return Status;
}

/**
  Returns a pointer to the ImageTypeId GUID value.  An attempt is made to get
  the GUID value from the FmpDeviceLib. If the FmpDeviceLib does not provide
  a GUID value, then PcdFmpDeviceImageTypeIdGuid is used.  If the size of
  PcdFmpDeviceImageTypeIdGuid is not the size of EFI_GUID, then gEfiCallerIdGuid
  is returned.

  @retval  The ImageTypeId GUID

**/
EFI_GUID *
GetImageTypeIdGuid (
  VOID
  )
{
  EFI_STATUS  Status;
  EFI_GUID    *FmpDeviceLibGuid;
  UINTN       ImageTypeIdGuidSize;

  FmpDeviceLibGuid = NULL;
  Status = FmpDeviceGetImageTypeIdGuidPtr (&FmpDeviceLibGuid);
  if (EFI_ERROR (Status)) {
    if (Status != EFI_UNSUPPORTED) {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): FmpDeviceLib GetImageTypeIdGuidPtr() returned invalid error %r\n", mImageIdName, Status));
    }
  } else if (FmpDeviceLibGuid == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): FmpDeviceLib GetImageTypeIdGuidPtr() returned invalid GUID\n", mImageIdName));
    Status = EFI_NOT_FOUND;
  }
  if (EFI_ERROR (Status)) {
    ImageTypeIdGuidSize = PcdGetSize (PcdFmpDeviceImageTypeIdGuid);
    if (ImageTypeIdGuidSize == sizeof (EFI_GUID)) {
      FmpDeviceLibGuid = (EFI_GUID *)PcdGetPtr (PcdFmpDeviceImageTypeIdGuid);
    } else {
      // MU_CHANGE start - this is a misconfiguration error, we should assert
      ASSERT(FALSE);
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): Fall back to ImageTypeIdGuid of gEfiCallerIdGuid. FmpDxe error: misconfiguration\n", mImageIdName));
      // MU_CHANGE end
      FmpDeviceLibGuid = &gEfiCallerIdGuid;
    }
  }
  return FmpDeviceLibGuid;
}

/**
  Returns a pointer to the Null-terminated Unicode ImageIdName string.

  @retval  Null-terminated Unicode ImageIdName string.

**/
CHAR16 *
GetImageTypeNameString (
  VOID
  )
{
  return mImageIdName;
}

/**
  Lowest supported version is a combo of three parts.
  1. Check if the device lib has a lowest supported version
  2. Check if we have a variable for lowest supported version (this will be updated with each capsule applied)
  3. Check Fixed at build PCD

  @param[in] Private  Pointer to the private context structure for the
                      Firmware Management Protocol instance.

  @retval  The largest value

**/
UINT32
GetLowestSupportedVersion (
  FIRMWARE_MANAGEMENT_PRIVATE_DATA  *Private
  )
{
  EFI_STATUS  Status;
  UINT32      DeviceLibLowestSupportedVersion;
  UINT32      VariableLowestSupportedVersion;
  UINT32      ReturnLsv;

  //
  // Get the LowestSupportedVersion.
  //

  if (!IsLowestSupportedVersionCheckRequired ()) {
    //
    // Any Version can pass the 0 LowestSupportedVersion check.
    //
    return 0;
  }

  ReturnLsv = PcdGet32 (PcdFmpDeviceBuildTimeLowestSupportedVersion);

  //
  // Check the FmpDeviceLib
  //
  DeviceLibLowestSupportedVersion = DEFAULT_LOWESTSUPPORTEDVERSION;
  Status = FmpDeviceGetLowestSupportedVersion (&DeviceLibLowestSupportedVersion);
  if (EFI_ERROR (Status)) {
    DeviceLibLowestSupportedVersion = DEFAULT_LOWESTSUPPORTEDVERSION;
  }

  if (DeviceLibLowestSupportedVersion > ReturnLsv) {
    ReturnLsv = DeviceLibLowestSupportedVersion;
  }

  //
  // Check the lowest supported version UEFI variable for this device
  //
  VariableLowestSupportedVersion = GetLowestSupportedVersionFromVariable (Private);
  if (VariableLowestSupportedVersion > ReturnLsv) {
    ReturnLsv = VariableLowestSupportedVersion;
  }

  //
  // Return the largest value
  //
  return ReturnLsv;
}

/**
  Populates the EFI_FIRMWARE_IMAGE_DESCRIPTOR structure in the private
  context structure.

  @param[in] Private  Pointer to the private context structure for the
                      Firmware Management Protocol instance.

**/
VOID
PopulateDescriptor (
  FIRMWARE_MANAGEMENT_PRIVATE_DATA  *Private
  )
{
  EFI_STATUS  Status;
  VOID        *Image;
  UINTN       ImageSize;
  BOOLEAN     IsDepexValid;
  UINT32      DepexSize;

  Image     = NULL;
  ImageSize = 0;

  if (Private->DescriptorPopulated) {
    return;
  }

  Private->Descriptor.ImageIndex = 1;
  CopyGuid (&Private->Descriptor.ImageTypeId, GetImageTypeIdGuid());
  Private->Descriptor.ImageId     = Private->Descriptor.ImageIndex;
  Private->Descriptor.ImageIdName = GetImageTypeNameString();

  //
  // Get the hardware instance from FmpDeviceLib
  //
  Status = FmpDeviceGetHardwareInstance (&Private->Descriptor.HardwareInstance);
  if (Status == EFI_UNSUPPORTED) {
    Private->Descriptor.HardwareInstance = 0;
  }

  //
  // Generate UEFI Variable names used to store status information for this
  // FMP instance.
  //
  GenerateFmpVariableNames (Private);

  //
  // Get the version.  Some devices don't support getting the firmware version
  // at runtime.  If FmpDeviceLib does not support returning a version, then
  // it is stored in a UEFI variable.
  //
  Status = FmpDeviceGetVersion (&Private->Descriptor.Version);
  if (Status == EFI_UNSUPPORTED) {
    Private->RuntimeVersionSupported = FALSE;
    Private->Descriptor.Version = GetVersionFromVariable (Private);
  } else if (EFI_ERROR (Status)) {
    //
    // Unexpected error.   Use default version.
    //
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): GetVersion() from FmpDeviceLib (%s) returned %r\n", mImageIdName, GetImageTypeNameString(), Status));
    Private->Descriptor.Version = DEFAULT_VERSION;
  }

  //
  // Free the current version name.  Shouldn't really happen but this populate
  // function could be called multiple times (to refresh).
  //
  if (Private->Descriptor.VersionName != NULL) {
    FreePool (Private->Descriptor.VersionName);
    Private->Descriptor.VersionName = NULL;
  }

  //
  // Attempt to get the version string from the FmpDeviceLib
  //
  Status = FmpDeviceGetVersionString (&Private->Descriptor.VersionName);
  if (Status == EFI_UNSUPPORTED) {
    DEBUG ((DEBUG_INFO, "FmpDxe(%s): GetVersionString() unsupported in FmpDeviceLib.\n", mImageIdName));
    Private->Descriptor.VersionName = AllocateCopyPool (
                                        sizeof (VERSION_STRING_NOT_SUPPORTED),
                                        VERSION_STRING_NOT_SUPPORTED
                                        );
  } else if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_INFO, "FmpDxe(%s): GetVersionString() not available in FmpDeviceLib.\n", mImageIdName));
    Private->Descriptor.VersionName = AllocateCopyPool (
                                        sizeof (VERSION_STRING_NOT_AVAILABLE),
                                        VERSION_STRING_NOT_AVAILABLE
                                        );
  }

  Private->Descriptor.LowestSupportedImageVersion = GetLowestSupportedVersion (Private);

  //
  // Get attributes from the FmpDeviceLib
  //
  FmpDeviceGetAttributes (
    &Private->Descriptor.AttributesSupported,
    &Private->Descriptor.AttributesSetting
    );

  //
  // Force set the updatable bits in the attributes;
  //
  Private->Descriptor.AttributesSupported |= IMAGE_ATTRIBUTE_IMAGE_UPDATABLE;
  Private->Descriptor.AttributesSetting   |= IMAGE_ATTRIBUTE_IMAGE_UPDATABLE;

  //
  // Force set the authentication bits in the attributes;
  //
  Private->Descriptor.AttributesSupported |= (IMAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED);
  Private->Descriptor.AttributesSetting   |= (IMAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED);

  Private->Descriptor.Compatibilities = 0;

  //
  // Get the size of the firmware image from the FmpDeviceLib
  //
  Status = FmpDeviceGetSize (&Private->Descriptor.Size);
  if (EFI_ERROR (Status)) {
    Private->Descriptor.Size = 0;
  }

  Private->Descriptor.LastAttemptVersion = GetLastAttemptVersionFromVariable (Private);
  Private->Descriptor.LastAttemptStatus  = GetLastAttemptStatusFromVariable (Private);

  //
  // Get the dependency from the FmpDeviceLib and populate it to the descriptor.
  //
  Private->Descriptor.Dependencies = NULL;

  //
  // Check the attribute IMAGE_ATTRIBUTE_DEPENDENCY
  //
  if (Private->Descriptor.AttributesSupported & IMAGE_ATTRIBUTE_DEPENDENCY) {
    //
    // The parameter "Image" of FmpDeviceGetImage() is extended to contain the dependency.
    // Get the dependency from the Image.
    //
    ImageSize = Private->Descriptor.Size;
    Image = AllocatePool (ImageSize);
    if (Image != NULL) {
      Status = FmpDeviceGetImage (Image, &ImageSize);
      if (Status == EFI_BUFFER_TOO_SMALL) {
        FreePool (Image);
        Image = AllocatePool (ImageSize);
        if (Image != NULL) {
          Status = FmpDeviceGetImage (Image, &ImageSize);
        }
      }
    }
    if (!EFI_ERROR (Status) && Image != NULL) {
      IsDepexValid = ValidateImageDepex ((EFI_FIRMWARE_IMAGE_DEP *) Image, ImageSize, &DepexSize);
      if (IsDepexValid) {
        Private->Descriptor.Dependencies = AllocatePool (DepexSize);
        if (Private->Descriptor.Dependencies != NULL) {
          CopyMem (Private->Descriptor.Dependencies->Dependencies, Image, DepexSize);
        }
      }
    }
  }

  Private->DescriptorPopulated = TRUE;

  if (Image != NULL) {
    FreePool (Image);
  }
}

/**
  Returns information about the current firmware image(s) of the device.

  This function allows a copy of the current firmware image to be created and saved.
  The saved copy could later been used, for example, in firmware image recovery or rollback.

  @param[in]      This               A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.
  @param[in, out] ImageInfoSize      A pointer to the size, in bytes, of the ImageInfo buffer.
                                     On input, this is the size of the buffer allocated by the caller.
                                     On output, it is the size of the buffer returned by the firmware
                                     if the buffer was large enough, or the size of the buffer needed
                                     to contain the image(s) information if the buffer was too small.
  @param[in, out] ImageInfo          A pointer to the buffer in which firmware places the current image(s)
                                     information. The information is an array of EFI_FIRMWARE_IMAGE_DESCRIPTORs.
  @param[out]     DescriptorVersion  A pointer to the location in which firmware returns the version number
                                     associated with the EFI_FIRMWARE_IMAGE_DESCRIPTOR.
  @param[out]     DescriptorCount    A pointer to the location in which firmware returns the number of
                                     descriptors or firmware images within this device.
  @param[out]     DescriptorSize     A pointer to the location in which firmware returns the size, in bytes,
                                     of an individual EFI_FIRMWARE_IMAGE_DESCRIPTOR.
  @param[out]     PackageVersion     A version number that represents all the firmware images in the device.
                                     The format is vendor specific and new version must have a greater value
                                     than the old version. If PackageVersion is not supported, the value is
                                     0xFFFFFFFF. A value of 0xFFFFFFFE indicates that package version comparison
                                     is to be performed using PackageVersionName. A value of 0xFFFFFFFD indicates
                                     that package version update is in progress.
  @param[out]     PackageVersionName A pointer to a pointer to a null-terminated string representing the
                                     package version name. The buffer is allocated by this function with
                                     AllocatePool(), and it is the caller's responsibility to free it with a call
                                     to FreePool().

  @retval EFI_SUCCESS                The device was successfully updated with the new image.
  @retval EFI_BUFFER_TOO_SMALL       The ImageInfo buffer was too small. The current buffer size
                                     needed to hold the image(s) information is returned in ImageInfoSize.
  @retval EFI_INVALID_PARAMETER      ImageInfoSize is NULL.
  @retval EFI_DEVICE_ERROR           Valid information could not be returned. Possible corrupted image.

**/
EFI_STATUS
EFIAPI
GetTheImageInfo (
  IN     EFI_FIRMWARE_MANAGEMENT_PROTOCOL  *This,
  IN OUT UINTN                             *ImageInfoSize,
  IN OUT EFI_FIRMWARE_IMAGE_DESCRIPTOR     *ImageInfo,
  OUT    UINT32                            *DescriptorVersion,
  OUT    UINT8                             *DescriptorCount,
  OUT    UINTN                             *DescriptorSize,
  OUT    UINT32                            *PackageVersion,
  OUT    CHAR16                            **PackageVersionName
  )
{
  EFI_STATUS                        Status;
  FIRMWARE_MANAGEMENT_PRIVATE_DATA  *Private;

  Status = EFI_SUCCESS;

  //
  // Retrieve the private context structure
  //
  Private = FIRMWARE_MANAGEMENT_PRIVATE_DATA_FROM_THIS (This);
  FmpDeviceSetContext (Private->Handle, &Private->FmpDeviceContext);

  //
  // Check for valid pointer
  //
  if (ImageInfoSize == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): GetImageInfo() - ImageInfoSize is NULL.\n", mImageIdName));
    Status = EFI_INVALID_PARAMETER;
    goto cleanup;
  }

  //
  // Check the buffer size
  // NOTE: Check this first so caller can get the necessary memory size it must allocate.
  //
  if (*ImageInfoSize < (sizeof (EFI_FIRMWARE_IMAGE_DESCRIPTOR))) {
    *ImageInfoSize = sizeof (EFI_FIRMWARE_IMAGE_DESCRIPTOR);
    DEBUG ((DEBUG_VERBOSE, "FmpDxe(%s): GetImageInfo() - ImageInfoSize is to small.\n", mImageIdName));
    Status = EFI_BUFFER_TOO_SMALL;
    goto cleanup;
  }

  //
  // Confirm that buffer isn't null
  //
  if ( (ImageInfo == NULL) || (DescriptorVersion == NULL) || (DescriptorCount == NULL) || (DescriptorSize == NULL)
       || (PackageVersion == NULL)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): GetImageInfo() - Pointer Parameter is NULL.\n", mImageIdName));
    Status = EFI_INVALID_PARAMETER;
    goto cleanup;
  }

  //
  // Set the size to whatever we need
  //
  *ImageInfoSize = sizeof (EFI_FIRMWARE_IMAGE_DESCRIPTOR);

  //
  // Make sure the descriptor has already been loaded or refreshed
  //
  PopulateDescriptor (Private);

  //
  // Copy the image descriptor
  //
  CopyMem (ImageInfo, &Private->Descriptor, sizeof (EFI_FIRMWARE_IMAGE_DESCRIPTOR));

  *DescriptorVersion = EFI_FIRMWARE_IMAGE_DESCRIPTOR_VERSION;
  *DescriptorCount = 1;
  *DescriptorSize = sizeof (EFI_FIRMWARE_IMAGE_DESCRIPTOR);
  //
  // means unsupported
  //
  *PackageVersion = 0xFFFFFFFF;

  //
  // Do not update PackageVersionName since it is not supported in this instance.
  //

cleanup:

  return Status;
}

/**
  Retrieves a copy of the current firmware image of the device.

  This function allows a copy of the current firmware image to be created and saved.
  The saved copy could later been used, for example, in firmware image recovery or rollback.

  @param[in]      This           A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.
  @param[in]      ImageIndex     A unique number identifying the firmware image(s) within the device.
                                 The number is between 1 and DescriptorCount.
  @param[in, out] Image          Points to the buffer where the current image is copied to.
  @param[in, out] ImageSize      On entry, points to the size of the buffer pointed to by Image, in bytes.
                                 On return, points to the length of the image, in bytes.

  @retval EFI_SUCCESS            The device was successfully updated with the new image.
  @retval EFI_BUFFER_TOO_SMALL   The buffer specified by ImageSize is too small to hold the
                                 image. The current buffer size needed to hold the image is returned
                                 in ImageSize.
  @retval EFI_INVALID_PARAMETER  The Image was NULL.
  @retval EFI_NOT_FOUND          The current image is not copied to the buffer.
  @retval EFI_UNSUPPORTED        The operation is not supported.
  @retval EFI_SECURITY_VIOLATION The operation could not be performed due to an authentication failure.

**/
EFI_STATUS
EFIAPI
GetTheImage (
  IN     EFI_FIRMWARE_MANAGEMENT_PROTOCOL  *This,
  IN     UINT8                             ImageIndex,
  IN OUT VOID                              *Image,
  IN OUT UINTN                             *ImageSize
  )
{
  EFI_STATUS                        Status;
  FIRMWARE_MANAGEMENT_PRIVATE_DATA  *Private;
  UINTN                             Size;
  UINT8                             *ImageBuffer;
  UINTN                             ImageBufferSize;
  UINT32                            DepexSize;

  if (!FeaturePcdGet (PcdFmpDeviceStorageAccessEnable)) {
    return EFI_UNSUPPORTED;
  }

  Status          = EFI_SUCCESS;
  ImageBuffer     = NULL;
  DepexSize       = 0;

  //
  // Retrieve the private context structure
  //
  Private = FIRMWARE_MANAGEMENT_PRIVATE_DATA_FROM_THIS (This);
  FmpDeviceSetContext (Private->Handle, &Private->FmpDeviceContext);

  //
  // Check to make sure index is 1 (only 1 image for this device)
  //
  if (ImageIndex != 1) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): GetImage() - Image Index Invalid.\n", mImageIdName));
    Status = EFI_INVALID_PARAMETER;
    goto cleanup;
  }

  if (ImageSize == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): GetImage() - ImageSize Pointer Parameter is NULL.\n", mImageIdName));
    Status = EFI_INVALID_PARAMETER;
    goto cleanup;
  }

  //
  // Check the buffer size
  //
  Status = FmpDeviceGetSize (&Size);
  if (EFI_ERROR (Status)) {
    Size = 0;
  }

  //
  // The parameter "Image" of FmpDeviceGetImage() is extended to contain the dependency.
  // Get the Fmp Payload from the Image.
  //
  ImageBufferSize = Size;
  ImageBuffer = AllocatePool (ImageBufferSize);
  if (ImageBuffer == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): GetImage() - AllocatePool fails.\n", mImageIdName));
    Status = EFI_NOT_FOUND;
    goto cleanup;
  }
  Status = FmpDeviceGetImage (ImageBuffer, &ImageBufferSize);
  if (Status == EFI_BUFFER_TOO_SMALL) {
    FreePool (ImageBuffer);
    ImageBuffer = AllocatePool (ImageBufferSize);
    if (ImageBuffer == NULL) {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): GetImage() - AllocatePool fails.\n", mImageIdName));
      Status = EFI_NOT_FOUND;
      goto cleanup;
    }
    Status = FmpDeviceGetImage (ImageBuffer, &ImageBufferSize);
  }
  if (EFI_ERROR (Status)) {
    goto cleanup;
  }

  //
  // Check the attribute IMAGE_ATTRIBUTE_DEPENDENCY
  //
  if (Private->Descriptor.AttributesSetting & IMAGE_ATTRIBUTE_DEPENDENCY) {
    //
    // Validate the dependency to get its size.
    //
    ValidateImageDepex ((EFI_FIRMWARE_IMAGE_DEP *) ImageBuffer, ImageBufferSize, &DepexSize);
  }

  if (*ImageSize < ImageBufferSize - DepexSize) {
    *ImageSize = ImageBufferSize - DepexSize;
    DEBUG ((DEBUG_VERBOSE, "FmpDxe(%s): GetImage() - ImageSize is to small.\n", mImageIdName));
    Status = EFI_BUFFER_TOO_SMALL;
    goto cleanup;
  }

  if (Image == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): GetImage() - Image Pointer Parameter is NULL.\n", mImageIdName));
    Status = EFI_INVALID_PARAMETER;
    goto cleanup;
  }

  //
  // Image is after the dependency expression.
  //
  *ImageSize = ImageBufferSize - DepexSize;
  CopyMem (Image, ImageBuffer + DepexSize, *ImageSize);
  Status = EFI_SUCCESS;

cleanup:
  if (ImageBuffer != NULL) {
    FreePool (ImageBuffer);
  }

  return Status;
}

/**
  Helper function to safely retrieve the FMP header from
  within an EFI_FIRMWARE_IMAGE_AUTHENTICATION structure.

  @param[in]   Image        Pointer to the image.
  @param[in]   ImageSize    Size of the image.
  @param[out]  PayloadSize

  @retval  !NULL  Valid pointer to the header.
  @retval  NULL   Structure is bad and pointer cannot be found.

**/
VOID *
GetFmpHeader (
  IN  CONST EFI_FIRMWARE_IMAGE_AUTHENTICATION  *Image,
  IN  CONST UINTN                              ImageSize,
  OUT UINTN                                    *PayloadSize
  )
{
  //
  // Check to make sure that operation can be safely performed.
  //
  if (((UINTN)Image + sizeof (Image->MonotonicCount) + Image->AuthInfo.Hdr.dwLength) < (UINTN)Image || \
      ((UINTN)Image + sizeof (Image->MonotonicCount) + Image->AuthInfo.Hdr.dwLength) >= (UINTN)Image + ImageSize) {
    //
    // Pointer overflow. Invalid image.
    //
    return NULL;
  }

  *PayloadSize = ImageSize - (sizeof (Image->MonotonicCount) + Image->AuthInfo.Hdr.dwLength);
  return (VOID *)((UINT8 *)Image + sizeof (Image->MonotonicCount) + Image->AuthInfo.Hdr.dwLength);
}

/**
  Helper function to safely calculate the size of all headers
  within an EFI_FIRMWARE_IMAGE_AUTHENTICATION structure.

  @param[in]  Image                 Pointer to the image.
  @param[in]  AdditionalHeaderSize  Size of any headers that cannot be calculated by this function.

  @retval  UINT32>0  Valid size of all the headers.
  @retval  0         Structure is bad and size cannot be found.

**/
UINT32
GetAllHeaderSize (
  IN CONST EFI_FIRMWARE_IMAGE_AUTHENTICATION  *Image,
  IN UINT32                                   AdditionalHeaderSize
  )
{
  UINT32  CalculatedSize;

  CalculatedSize = sizeof (Image->MonotonicCount) +
                   AdditionalHeaderSize +
                   Image->AuthInfo.Hdr.dwLength;

  //
  // Check to make sure that operation can be safely performed.
  //
  if (CalculatedSize < sizeof (Image->MonotonicCount) ||
      CalculatedSize < AdditionalHeaderSize           ||
      CalculatedSize < Image->AuthInfo.Hdr.dwLength      ) {
    //
    // Integer overflow. Invalid image.
    //
    return 0;
  }

  return CalculatedSize;
}

/**
  Checks if the firmware image is valid for the device.

// MU_CHANGE Starts
  This internal function returns the LastAttemptStatus value from FmpDeviceCheckImage (). This enables
  a FmpDeviceCheckImage () implementation to report more granular last attempt status codes that can be exposed
  to the operating system. The UEFI specification defined CheckTheImage () function does not include this
  parameter.
// MU_CHANGE Ends

  @param[in]  This               A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.
  @param[in]  ImageIndex         A unique number identifying the firmware image(s) within the device.
                                 The number is between 1 and DescriptorCount.
  @param[in]  Image              Points to the new image.
  @param[in]  ImageSize          Size of the new image in bytes.
  @param[out] ImageUpdatable     Indicates if the new image is valid for update. It also provides,
                                 if available, additional information if the image is invalid.
// MU_CHANGE Starts
  @param[out] LastAttemptStatus  A pointer to a UINT32 that holds the last attempt
                                 status to report back to the ESRT table in case
                                 of error.

                                 This function will return error codes that occur within this function
                                 implementation within a driver range of last attempt error codes from
                                 LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL_VENDOR_RANGE_MIN
                                 to LAST_ATTEMPT_STATUS_DRIVER_ERROR_MAX_ERROR_CODE.

                                 This function will additionally return error codes that are returned
                                 from a platform-specific CheckImage () implementation in the range of
                                 LAST_ATTEMPT_STATUS_LIBRARY_ERROR_MIN_ERROR_CODE to
                                 LAST_ATTEMPT_STATUS_LIBRARY_ERROR_MAX_ERROR_CODE.
// MU_CHANGE Ends

  @retval EFI_SUCCESS            The image was successfully checked.
  @retval EFI_ABORTED            The operation is aborted.
  @retval EFI_INVALID_PARAMETER  The Image was NULL.
  @retval EFI_UNSUPPORTED        The operation is not supported.
  @retval EFI_SECURITY_VIOLATION The operation could not be performed due to an authentication failure.

**/
EFI_STATUS
EFIAPI
// MU_CHANGE Starts
CheckTheImageInternal (
// MU_CHANGE Ends
  IN  EFI_FIRMWARE_MANAGEMENT_PROTOCOL  *This,
  IN  UINT8                             ImageIndex,
  IN  CONST VOID                        *Image,
  IN  UINTN                             ImageSize,
// MU_CHANGE Starts
  OUT UINT32                            *ImageUpdatable,
  OUT UINT32                            *LastAttemptStatus
// MU_CHANGE Ends
  )
{
  EFI_STATUS                        Status;
  FIRMWARE_MANAGEMENT_PRIVATE_DATA  *Private;
  UINTN                             RawSize;
  VOID                              *FmpPayloadHeader;
  UINTN                             FmpPayloadSize;
  UINT32                            Version;
  UINT32                            FmpHeaderSize;
  UINTN                             AllHeaderSize;
  UINT32                            Index;
  VOID                              *PublicKeyData;
  UINTN                             PublicKeyDataLength;
  UINT8                             *PublicKeyDataXdr;
  UINT8                             *PublicKeyDataXdrEnd;
  EFI_FIRMWARE_IMAGE_DEP            *Dependencies;
  UINT32                            DependenciesSize;
  BOOLEAN                           IsDepexValid;
  BOOLEAN                           IsDepexSatisfied;

  Status           = EFI_SUCCESS;
  RawSize          = 0;
  FmpPayloadHeader = NULL;
  FmpPayloadSize   = 0;
  Version          = 0;
  FmpHeaderSize    = 0;
  AllHeaderSize    = 0;
  Dependencies     = NULL;
  DependenciesSize = 0;

  if (!FeaturePcdGet (PcdFmpDeviceStorageAccessEnable)) {
    return EFI_UNSUPPORTED;
  }

  //
  // Retrieve the private context structure
  //
  Private = FIRMWARE_MANAGEMENT_PRIVATE_DATA_FROM_THIS (This);
  FmpDeviceSetContext (Private->Handle, &Private->FmpDeviceContext);

  //
  // Make sure the descriptor has already been loaded or refreshed
  //
  PopulateDescriptor (Private);

  if (ImageUpdatable == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckImage() - ImageUpdatable Pointer Parameter is NULL.\n", mImageIdName));
    Status = EFI_INVALID_PARAMETER;
// MU_CHANGE Starts
    *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_IMAGE_NOT_UPDATABLE;
// MU_CHANGE Ends
    goto cleanup;
  }

  //
  //Set to valid and then if any tests fail it will update this flag.
  //
  *ImageUpdatable = IMAGE_UPDATABLE_VALID;

  if (Image == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckImage() - Image Pointer Parameter is NULL.\n", mImageIdName));
    //
    // not sure if this is needed
    //
    *ImageUpdatable = IMAGE_UPDATABLE_INVALID;
// MU_CHANGE Starts
    *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_IMAGE_NOT_PROVIDED;
// MU_CHANGE Ends
    return EFI_INVALID_PARAMETER;
  }

  PublicKeyDataXdr    = PcdGetPtr (PcdFmpDevicePkcs7CertBufferXdr);
  PublicKeyDataXdrEnd = PublicKeyDataXdr + PcdGetSize (PcdFmpDevicePkcs7CertBufferXdr);

  if (PublicKeyDataXdr == NULL || (PublicKeyDataXdr == PublicKeyDataXdrEnd)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): Invalid certificate, skipping it.\n", mImageIdName));
    Status = EFI_ABORTED;
// MU_CHANGE Starts
    *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_INVALID_CERTIFICATE;
// MU_CHANGE Ends
  } else {
    //
    // Try each key from PcdFmpDevicePkcs7CertBufferXdr
    //
    for (Index = 1; PublicKeyDataXdr < PublicKeyDataXdrEnd; Index++) {
      Index++;
      DEBUG (
        (DEBUG_INFO,
        "FmpDxe(%s): Certificate #%d [%p..%p].\n",
        mImageIdName,
        Index,
        PublicKeyDataXdr,
        PublicKeyDataXdrEnd
        )
        );

      if ((PublicKeyDataXdr + sizeof (UINT32)) > PublicKeyDataXdrEnd) {
        //
        // Key data extends beyond end of PCD
        //
        DEBUG ((DEBUG_ERROR, "FmpDxe(%s): Certificate size extends beyond end of PCD, skipping it.\n", mImageIdName));
        Status = EFI_ABORTED;
// MU_CHANGE Starts
        *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_INVALID_KEY_LENGTH_VALUE;
// MU_CHANGE Ends
        break;
      }
      //
      // Read key length stored in big-endian format
      //
      PublicKeyDataLength = SwapBytes32 (*(UINT32 *)(PublicKeyDataXdr));
      //
      // Point to the start of the key data
      //
      PublicKeyDataXdr += sizeof (UINT32);
      if (PublicKeyDataXdr + PublicKeyDataLength > PublicKeyDataXdrEnd) {
        //
        // Key data extends beyond end of PCD
        //
        DEBUG ((DEBUG_ERROR, "FmpDxe(%s): Certificate extends beyond end of PCD, skipping it.\n", mImageIdName));
        Status = EFI_ABORTED;
// MU_CHANGE Starts
        *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_INVALID_KEY_LENGTH;
// MU_CHANGE Ends
        break;
      }
      PublicKeyData = PublicKeyDataXdr;
      Status = AuthenticateFmpImage (
                 (EFI_FIRMWARE_IMAGE_AUTHENTICATION *)Image,
                 ImageSize,
                 PublicKeyData,
                 PublicKeyDataLength
                 );
      if (!EFI_ERROR (Status)) {
        break;
      }
      PublicKeyDataXdr += PublicKeyDataLength;
      PublicKeyDataXdr = (UINT8 *)ALIGN_POINTER (PublicKeyDataXdr, sizeof (UINT32));
    }
  }

  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckTheImage() - Authentication Failed %r.\n", mImageIdName, Status));
    goto cleanup;
  }

  //
  // Check to make sure index is 1
  //
  if (ImageIndex != 1) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckImage() - Image Index Invalid.\n", mImageIdName));
    *ImageUpdatable = IMAGE_UPDATABLE_INVALID_TYPE;
    Status = EFI_SUCCESS;
// MU_CHANGE Starts
    *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_INVALID_IMAGE_INDEX;
// MU_CHANGE Ends
    goto cleanup;
  }


  //
  // Check the FmpPayloadHeader
  //
  FmpPayloadHeader = GetFmpHeader ( (EFI_FIRMWARE_IMAGE_AUTHENTICATION *)Image, ImageSize, &FmpPayloadSize );
  if (FmpPayloadHeader == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckTheImage() - GetFmpHeader failed.\n", mImageIdName));
    Status = EFI_ABORTED;
// MU_CHANGE Starts
    *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_GETFMPHEADER;
// MU_CHANGE Ends
    goto cleanup;
  }
  Status = GetFmpPayloadHeaderVersion (FmpPayloadHeader, FmpPayloadSize, &Version);
  if (EFI_ERROR (Status)) {
    //
    // Check if there is dependency expression
    //
    IsDepexValid = ValidateImageDepex ((EFI_FIRMWARE_IMAGE_DEP*) FmpPayloadHeader, FmpPayloadSize, &DependenciesSize);
    if (IsDepexValid && (DependenciesSize < FmpPayloadSize)) {
      //
      // Fmp payload is after dependency expression
      //
      Dependencies = (EFI_FIRMWARE_IMAGE_DEP*) FmpPayloadHeader;
      FmpPayloadHeader = (UINT8 *) Dependencies + DependenciesSize;
      FmpPayloadSize = FmpPayloadSize - DependenciesSize;
      Status = GetFmpPayloadHeaderVersion (FmpPayloadHeader, FmpPayloadSize, &Version);
      if (EFI_ERROR (Status)) {
        DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckTheImage() - GetFmpPayloadHeaderVersion failed %r.\n", mImageIdName, Status));
        *ImageUpdatable = IMAGE_UPDATABLE_INVALID;
        Status = EFI_SUCCESS;
// MU_CHANGE Starts
        *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_GETFMPHEADER_VERSION;
// MU_CHANGE Ends
        goto cleanup;
      }
    } else {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckTheImage() - Dependency is invalid.\n", mImageIdName));
      mDependenciesCheckStatus = DEPENDENCIES_INVALID;
      *ImageUpdatable = IMAGE_UPDATABLE_INVALID;
      Status = EFI_SUCCESS;
// MU_CHANGE Starts
      *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_DEPENDENCY_INVALID;
// MU_CHANGE Ends
      goto cleanup;
    }
  } else {
    DEBUG ((DEBUG_WARN, "FmpDxe(%s): CheckTheImage() - No dependency associated in image.\n", mImageIdName));
  }

  //
  // Check the lowest supported version
  //
  if (Version < Private->Descriptor.LowestSupportedImageVersion) {
    DEBUG (
      (DEBUG_ERROR,
      "FmpDxe(%s): CheckTheImage() - Version Lower than lowest supported version. 0x%08X < 0x%08X\n",
      mImageIdName, Version, Private->Descriptor.LowestSupportedImageVersion)
      );
    *ImageUpdatable = IMAGE_UPDATABLE_INVALID_OLD;
    Status = EFI_SUCCESS;
// MU_CHANGE Starts
    *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_VERSION_TOO_LOW;
// MU_CHANGE Ends
    goto cleanup;
  }

  //
  // Evaluate dependency expression
  //
  Status = EvaluateImageDependencies (Private->Descriptor.ImageTypeId, Version, Dependencies, DependenciesSize, &IsDepexSatisfied);
  if (!IsDepexSatisfied || EFI_ERROR (Status)) {
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckTheImage() - Dependency check failed %r.\n", mImageIdName, Status));
    } else {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckTheImage() - Dependency is not satisfied.\n", mImageIdName));
    }
    mDependenciesCheckStatus = DEPENDENCIES_UNSATISFIED;
    *ImageUpdatable = IMAGE_UPDATABLE_INVALID;
    Status = EFI_SUCCESS;
// MU_CHANGE Starts
    *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_DEPENDENCY_UNSATISFIED;
// MU_CHANGE Ends
    goto cleanup;
  }

  //
  // Get the FmpHeaderSize so we can determine the real payload size
  //
  Status = GetFmpPayloadHeaderSize (FmpPayloadHeader, FmpPayloadSize, &FmpHeaderSize);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe: CheckTheImage() - GetFmpPayloadHeaderSize failed %r.\n", Status));
    *ImageUpdatable = IMAGE_UPDATABLE_INVALID;
    Status = EFI_SUCCESS;
// MU_CHANGE Starts
    *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_GETFMPHEADERSIZE;
// MU_CHANGE Ends
    goto cleanup;
  }

  //
  // Call FmpDevice Lib Check Image on the
  // Raw payload.  So all headers need stripped off
  //
  AllHeaderSize = GetAllHeaderSize ( (EFI_FIRMWARE_IMAGE_AUTHENTICATION *)Image, FmpHeaderSize + DependenciesSize);
  if (AllHeaderSize == 0) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckTheImage() - GetAllHeaderSize failed.\n", mImageIdName));
    Status = EFI_ABORTED;
// MU_CHANGE Starts
    *LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_GETALLHEADERSIZE;
// MU_CHANGE Ends
    goto cleanup;
  }
  RawSize = ImageSize - AllHeaderSize;

// MU_CHANGE Starts
  //
  // Set LastAttemptStatus to successful prior to getting any potential error codes from FmpDeviceLib
  //
  *LastAttemptStatus = LAST_ATTEMPT_STATUS_SUCCESS;
// MU_CHANGE Ends

  //
  // FmpDeviceLib CheckImage function to do any specific checks
  //
  Status = FmpDeviceCheckImage ((((UINT8 *)Image) + AllHeaderSize), RawSize, ImageUpdatable, LastAttemptStatus);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): CheckTheImage() - FmpDeviceLib CheckImage failed. Status = %r\n", mImageIdName, Status));
  }

cleanup:
  return Status;
}

// MU_CHANGE Starts
/**
  Checks if the firmware image is valid for the device.

  This function allows firmware update application to validate the firmware image without
  invoking the SetImage() first.

  @param[in]  This               A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.
  @param[in]  ImageIndex         A unique number identifying the firmware image(s) within the device.
                                 The number is between 1 and DescriptorCount.
  @param[in]  Image              Points to the new image.
  @param[in]  ImageSize          Size of the new image in bytes.
  @param[out] ImageUpdatable     Indicates if the new image is valid for update. It also provides,
                                 if available, additional information if the image is invalid.

  @retval EFI_SUCCESS            The image was successfully checked.
  @retval EFI_ABORTED            The operation is aborted.
  @retval EFI_INVALID_PARAMETER  The Image was NULL.
  @retval EFI_UNSUPPORTED        The operation is not supported.
  @retval EFI_SECURITY_VIOLATION The operation could not be performed due to an authentication failure.

**/
EFI_STATUS
EFIAPI
CheckTheImage (
  IN  EFI_FIRMWARE_MANAGEMENT_PROTOCOL  *This,
  IN  UINT8                             ImageIndex,
  IN  CONST VOID                        *Image,
  IN  UINTN                             ImageSize,
  OUT UINT32                            *ImageUpdatable
  )
{
  UINT32    LastAttemptStatus;

  return CheckTheImageInternal (This, ImageIndex, Image, ImageSize, ImageUpdatable, &LastAttemptStatus);
}
// MU_CHANGE Ends

/**
  Updates the firmware image of the device.

  This function updates the hardware with the new firmware image.
  This function returns EFI_UNSUPPORTED if the firmware image is not updatable.
  If the firmware image is updatable, the function should perform the following minimal validations
  before proceeding to do the firmware image update.
  - Validate the image authentication if image has attribute
    IMAGE_ATTRIBUTE_AUTHENTICATION_REQUIRED. The function returns
    EFI_SECURITY_VIOLATION if the validation fails.
  - Validate the image is a supported image for this device. The function returns EFI_ABORTED if
    the image is unsupported. The function can optionally provide more detailed information on
    why the image is not a supported image.
  - Validate the data from VendorCode if not null. Image validation must be performed before
    VendorCode data validation. VendorCode data is ignored or considered invalid if image
    validation failed. The function returns EFI_ABORTED if the data is invalid.

  VendorCode enables vendor to implement vendor-specific firmware image update policy. Null if
  the caller did not specify the policy or use the default policy. As an example, vendor can implement
  a policy to allow an option to force a firmware image update when the abort reason is due to the new
  firmware image version is older than the current firmware image version or bad image checksum.
  Sensitive operations such as those wiping the entire firmware image and render the device to be
  non-functional should be encoded in the image itself rather than passed with the VendorCode.
  AbortReason enables vendor to have the option to provide a more detailed description of the abort
  reason to the caller.

  @param[in]  This               A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.
  @param[in]  ImageIndex         A unique number identifying the firmware image(s) within the device.
                                 The number is between 1 and DescriptorCount.
  @param[in]  Image              Points to the new image.
  @param[in]  ImageSize          Size of the new image in bytes.
  @param[in]  VendorCode         This enables vendor to implement vendor-specific firmware image update policy.
                                 Null indicates the caller did not specify the policy or use the default policy.
  @param[in]  Progress           A function used by the driver to report the progress of the firmware update.
  @param[out] AbortReason        A pointer to a pointer to a null-terminated string providing more
                                 details for the aborted operation. The buffer is allocated by this function
                                 with AllocatePool(), and it is the caller's responsibility to free it with a
                                 call to FreePool().

  @retval EFI_SUCCESS            The device was successfully updated with the new image.
  @retval EFI_ABORTED            The operation is aborted.
  @retval EFI_INVALID_PARAMETER  The Image was NULL.
  @retval EFI_UNSUPPORTED        The operation is not supported.
  @retval EFI_SECURITY_VIOLATION The operation could not be performed due to an authentication failure.

**/
EFI_STATUS
EFIAPI
SetTheImage (
  IN  EFI_FIRMWARE_MANAGEMENT_PROTOCOL               *This,
  IN  UINT8                                          ImageIndex,
  IN  CONST VOID                                     *Image,
  IN  UINTN                                          ImageSize,
  IN  CONST VOID                                     *VendorCode,
  IN  EFI_FIRMWARE_MANAGEMENT_UPDATE_IMAGE_PROGRESS  Progress,
  OUT CHAR16                                         **AbortReason
  )
{
  EFI_STATUS                        Status;
  FIRMWARE_MANAGEMENT_PRIVATE_DATA  *Private;
  UINT32                            Updateable;
  BOOLEAN                           BooleanValue;
  UINT32                            FmpHeaderSize;
  VOID                              *FmpHeader;
  UINTN                             FmpPayloadSize;
  UINT32                            AllHeaderSize;
  UINT32                            IncomingFwVersion;
  UINT32                            LastAttemptStatus;
  UINT32                            Version;
  UINT32                            LowestSupportedVersion;
  EFI_FIRMWARE_IMAGE_DEP            *Dependencies;
  UINT32                            DependenciesSize;
  BOOLEAN                           IsDepexValid;
  UINT8                             *ImageBuffer;
  UINTN                             ImageBufferSize;

  Status             = EFI_SUCCESS;
  Updateable         = 0;
  BooleanValue       = FALSE;
  FmpHeaderSize      = 0;
  FmpHeader          = NULL;
  FmpPayloadSize     = 0;
  AllHeaderSize      = 0;
  IncomingFwVersion  = 0;
  LastAttemptStatus  = LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL;
  Dependencies       = NULL;
  DependenciesSize   = 0;
  ImageBuffer        = NULL;
  ImageBufferSize    = 0;

  if (!FeaturePcdGet (PcdFmpDeviceStorageAccessEnable)) {
    return EFI_UNSUPPORTED;
  }

  //
  // Retrieve the private context structure
  //
  Private = FIRMWARE_MANAGEMENT_PRIVATE_DATA_FROM_THIS (This);
  FmpDeviceSetContext (Private->Handle, &Private->FmpDeviceContext);

  //
  // Make sure the descriptor has already been loaded or refreshed
  //
  PopulateDescriptor (Private);

  //
  // Set to 0 to clear any previous results.
  //
  SetLastAttemptVersionInVariable (Private, IncomingFwVersion);

  //
  // if we have locked the device, then skip the set operation.
  // it should be blocked by hardware too but we can catch here even faster
  //
  if (Private->FmpDeviceLocked) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - Device is already locked.  Can't update.\n", mImageIdName));
    Status = EFI_UNSUPPORTED;
    goto cleanup;
  }

  //
  // Set check status to satisfied before CheckTheImage()
  //
  mDependenciesCheckStatus = DEPENDENCIES_SATISFIED;

  //
  // Call check image to verify the image
  //
  Status = CheckTheImageInternal (This, ImageIndex, Image, ImageSize, &Updateable, &LastAttemptStatus);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - Check The Image failed with %r.\n", mImageIdName, Status));
    goto cleanup;
  }

  //
  // No functional error in CheckTheImage.  Attempt to get the Version to
  // support better error reporting.
  //
  FmpHeader = GetFmpHeader ( (EFI_FIRMWARE_IMAGE_AUTHENTICATION *)Image, ImageSize, &FmpPayloadSize );
  if (FmpHeader == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - GetFmpHeader failed.\n", mImageIdName));
    // MU_CHANGE Starts
    LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_GETFMPHEADER;
    // MU_CHANGE Ends
    Status = EFI_ABORTED;
    goto cleanup;
  }
  Status = GetFmpPayloadHeaderVersion (FmpHeader, FmpPayloadSize, &IncomingFwVersion);
  if (EFI_ERROR (Status)) {
    //
    // Check if there is dependency expression
    //
    IsDepexValid = ValidateImageDepex ((EFI_FIRMWARE_IMAGE_DEP*) FmpHeader, FmpPayloadSize, &DependenciesSize);
    if (IsDepexValid && (DependenciesSize < FmpPayloadSize)) {
      //
      // Fmp payload is after dependency expression
      //
      Dependencies = (EFI_FIRMWARE_IMAGE_DEP*) FmpHeader;
      FmpHeader = (UINT8 *) FmpHeader + DependenciesSize;
      FmpPayloadSize = FmpPayloadSize - DependenciesSize;
      Status = GetFmpPayloadHeaderVersion (FmpHeader, FmpPayloadSize, &IncomingFwVersion);
    }
  }
  if (!EFI_ERROR (Status)) {
    //
    // Set to actual value
    //
    SetLastAttemptVersionInVariable (Private, IncomingFwVersion);
  }


  if (Updateable != IMAGE_UPDATABLE_VALID) {
    DEBUG (
      (DEBUG_ERROR,
      "FmpDxe(%s): SetTheImage() - Check The Image returned that the Image was not valid for update.  Updatable value = 0x%X.\n",
      mImageIdName, Updateable)
      );
    if (mDependenciesCheckStatus == DEPENDENCIES_UNSATISFIED) {
      LastAttemptStatus = LAST_ATTEMPT_STATUS_ERROR_UNSATISFIED_DEPENDENCIES;
    } else if (mDependenciesCheckStatus == DEPENDENCIES_INVALID) {
      LastAttemptStatus = LAST_ATTEMPT_STATUS_ERROR_INVALID_FORMAT;
    }
    Status = EFI_ABORTED;
    goto cleanup;
  }

  if (Progress == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - Invalid progress callback\n", mImageIdName));
    // MU_CHANGE Starts
    LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_PROGRESS_CALLBACK_ERROR;
    // MU_CHANGE Ends
    Status = EFI_INVALID_PARAMETER;
    goto cleanup;
  }

  mProgressFunc = Progress;

  //
  // Checking the image is at least 1%
  //
  Status = Progress (1);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - Progress Callback failed with Status %r.\n", mImageIdName, Status));
  }

  //
  //Check System Power
  //
  Status = CheckSystemPower (&BooleanValue);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - CheckSystemPower - API call failed %r.\n", mImageIdName, Status));
    // MU_CHANGE Starts
    LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_CHECKPWR_API;
    // MU_CHANGE Ends
    goto cleanup;
  }
  if (!BooleanValue) {
    Status = EFI_ABORTED;
    DEBUG (
      (DEBUG_ERROR,
      "FmpDxe(%s): SetTheImage() - CheckSystemPower - returned False.  Update not allowed due to System Power.\n", mImageIdName)
      );
    LastAttemptStatus = LAST_ATTEMPT_STATUS_ERROR_PWR_EVT_BATT;
    goto cleanup;
  }

  Progress (2);

  //
  //Check System Thermal
  //
  Status = CheckSystemThermal (&BooleanValue);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - CheckSystemThermal - API call failed %r.\n", mImageIdName, Status));
    // MU_CHANGE Starts
    LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_CHECKSYSTHERMAL_API;
    // MU_CHANGE Ends
    goto cleanup;
  }
  if (!BooleanValue) {
    Status = EFI_ABORTED;
    // MU_CHANGE Starts
    LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_THERMAL;
    // MU_CHANGE Ends
    DEBUG (
      (DEBUG_ERROR,
      "FmpDxe(%s): SetTheImage() - CheckSystemThermal - returned False.  Update not allowed due to System Thermal.\n", mImageIdName)
      );
    goto cleanup;
  }

  Progress (3);

  //
  //Check System Environment
  //
  Status = CheckSystemEnvironment (&BooleanValue);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - CheckSystemEnvironment - API call failed %r.\n", mImageIdName, Status));
    // MU_CHANGE Starts
    LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_CHECKSYSENV_API;
    // MU_CHANGE Ends
    goto cleanup;
  }
  if (!BooleanValue) {
    Status = EFI_ABORTED;
    // MU_CHANGE Starts
    LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_SYSTEM_ENV;
    // MU_CHANGE Ends
    DEBUG (
      (DEBUG_ERROR,
      "FmpDxe(%s): SetTheImage() - CheckSystemEnvironment - returned False.  Update not allowed due to System Environment.\n", mImageIdName)
      );
    goto cleanup;
  }

  Progress (4);

  //
  // Save LastAttemptStatus as error so that if SetImage never returns the error
  // state is recorded.
  //
  SetLastAttemptStatusInVariable (Private, LastAttemptStatus);

  //
  // Strip off all the headers so the device can process its firmware
  //
  Status = GetFmpPayloadHeaderSize (FmpHeader, FmpPayloadSize, &FmpHeaderSize);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - GetFmpPayloadHeaderSize failed %r.\n", mImageIdName, Status));
    // MU_CHANGE Starts
    LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_GETFMPHEADERSIZE;
    // MU_CHANGE Ends
    goto cleanup;
  }

  AllHeaderSize = GetAllHeaderSize ((EFI_FIRMWARE_IMAGE_AUTHENTICATION *)Image, FmpHeaderSize + DependenciesSize);
  if (AllHeaderSize == 0) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - GetAllHeaderSize failed.\n", mImageIdName));
    // MU_CHANGE Starts
    LastAttemptStatus = LAST_ATTEMPT_STATUS_DRIVER_ERROR_GETALLHEADERSIZE;
    // MU_CHANGE Ends
    Status = EFI_ABORTED;
    goto cleanup;
  }

  //
  // Check the attribute IMAGE_ATTRIBUTE_DEPENDENCY
  //
  if (Private->Descriptor.AttributesSetting & IMAGE_ATTRIBUTE_DEPENDENCY) {
    //
    // To support saving dependency, extend param "Image" of FmpDeviceSetImage() to
    // contain the dependency inside. FmpDeviceSetImage() is responsible for saving
    // the dependency which can be used for future dependency check.
    //
    ImageBufferSize = DependenciesSize + ImageSize - AllHeaderSize;
    ImageBuffer = AllocatePool (ImageBufferSize);
    if (ImageBuffer == NULL) {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - AllocatePool failed.\n", mImageIdName));
      Status = EFI_ABORTED;
      goto cleanup;
    }
    CopyMem (ImageBuffer, Dependencies->Dependencies, DependenciesSize);
    CopyMem (ImageBuffer + DependenciesSize, (UINT8 *)Image + AllHeaderSize, ImageBufferSize - DependenciesSize);
  } else {
    ImageBufferSize = ImageSize - AllHeaderSize;
    ImageBuffer = AllocateCopyPool(ImageBufferSize, (UINT8 *)Image + AllHeaderSize);
    if (ImageBuffer == NULL) {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() - AllocatePool failed.\n", mImageIdName));
      Status = EFI_ABORTED;
      goto cleanup;
    }
  }

  //
  // Indicate that control is handed off to FmpDeviceLib
  //
  Progress (5);

  //
  //Copy the requested image to the firmware using the FmpDeviceLib
  //
  Status = FmpDeviceSetImage (
             ImageBuffer,
             ImageBufferSize,
             VendorCode,
             FmpDxeProgress,
             IncomingFwVersion,
             // MU_CHANGE Starts
             AbortReason,
             &LastAttemptStatus
             // MU_CHANGE Ends
             );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): SetTheImage() SetImage from FmpDeviceLib failed. Status =  %r.\n", mImageIdName, Status));
    // MU_CHANGE Starts
    // Returned LastAttemptStatus should fall into designated LAST_ATTEMPT_STATUS_LIBRARY_ERROR range.
    if ((LastAttemptStatus < LAST_ATTEMPT_STATUS_LIBRARY_ERROR_MIN_ERROR_CODE) ||
        (LastAttemptStatus > LAST_ATTEMPT_STATUS_LIBRARY_ERROR_MAX_ERROR_CODE)) {
      ReportStatusCode ((EFI_ERROR_MINOR | EFI_ERROR_CODE), FIRMWARE_MANAGEMENT_ILLEGAL_STATE);
      LastAttemptStatus = LAST_ATTEMPT_STATUS_ERROR_UNSUCCESSFUL;
    }
    // MU_CHANGE Ends
    goto cleanup;
  }


  //
  // Finished the update without error
  // Indicate that control has been returned from FmpDeviceLib
  //
  Progress (99);

  //
  // Update the version stored in variable
  //
  if (!Private->RuntimeVersionSupported) {
    Version = DEFAULT_VERSION;
    GetFmpPayloadHeaderVersion (FmpHeader, FmpPayloadSize, &Version);
    SetVersionInVariable (Private, Version);
  }

  //
  // Update lowest supported variable
  //
  LowestSupportedVersion = DEFAULT_LOWESTSUPPORTEDVERSION;
  GetFmpPayloadHeaderLowestSupportedVersion (FmpHeader, FmpPayloadSize, &LowestSupportedVersion);
  SetLowestSupportedVersionInVariable (Private, LowestSupportedVersion);

  LastAttemptStatus = LAST_ATTEMPT_STATUS_SUCCESS;

cleanup:
  if (ImageBuffer != NULL) {
    FreePool (ImageBuffer);
  }

  mProgressFunc = NULL;
  // MU_CHANGE Starts
  DEBUG((DEBUG_INFO, "SetTheImage Cleanup LastAttemptStatus: %u.\n", LastAttemptStatus));
  // MU_CHANGE Ends
  SetLastAttemptStatusInVariable (Private, LastAttemptStatus);

  if (Progress != NULL) {
    //
    // Set progress to 100 after everything is done including recording Status.
    //
    Progress (100);
  }

  //
  // Need repopulate after SetImage is called to
  // update LastAttemptVersion and LastAttemptStatus.
  //
  Private->DescriptorPopulated = FALSE;

  return Status;
}

/**
  Returns information about the firmware package.

  This function returns package information.

  @param[in]  This                     A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.
  @param[out] PackageVersion           A version number that represents all the firmware images in the device.
                                       The format is vendor specific and new version must have a greater value
                                       than the old version. If PackageVersion is not supported, the value is
                                       0xFFFFFFFF. A value of 0xFFFFFFFE indicates that package version
                                       comparison is to be performed using PackageVersionName. A value of
                                       0xFFFFFFFD indicates that package version update is in progress.
  @param[out] PackageVersionName       A pointer to a pointer to a null-terminated string representing
                                       the package version name. The buffer is allocated by this function with
                                       AllocatePool(), and it is the caller's responsibility to free it with a
                                       call to FreePool().
  @param[out] PackageVersionNameMaxLen The maximum length of package version name if device supports update of
                                       package version name. A value of 0 indicates the device does not support
                                       update of package version name. Length is the number of Unicode characters,
                                       including the terminating null character.
  @param[out] AttributesSupported      Package attributes that are supported by this device. See 'Package Attribute
                                       Definitions' for possible returned values of this parameter. A value of 1
                                       indicates the attribute is supported and the current setting value is
                                       indicated in AttributesSetting. A value of 0 indicates the attribute is not
                                       supported and the current setting value in AttributesSetting is meaningless.
  @param[out] AttributesSetting        Package attributes. See 'Package Attribute Definitions' for possible returned
                                       values of this parameter

  @retval EFI_SUCCESS                  The package information was successfully returned.
  @retval EFI_UNSUPPORTED              The operation is not supported.

**/
EFI_STATUS
EFIAPI
GetPackageInfo (
  IN  EFI_FIRMWARE_MANAGEMENT_PROTOCOL  *This,
  OUT UINT32                            *PackageVersion,
  OUT CHAR16                            **PackageVersionName,
  OUT UINT32                            *PackageVersionNameMaxLen,
  OUT UINT64                            *AttributesSupported,
  OUT UINT64                            *AttributesSetting
  )
{
  return EFI_UNSUPPORTED;
}

/**
  Updates information about the firmware package.

  This function updates package information.
  This function returns EFI_UNSUPPORTED if the package information is not updatable.
  VendorCode enables vendor to implement vendor-specific package information update policy.
  Null if the caller did not specify this policy or use the default policy.

  @param[in]  This               A pointer to the EFI_FIRMWARE_MANAGEMENT_PROTOCOL instance.
  @param[in]  Image              Points to the authentication image.
                                 Null if authentication is not required.
  @param[in]  ImageSize          Size of the authentication image in bytes.
                                 0 if authentication is not required.
  @param[in]  VendorCode         This enables vendor to implement vendor-specific firmware
                                 image update policy.
                                 Null indicates the caller did not specify this policy or use
                                 the default policy.
  @param[in]  PackageVersion     The new package version.
  @param[in]  PackageVersionName A pointer to the new null-terminated Unicode string representing
                                 the package version name.
                                 The string length is equal to or less than the value returned in
                                 PackageVersionNameMaxLen.

  @retval EFI_SUCCESS            The device was successfully updated with the new package
                                 information.
  @retval EFI_INVALID_PARAMETER  The PackageVersionName length is longer than the value
                                 returned in PackageVersionNameMaxLen.
  @retval EFI_UNSUPPORTED        The operation is not supported.
  @retval EFI_SECURITY_VIOLATION The operation could not be performed due to an authentication failure.

**/
EFI_STATUS
EFIAPI
SetPackageInfo (
  IN EFI_FIRMWARE_MANAGEMENT_PROTOCOL  *This,
  IN CONST VOID                        *Image,
  IN UINTN                             ImageSize,
  IN CONST VOID                        *VendorCode,
  IN UINT32                            PackageVersion,
  IN CONST CHAR16                      *PackageVersionName
  )
{
  return EFI_UNSUPPORTED;
}

/**
  Event notification function that is invoked when the event GUID specified by
  PcdFmpDeviceLockEventGuid is signaled.

  @param[in] Event    Event whose notification function is being invoked.
  @param[in] Context  The pointer to the notification function's context,
                      which is implementation-dependent.
**/
VOID
EFIAPI
FmpDxeLockEventNotify (
  IN EFI_EVENT  Event,
  IN VOID       *Context
  )
{
  EFI_STATUS                        Status;
  FIRMWARE_MANAGEMENT_PRIVATE_DATA  *Private;

  Private = (FIRMWARE_MANAGEMENT_PRIVATE_DATA *)Context;

  if (!Private->FmpDeviceLocked) {
    //
    // Lock the firmware device
    //
    FmpDeviceSetContext (Private->Handle, &Private->FmpDeviceContext);
    Status = FmpDeviceLock();
    if (EFI_ERROR (Status)) {
      if (Status != EFI_UNSUPPORTED) {
        DEBUG ((DEBUG_ERROR, "FmpDxe(%s): FmpDeviceLock() returned error.  Status = %r\n", mImageIdName, Status));
      } else {
        DEBUG ((DEBUG_WARN, "FmpDxe(%s): FmpDeviceLock() returned error.  Status = %r\n", mImageIdName, Status));
      }
    }
    Private->FmpDeviceLocked = TRUE;
  }
}

/**
  Function to install FMP instance.

  @param[in]  Handle  The device handle to install a FMP instance on.

  @retval  EFI_SUCCESS            FMP Installed
  @retval  EFI_INVALID_PARAMETER  Handle was invalid
  @retval  other                  Error installing FMP

**/
EFI_STATUS
EFIAPI
InstallFmpInstance (
  IN EFI_HANDLE  Handle
  )
{
  EFI_STATUS                        Status;
  EFI_FIRMWARE_MANAGEMENT_PROTOCOL  *Fmp;
  FIRMWARE_MANAGEMENT_PRIVATE_DATA  *Private;

  //
  // Only allow a single FMP Protocol instance to be installed
  //
  Status = gBS->OpenProtocol (
                  Handle,
                  &gEfiFirmwareManagementProtocolGuid,
                  (VOID **)&Fmp,
                  NULL,
                  NULL,
                  EFI_OPEN_PROTOCOL_GET_PROTOCOL
                  );
  if (!EFI_ERROR (Status)) {
    return EFI_ALREADY_STARTED;
  }

  //
  // Allocate FMP Protocol instance
  //
  Private = AllocateCopyPool (
              sizeof (mFirmwareManagementPrivateDataTemplate),
              &mFirmwareManagementPrivateDataTemplate
              );
  if (Private == NULL) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): Failed to allocate memory for private structure.\n", mImageIdName));
    Status = EFI_OUT_OF_RESOURCES;
    goto cleanup;
  }

  //
  // Initialize private context data structure
  //
  Private->Handle = Handle;
  Private->FmpDeviceContext = NULL;
  Status = FmpDeviceSetContext (Private->Handle, &Private->FmpDeviceContext);
  if (Status == EFI_UNSUPPORTED) {
    Private->FmpDeviceContext = NULL;
  } else if (EFI_ERROR (Status)) {
    goto cleanup;
  }

  //
  // Make sure the descriptor has already been loaded or refreshed
  //
  PopulateDescriptor (Private);

  if (IsLockFmpDeviceAtLockEventGuidRequired ()) {
    //
    // Register all UEFI Variables used by this module to be locked.
    //
    Status = LockAllFmpVariables (Private);
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): Failed to register variables to lock.  Status = %r.\n", mImageIdName, Status));
    } else {
      DEBUG ((DEBUG_INFO, "FmpDxe(%s): All variables registered to lock\n", mImageIdName));
    }

    //
    // Create and register notify function to lock the FMP device.
    //
    Status = gBS->CreateEventEx (
                    EVT_NOTIFY_SIGNAL,
                    TPL_CALLBACK,
                    FmpDxeLockEventNotify,
                    Private,
                    mLockGuid,
                    &Private->FmpDeviceLockEvent
                    );
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): Failed to register notification.  Status = %r\n", mImageIdName, Status));
    }
    ASSERT_EFI_ERROR (Status);
  } else {
    DEBUG ((DEBUG_VERBOSE, "FmpDxe(%s): Not registering notification to call FmpDeviceLock() because mfg mode\n", mImageIdName));
  }

  //
  // Install FMP Protocol and FMP Progress Protocol
  //
  Status = gBS->InstallMultipleProtocolInterfaces (
                  &Private->Handle,
                  &gEfiFirmwareManagementProtocolGuid, &Private->Fmp,
                  &gEdkiiFirmwareManagementProgressProtocolGuid, &mFmpProgress,
                  NULL
                  );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): Protocol install error. Status = %r.\n", mImageIdName, Status));
    goto cleanup;
  }

cleanup:

  if (EFI_ERROR (Status)) {
    if (Private != NULL) {
      if (Private->FmpDeviceLockEvent != NULL) {
        gBS->CloseEvent (Private->FmpDeviceLockEvent);
      }
      if (Private->Descriptor.VersionName != NULL) {
        FreePool (Private->Descriptor.VersionName);
      }
      if (Private->FmpDeviceContext != NULL) {
        FmpDeviceSetContext (NULL, &Private->FmpDeviceContext);
      }
      if (Private->VersionVariableName != NULL) {
        FreePool (Private->VersionVariableName);
      }
      if (Private->LsvVariableName != NULL) {
        FreePool (Private->LsvVariableName);
      }
      if (Private->LastAttemptStatusVariableName != NULL) {
        FreePool (Private->LastAttemptStatusVariableName);
      }
      if (Private->LastAttemptVersionVariableName != NULL) {
        FreePool (Private->LastAttemptVersionVariableName);
      }
      if (Private->FmpStateVariableName != NULL) {
        FreePool (Private->FmpStateVariableName);
      }
      FreePool (Private);
    }
  }

  return Status;
}

/**
  Function to uninstall FMP instance.

  @param[in]  Handle  The device handle to install a FMP instance on.

  @retval  EFI_SUCCESS            FMP Installed
  @retval  EFI_INVALID_PARAMETER  Handle was invalid
  @retval  other                  Error installing FMP

**/
EFI_STATUS
EFIAPI
UninstallFmpInstance (
  IN EFI_HANDLE  Handle
  )
{
  EFI_STATUS                        Status;
  EFI_FIRMWARE_MANAGEMENT_PROTOCOL  *Fmp;
  FIRMWARE_MANAGEMENT_PRIVATE_DATA  *Private;

  Status = gBS->OpenProtocol (
                  Handle,
                  &gEfiFirmwareManagementProtocolGuid,
                  (VOID **)&Fmp,
                  NULL,
                  NULL,
                  EFI_OPEN_PROTOCOL_GET_PROTOCOL
                  );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): Protocol open error. Status = %r.\n", mImageIdName, Status));
    return Status;
  }

  Private = FIRMWARE_MANAGEMENT_PRIVATE_DATA_FROM_THIS (Fmp);
  FmpDeviceSetContext (Private->Handle, &Private->FmpDeviceContext);

  if (Private->FmpDeviceLockEvent != NULL) {
    gBS->CloseEvent (Private->FmpDeviceLockEvent);
  }

  Status = gBS->UninstallMultipleProtocolInterfaces (
                  Private->Handle,
                  &gEfiFirmwareManagementProtocolGuid, &Private->Fmp,
                  &gEdkiiFirmwareManagementProgressProtocolGuid, &mFmpProgress,
                  NULL
                  );
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): Protocol uninstall error. Status = %r.\n", mImageIdName, Status));
    return Status;
  }

  if (Private->Descriptor.VersionName != NULL) {
    FreePool (Private->Descriptor.VersionName);
  }
  if (Private->FmpDeviceContext != NULL) {
    FmpDeviceSetContext (NULL, &Private->FmpDeviceContext);
  }
  if (Private->VersionVariableName != NULL) {
    FreePool (Private->VersionVariableName);
  }
  if (Private->LsvVariableName != NULL) {
    FreePool (Private->LsvVariableName);
  }
  if (Private->LastAttemptStatusVariableName != NULL) {
    FreePool (Private->LastAttemptStatusVariableName);
  }
  if (Private->LastAttemptVersionVariableName != NULL) {
    FreePool (Private->LastAttemptVersionVariableName);
  }
  if (Private->FmpStateVariableName != NULL) {
    FreePool (Private->FmpStateVariableName);
  }
  FreePool (Private);

  return EFI_SUCCESS;
}

/**
  Unloads the application and its installed protocol.

  @param ImageHandle       Handle that identifies the image to be unloaded.
  @param  SystemTable      The system table.

  @retval EFI_SUCCESS      The image has been unloaded.

**/
EFI_STATUS
EFIAPI
FmpDxeLibDestructor (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  if (mFmpSingleInstance) {
    return UninstallFmpInstance (ImageHandle);
  }
  return EFI_SUCCESS;
}

/**
  Main entry for this driver/library.

  @param[in] ImageHandle  Image handle this driver.
  @param[in] SystemTable  Pointer to SystemTable.

**/
EFI_STATUS
EFIAPI
FmpDxeEntryPoint (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS  Status;

  //
  // Verify that a new FILE_GUID value has been provided in the <Defines>
  // section of this module.  The FILE_GUID is the ESRT GUID that must be
  // unique for each updatable firmware image.
  //
  if (CompareGuid (&mDefaultModuleFileGuid, &gEfiCallerIdGuid)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe: Use of default FILE_GUID detected.  FILE_GUID must be set to a unique value.\n"));
    ASSERT (FALSE);
    return EFI_UNSUPPORTED;
  }

  //
  // Get the ImageIdName value for the EFI_FIRMWARE_IMAGE_DESCRIPTOR from a PCD.
  //
  mImageIdName = (CHAR16 *) PcdGetPtr (PcdFmpDeviceImageIdName);
  if (PcdGetSize (PcdFmpDeviceImageIdName) <= 2 || mImageIdName[0] == 0) {
    //
    // PcdFmpDeviceImageIdName must be set to a non-empty Unicode string
    //
    // MU_CHANGE - Elaborate on which FmpDriver is failing.
    DEBUG ((DEBUG_ERROR, "FmpDxe(%g): PcdFmpDeviceImageIdName is an empty string.\n", &gEfiCallerIdGuid));
    ASSERT (FALSE);
    return EFI_UNSUPPORTED;
  }

  //
  // Detects if PcdFmpDevicePkcs7CertBufferXdr contains a test key.
  //
  DetectTestKey ();

  //
  // Fill in FMP Progress Protocol fields for Version 1
  //
  mFmpProgress.Version                        = 1;
  mFmpProgress.ProgressBarForegroundColor.Raw = PcdGet32 (PcdFmpDeviceProgressColor);
  mFmpProgress.WatchdogSeconds                = PcdGet8 (PcdFmpDeviceProgressWatchdogTimeInSeconds);

  // The lock event GUID is retrieved from PcdFmpDeviceLockEventGuid.
  // If PcdFmpDeviceLockEventGuid is not the size of an EFI_GUID, then
  // gEfiEndOfDxeEventGroupGuid is used.
  //
  mLockGuid = &gEfiEndOfDxeEventGroupGuid;
  if (PcdGetSize (PcdFmpDeviceLockEventGuid) == sizeof (EFI_GUID)) {
    mLockGuid = (EFI_GUID *)PcdGetPtr (PcdFmpDeviceLockEventGuid);
  }
  DEBUG ((DEBUG_INFO, "FmpDxe(%s): Lock GUID: %g\n", mImageIdName, mLockGuid));

  //
  // Register with library the install function so if the library uses
  // UEFI driver model/driver binding protocol it can install FMP on its device handle
  // If library is simple lib that does not use driver binding then it should return
  // unsupported and this will install the FMP instance on the ImageHandle
  //
  Status = RegisterFmpInstaller (InstallFmpInstance);
  if (Status == EFI_UNSUPPORTED) {
    mFmpSingleInstance = TRUE;
    DEBUG ((DEBUG_INFO, "FmpDxe(%s): FmpDeviceLib registration returned EFI_UNSUPPORTED.  Installing single FMP instance.\n", mImageIdName));
    Status = RegisterFmpUninstaller (UninstallFmpInstance);
    if (Status == EFI_UNSUPPORTED) {
      Status = InstallFmpInstance (ImageHandle);
    } else {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): FmpDeviceLib RegisterFmpInstaller and RegisterFmpUninstaller do not match.\n", mImageIdName));
      Status = EFI_UNSUPPORTED;
    }
  } else if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "FmpDxe(%s): FmpDeviceLib registration returned %r.  No FMP installed.\n", mImageIdName, Status));
  } else {
    DEBUG ((
      DEBUG_INFO,
      "FmpDxe(%s): FmpDeviceLib registration returned EFI_SUCCESS.  Expect FMP to be installed during the BDS/Device connection phase.\n",
      mImageIdName
      ));
    Status = RegisterFmpUninstaller (UninstallFmpInstance);
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "FmpDxe(%s): FmpDeviceLib RegisterFmpInstaller and RegisterFmpUninstaller do not match.\n", mImageIdName));
    }
  }

  return Status;
}