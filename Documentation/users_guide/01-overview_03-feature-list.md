Feature List per Board {#feature-list}
----

Table: Overview of the currently supported features for every board.


| Feature      |   MCIMX8M-EVK     |    8MMINILPD4-EVK     |
|:-------------|:-----------------:|:--------------------: |
| BSP name     | NXPEVK_IMX8M_4GB  | NXPEVK_iMX8M_Mini_2GB |
| SD Card boot |         Y         |            Y          |
| eMMC boot    |         Y         |            Y          |
| Audio        |         Y         |            Y          |
| GPIO         |         Y         |            Y          |
| I2C          |         Y         |            Y          |
| Ethernet     |         Y         |            Y          |
| PWM          |         Y         |            Y          |
| SD Card      |         Y         |            Y          |
| eMMC         |         Y         |            Y          |
| SPI (master) |        N/A        |           N/A         |
| Display      |         Y         |            Y          |
| UART         |         Y*        |            Y*         |
| USB (host)   |         Y         |            Y          |
| PCIe         |         Y         |            Y          |
| TrEE         |         Y         |            Y          |
| Processor PM |         Y         |            Y          |
| Device PM    |        N**        |           N**         |
| LP standby   |        N**        |           N**         |
| Display PM   |         Y         |            Y          |
| DMA          |         Y         |            Y          |
| VPU          |         Y         |            Y          |

| Legend | Meaning                                                                       |
|:-------|:------------------------------------------------------------------------------|
| Y      | Enabled                                                                       |
| Y*     | To enable the UART, the kernel debugger must be disabled by running the following command on the device and rebooting. The UART exposed is the same UART that the kernel debugger uses. `bcdedit /debug off` |
| N/A    | Feature not applicable                                                        |
| N*     | Feature not enabled - feature is not available in default board configuration |
| N**    | Feature not enabled - feature is not currently supported                      |
| PM     | Power management                                                              |
| LP     | Low power                                                                     |

Not all features of a given subsystem maybe fully enabled and/or optimized. If you encounter issues with supported features, please open an issue.
