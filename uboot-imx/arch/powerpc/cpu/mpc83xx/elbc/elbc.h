#ifdef CONFIG_ELBC_BR0_OR0
#define CONFIG_SYS_BR0_PRELIM (\
	CONFIG_BR0_OR0_BASE |\
	CONFIG_BR0_PORTSIZE |\
	CONFIG_BR0_ERRORCHECKING |\
	CONFIG_BR0_WRITE_PROTECT_BIT |\
	CONFIG_BR0_MACHINE |\
	CONFIG_BR0_ATOMIC |\
	CONFIG_BR0_VALID_BIT \
)
#define CONFIG_SYS_OR0_PRELIM (\
	CONFIG_OR0_AM |\
	CONFIG_OR0_XAM |\
	CONFIG_OR0_BCTLD |\
	CONFIG_OR0_BI |\
	CONFIG_OR0_COLS |\
	CONFIG_OR0_ROWS |\
	CONFIG_OR0_PMSEL |\
	CONFIG_OR0_SCY |\
	CONFIG_OR0_PGS |\
	CONFIG_OR0_CSCT |\
	CONFIG_OR0_CST |\
	CONFIG_OR0_CHT |\
	CONFIG_OR0_RST |\
	CONFIG_OR0_CSNT |\
	CONFIG_OR0_ACS |\
	CONFIG_OR0_XACS |\
	CONFIG_OR0_SETA |\
	CONFIG_OR0_TRLX |\
	CONFIG_OR0_EHTR |\
	CONFIG_OR0_EAD \
)
#endif /* CONFIG_ELBC_BR0_OR0 */

#ifdef CONFIG_ELBC_BR1_OR1
#define CONFIG_SYS_BR1_PRELIM (\
	CONFIG_BR1_OR1_BASE |\
	CONFIG_BR1_PORTSIZE |\
	CONFIG_BR1_ERRORCHECKING |\
	CONFIG_BR1_WRITE_PROTECT_BIT |\
	CONFIG_BR1_MACHINE |\
	CONFIG_BR1_ATOMIC |\
	CONFIG_BR1_VALID_BIT \
)
#define CONFIG_SYS_OR1_PRELIM (\
	CONFIG_OR1_AM |\
	CONFIG_OR1_XAM |\
	CONFIG_OR1_BCTLD |\
	CONFIG_OR1_BI |\
	CONFIG_OR1_COLS |\
	CONFIG_OR1_ROWS |\
	CONFIG_OR1_PMSEL |\
	CONFIG_OR1_SCY |\
	CONFIG_OR1_PGS |\
	CONFIG_OR1_CSCT |\
	CONFIG_OR1_CST |\
	CONFIG_OR1_CHT |\
	CONFIG_OR1_RST |\
	CONFIG_OR1_CSNT |\
	CONFIG_OR1_ACS |\
	CONFIG_OR1_XACS |\
	CONFIG_OR1_SETA |\
	CONFIG_OR1_TRLX |\
	CONFIG_OR1_EHTR |\
	CONFIG_OR1_EAD \
)
#endif /* CONFIG_ELBC_BR1_OR1 */

#ifdef CONFIG_ELBC_BR2_OR2
#define CONFIG_SYS_BR2_PRELIM (\
	CONFIG_BR2_OR2_BASE |\
	CONFIG_BR2_PORTSIZE |\
	CONFIG_BR2_ERRORCHECKING |\
	CONFIG_BR2_WRITE_PROTECT_BIT |\
	CONFIG_BR2_MACHINE |\
	CONFIG_BR2_ATOMIC |\
	CONFIG_BR2_VALID_BIT \
)
#define CONFIG_SYS_OR2_PRELIM (\
	CONFIG_OR2_AM |\
	CONFIG_OR2_XAM |\
	CONFIG_OR2_BCTLD |\
	CONFIG_OR2_BI |\
	CONFIG_OR2_COLS |\
	CONFIG_OR2_ROWS |\
	CONFIG_OR2_PMSEL |\
	CONFIG_OR2_SCY |\
	CONFIG_OR2_PGS |\
	CONFIG_OR2_CSCT |\
	CONFIG_OR2_CST |\
	CONFIG_OR2_CHT |\
	CONFIG_OR2_RST |\
	CONFIG_OR2_CSNT |\
	CONFIG_OR2_ACS |\
	CONFIG_OR2_XACS |\
	CONFIG_OR2_SETA |\
	CONFIG_OR2_TRLX |\
	CONFIG_OR2_EHTR |\
	CONFIG_OR2_EAD \
)
#endif /* CONFIG_ELBC_BR2_OR2 */

