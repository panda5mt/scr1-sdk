#ifndef _ALTERA_QSYS_MEM_MAP_H_
#define _ALTERA_QSYS_MEM_MAP_H_

/*
 * This file was automatically generated by the swinfo2header utility.
 * 
 * Created from SOPC Builder system 'de10lite_qsys' in
 * file 'C:\RISCV\Syntacore\scr1-sdk\fpga\de10lite\scr1\qsys/de10lite_qsys.swinfo'.
 */

/*
 * This file contains macros for module 'avl_dmem' and devices
 * connected to the following master:
 *   m0
 * 
 * Do not include this header file and another header file created for a
 * different module or master group at the same time.
 * Doing so may result in duplicate macro names.
 * Instead, use the system header file which has macros with unique names.
 */

/*
 * Macros for device 'sdram', class 'altera_avalon_new_sdram_controller'
 * The macros are prefixed with 'SDRAM_'.
 * The prefix is the slave descriptor.
 */
#define SDRAM_COMPONENT_TYPE altera_avalon_new_sdram_controller
#define SDRAM_COMPONENT_NAME sdram
#define SDRAM_BASE 0x0
#define SDRAM_SPAN 8388608
#define SDRAM_END 0x7fffff
#define SDRAM_CAS_LATENCY 2
#define SDRAM_CONTENTS_INFO 
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 7.8125
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 22
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 8
#define SDRAM_SDRAM_DATA_WIDTH 16
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 12
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 0
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_T_AC 5.4
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 15.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 15.0
#define SDRAM_T_WR 14.0
#define SDRAM_MEMORY_INFO_DAT_SYM_INSTALL_DIR SIM_DIR
#define SDRAM_MEMORY_INFO_GENERATE_DAT_SYM 1
#define SDRAM_MEMORY_INFO_MEM_INIT_DATA_WIDTH 16

/*
 * Macros for device 'i2c_0', class 'altera_avalon_i2c'
 * The macros are prefixed with 'I2C_0_'.
 * The prefix is the slave descriptor.
 */
#define I2C_0_COMPONENT_TYPE altera_avalon_i2c
#define I2C_0_COMPONENT_NAME i2c_0
#define I2C_0_BASE 0x820000
#define I2C_0_SPAN 64
#define I2C_0_END 0x82003f
#define I2C_0_FIFO_DEPTH 4
#define I2C_0_FREQ 48000000
#define I2C_0_USE_AV_ST 0

/*
 * Macros for device 'spi_0', class 'altera_avalon_spi'
 * The macros are prefixed with 'SPI_0_'.
 * The prefix is the slave descriptor.
 */
#define SPI_0_COMPONENT_TYPE altera_avalon_spi
#define SPI_0_COMPONENT_NAME spi_0
#define SPI_0_BASE 0x820040
#define SPI_0_SPAN 32
#define SPI_0_END 0x82005f
#define SPI_0_CLOCKMULT 1
#define SPI_0_CLOCKPHASE 0
#define SPI_0_CLOCKPOLARITY 0
#define SPI_0_CLOCKUNITS "Hz"
#define SPI_0_DATABITS 8
#define SPI_0_DATAWIDTH 16
#define SPI_0_DELAYMULT "1.0E-9"
#define SPI_0_DELAYUNITS "ns"
#define SPI_0_EXTRADELAY 0
#define SPI_0_INSERT_SYNC 0
#define SPI_0_ISMASTER 1
#define SPI_0_LSBFIRST 0
#define SPI_0_NUMSLAVES 1
#define SPI_0_PREFIX "spi_"
#define SPI_0_SYNC_REG_DEPTH 2
#define SPI_0_TARGETCLOCK 800000
#define SPI_0_TARGETSSDELAY "0.0"

/*
 * Macros for device 'pio_0', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_0_'.
 * The prefix is the slave descriptor.
 */
#define PIO_0_COMPONENT_TYPE altera_avalon_pio
#define PIO_0_COMPONENT_NAME pio_0
#define PIO_0_BASE 0x820060
#define PIO_0_SPAN 16
#define PIO_0_END 0x82006f
#define PIO_0_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_0_CAPTURE 0
#define PIO_0_DATA_WIDTH 8
#define PIO_0_DO_TEST_BENCH_WIRING 0
#define PIO_0_DRIVEN_SIM_VALUE 0
#define PIO_0_EDGE_TYPE NONE
#define PIO_0_FREQ 48000000
#define PIO_0_HAS_IN 0
#define PIO_0_HAS_OUT 1
#define PIO_0_HAS_TRI 0
#define PIO_0_IRQ_TYPE NONE
#define PIO_0_RESET_VALUE 255

/*
 * Macros for device 'bld_id', class 'altera_avalon_pio'
 * The macros are prefixed with 'BLD_ID_'.
 * The prefix is the slave descriptor.
 */
#define BLD_ID_COMPONENT_TYPE altera_avalon_pio
#define BLD_ID_COMPONENT_NAME bld_id
#define BLD_ID_BASE 0xff000000
#define BLD_ID_SPAN 16
#define BLD_ID_END 0xff00000f
#define BLD_ID_BIT_CLEARING_EDGE_REGISTER 0
#define BLD_ID_BIT_MODIFYING_OUTPUT_REGISTER 0
#define BLD_ID_CAPTURE 0
#define BLD_ID_DATA_WIDTH 32
#define BLD_ID_DO_TEST_BENCH_WIRING 1
#define BLD_ID_DRIVEN_SIM_VALUE 3738876602
#define BLD_ID_EDGE_TYPE NONE
#define BLD_ID_FREQ 48000000
#define BLD_ID_HAS_IN 1
#define BLD_ID_HAS_OUT 0
#define BLD_ID_HAS_TRI 0
#define BLD_ID_IRQ_TYPE NONE
#define BLD_ID_RESET_VALUE 0

/*
 * Macros for device 'avl_uart', class 'altera_avalon_mm_bridge'
 * The macros are prefixed with 'AVL_UART_'.
 * The prefix is the slave descriptor.
 */
#define AVL_UART_COMPONENT_TYPE altera_avalon_mm_bridge
#define AVL_UART_COMPONENT_NAME avl_uart
#define AVL_UART_BASE 0xff010000
#define AVL_UART_SPAN 32
#define AVL_UART_END 0xff01001f

/*
 * Macros for device 'pio_hex_1_0', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_HEX_1_0_'.
 * The prefix is the slave descriptor.
 */
#define PIO_HEX_1_0_COMPONENT_TYPE altera_avalon_pio
#define PIO_HEX_1_0_COMPONENT_NAME pio_hex_1_0
#define PIO_HEX_1_0_BASE 0xff020000
#define PIO_HEX_1_0_SPAN 16
#define PIO_HEX_1_0_END 0xff02000f
#define PIO_HEX_1_0_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_HEX_1_0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_HEX_1_0_CAPTURE 0
#define PIO_HEX_1_0_DATA_WIDTH 16
#define PIO_HEX_1_0_DO_TEST_BENCH_WIRING 0
#define PIO_HEX_1_0_DRIVEN_SIM_VALUE 0
#define PIO_HEX_1_0_EDGE_TYPE NONE
#define PIO_HEX_1_0_FREQ 48000000
#define PIO_HEX_1_0_HAS_IN 0
#define PIO_HEX_1_0_HAS_OUT 1
#define PIO_HEX_1_0_HAS_TRI 0
#define PIO_HEX_1_0_IRQ_TYPE NONE
#define PIO_HEX_1_0_RESET_VALUE 65535

/*
 * Macros for device 'pio_hex_3_2', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_HEX_3_2_'.
 * The prefix is the slave descriptor.
 */
#define PIO_HEX_3_2_COMPONENT_TYPE altera_avalon_pio
#define PIO_HEX_3_2_COMPONENT_NAME pio_hex_3_2
#define PIO_HEX_3_2_BASE 0xff020010
#define PIO_HEX_3_2_SPAN 16
#define PIO_HEX_3_2_END 0xff02001f
#define PIO_HEX_3_2_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_HEX_3_2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_HEX_3_2_CAPTURE 0
#define PIO_HEX_3_2_DATA_WIDTH 16
#define PIO_HEX_3_2_DO_TEST_BENCH_WIRING 0
#define PIO_HEX_3_2_DRIVEN_SIM_VALUE 0
#define PIO_HEX_3_2_EDGE_TYPE NONE
#define PIO_HEX_3_2_FREQ 48000000
#define PIO_HEX_3_2_HAS_IN 0
#define PIO_HEX_3_2_HAS_OUT 1
#define PIO_HEX_3_2_HAS_TRI 0
#define PIO_HEX_3_2_IRQ_TYPE NONE
#define PIO_HEX_3_2_RESET_VALUE 65535

/*
 * Macros for device 'pio_hex_5_4', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_HEX_5_4_'.
 * The prefix is the slave descriptor.
 */
#define PIO_HEX_5_4_COMPONENT_TYPE altera_avalon_pio
#define PIO_HEX_5_4_COMPONENT_NAME pio_hex_5_4
#define PIO_HEX_5_4_BASE 0xff020020
#define PIO_HEX_5_4_SPAN 16
#define PIO_HEX_5_4_END 0xff02002f
#define PIO_HEX_5_4_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_HEX_5_4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_HEX_5_4_CAPTURE 0
#define PIO_HEX_5_4_DATA_WIDTH 16
#define PIO_HEX_5_4_DO_TEST_BENCH_WIRING 0
#define PIO_HEX_5_4_DRIVEN_SIM_VALUE 0
#define PIO_HEX_5_4_EDGE_TYPE NONE
#define PIO_HEX_5_4_FREQ 48000000
#define PIO_HEX_5_4_HAS_IN 0
#define PIO_HEX_5_4_HAS_OUT 1
#define PIO_HEX_5_4_HAS_TRI 0
#define PIO_HEX_5_4_IRQ_TYPE NONE
#define PIO_HEX_5_4_RESET_VALUE 65535