#ifdef CONFIG_ELBC_BR3_OR3
#define CONFIG_SYS_BR3_PRELIM (\
	CONFIG_BR3_OR3_BASE |\
	CONFIG_BR3_PORTSIZE |\
	CONFIG_BR3_ERRORCHECKING |\
	CONFIG_BR3_WRITE_PROTECT_BIT |\
	CONFIG_BR3_MACHINE |\
	CONFIG_BR3_ATOMIC |\
	CONFIG_BR3_VALID_BIT \
)
#define CONFIG_SYS_OR3_PRELIM (\
	CONFIG_OR3_AM |\
	CONFIG_OR3_XAM |\
	CONFIG_OR3_BCTLD |\
	CONFIG_OR3_BI |\
	CONFIG_OR3_COLS |\
	CONFIG_OR3_ROWS |\
	CONFIG_OR3_PMSEL |\
	CONFIG_OR3_SCY |\
	CONFIG_OR3_PGS |\
	CONFIG_OR3_CSCT |\
	CONFIG_OR3_CST |\
	CONFIG_OR3_CHT |\
	CONFIG_OR3_RST |\
	CONFIG_OR3_CSNT |\
	CONFIG_OR3_ACS |\
	CONFIG_OR3_XACS |\
	CONFIG_OR3_SETA |\
	CONFIG_OR3_TRLX |\
	CONFIG_OR3_EHTR |\
	CONFIG_OR3_EAD \
)
#endif /* CONFIG_ELBC_BR3_OR3 */

#ifdef CONFIG_ELBC_BR4_OR4
#define CONFIG_SYS_BR4_PRELIM (\
	CONFIG_BR4_OR4_BASE |\
	CONFIG_BR4_PORTSIZE |\
	CONFIG_BR4_ERRORCHECKING |\
	CONFIG_BR4_WRITE_PROTECT_BIT |\
	CONFIG_BR4_MACHINE |\
	CONFIG_BR4_ATOMIC |\
	CONFIG_BR4_VALID_BIT \
)
#define CONFIG_SYS_OR4_PRELIM (\
	CONFIG_OR4_AM |\
	CONFIG_OR4_XAM |\
	CONFIG_OR4_BCTLD |\
	CONFIG_OR4_BI |\
	CONFIG_OR4_COLS |\
	CONFIG_OR4_ROWS |\
	CONFIG_OR4_PMSEL |\
	CONFIG_OR4_SCY |\
	CONFIG_OR4_PGS |\
	CONFIG_OR4_CSCT |\
	CONFIG_OR4_CST |\
	CONFIG_OR4_CHT |\
	CONFIG_OR4_RST |\
	CONFIG_OR4_CSNT |\
	CONFIG_OR4_ACS |\
	CONFIG_OR4_XACS |\
	CONFIG_OR4_SETA |\
	CONFIG_OR4_TRLX |\
	CONFIG_OR4_EHTR |\
	CONFIG_OR4_EAD \
)
#endif /* CONFIG_ELBC_BR4_OR4 */

#if defined(CONFIG_ELBC_BR_OR_NAND_PRELIM_0)
#define CONFIG_SYS_NAND_BR_PRELIM CONFIG_SYS_BR0_PRELIM
#define CONFIG_SYS_NAND_OR_PRELIM CONFIG_SYS_OR0_PRELIM
#elif defined(CONFIG_ELBC_BR_OR_NAND_PRELIM_1)
#define CONFIG_SYS_NAND_BR_PRELIM CONFIG_SYS_BR1_PRELIM
#define CONFIG_SYS_NAND_OR_PRELIM CONFIG_SYS_OR1_PRELIM
#elif defined(CONFIG_ELBC_BR_OR_NAND_PRELIM_2)
#define CONFIG_SYS_NAND_BR_PRELIM CONFIG_SYS_BR2_PRELIM
#define CONFIG_SYS_NAND_OR_PRELIM CONFIG_SYS_OR2_PRELIM
#elif defined(CONFIG_ELBC_BR_OR_NAND_PRELIM_3)
#define CONFIG_SYS_NAND_BR_PRELIM CONFIG_SYS_BR3_PRELIM
#define CONFIG_SYS_NAND_OR_PRELIM CONFIG_SYS_OR3_PRELIM
#elif defined(CONFIG_ELBC_BR_OR_NAND_PRELIM_4)
#define CONFIG_SYS_NAND_BR_PRELIM CONFIG_SYS_BR4_PRELIM
#define CONFIG_SYS_NAND_OR_PRELIM CONFIG_SYS_OR4_PRELIM
#endif