/*
 * Macros for device 'pio_led', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_LED_'.
 * The prefix is the slave descriptor.
 */
#define PIO_LED_COMPONENT_TYPE altera_avalon_pio
#define PIO_LED_COMPONENT_NAME pio_led
#define PIO_LED_BASE 0xff021000
#define PIO_LED_SPAN 16
#define PIO_LED_END 0xff02100f
#define PIO_LED_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_LED_CAPTURE 0
#define PIO_LED_DATA_WIDTH 10
#define PIO_LED_DO_TEST_BENCH_WIRING 0
#define PIO_LED_DRIVEN_SIM_VALUE 0
#define PIO_LED_EDGE_TYPE NONE
#define PIO_LED_FREQ 48000000
#define PIO_LED_HAS_IN 0
#define PIO_LED_HAS_OUT 1
#define PIO_LED_HAS_TRI 0
#define PIO_LED_IRQ_TYPE NONE
#define PIO_LED_RESET_VALUE 0

/*
 * Macros for device 'pio_sw', class 'altera_avalon_pio'
 * The macros are prefixed with 'PIO_SW_'.
 * The prefix is the slave descriptor.
 */
#define PIO_SW_COMPONENT_TYPE altera_avalon_pio
#define PIO_SW_COMPONENT_NAME pio_sw
#define PIO_SW_BASE 0xff022000
#define PIO_SW_SPAN 16
#define PIO_SW_END 0xff02200f
#define PIO_SW_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_SW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_SW_CAPTURE 0
#define PIO_SW_DATA_WIDTH 10
#define PIO_SW_DO_TEST_BENCH_WIRING 1
#define PIO_SW_DRIVEN_SIM_VALUE 0
#define PIO_SW_EDGE_TYPE NONE
#define PIO_SW_FREQ 48000000
#define PIO_SW_HAS_IN 1
#define PIO_SW_HAS_OUT 0
#define PIO_SW_HAS_TRI 0
#define PIO_SW_IRQ_TYPE NONE
#define PIO_SW_RESET_VALUE 0

/*
 * Macros for device 'onchip_ram', class 'altera_avalon_onchip_memory2'
 * The macros are prefixed with 'ONCHIP_RAM_'.
 * The prefix is the slave descriptor.
 */
#define ONCHIP_RAM_COMPONENT_TYPE altera_avalon_onchip_memory2
#define ONCHIP_RAM_COMPONENT_NAME onchip_ram
#define ONCHIP_RAM_BASE 0xffff0000
#define ONCHIP_RAM_SPAN 65536
#define ONCHIP_RAM_END 0xffffffff
#define ONCHIP_RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_RAM_CONTENTS_INFO ""
#define ONCHIP_RAM_DUAL_PORT 0
#define ONCHIP_RAM_GUI_RAM_BLOCK_TYPE AUTO
#define ONCHIP_RAM_INIT_CONTENTS_FILE riscv_main
#define ONCHIP_RAM_INIT_MEM_CONTENT 1
#define ONCHIP_RAM_INSTANCE_ID NONE
#define ONCHIP_RAM_NON_DEFAULT_INIT_FILE_ENABLED 1
#define ONCHIP_RAM_RAM_BLOCK_TYPE AUTO
#define ONCHIP_RAM_READ_DURING_WRITE_MODE DONT_CARE
#define ONCHIP_RAM_SINGLE_CLOCK_OP 0
#define ONCHIP_RAM_SIZE_MULTIPLE 1
#define ONCHIP_RAM_SIZE_VALUE 65536
#define ONCHIP_RAM_WRITABLE 1
#define ONCHIP_RAM_MEMORY_INFO_DAT_SYM_INSTALL_DIR SIM_DIR
#define ONCHIP_RAM_MEMORY_INFO_GENERATE_DAT_SYM 1
#define ONCHIP_RAM_MEMORY_INFO_GENERATE_HEX 1
#define ONCHIP_RAM_MEMORY_INFO_HAS_BYTE_LANE 0
#define ONCHIP_RAM_MEMORY_INFO_HEX_INSTALL_DIR QPF_DIR
#define ONCHIP_RAM_MEMORY_INFO_MEM_INIT_DATA_WIDTH 64
#define ONCHIP_RAM_MEMORY_INFO_MEM_INIT_FILENAME riscv_main


#endif /* _ALTERA_QSYS_MEM_MAP_H_ */
