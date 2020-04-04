#ifndef SCR_QSYS_SPI_H
#define SCR_QSYS_SPI_H

#include <stdint.h>
#include "plf_de10lite_scr1.h"
#include  "qsys_mem_map.h"

#ifndef SYSTEM_BUS_WIDTH
#define SYSTEM_BUS_WIDTH 32
#endif

#ifndef CAL_ADDR(BASE, REGNUM)
#define CAL_ADDR(BASE, REGNUM) (((BASE) + ((REGNUM) * (SYSTEM_BUS_WIDTH/8))))
#endif
// define SPI_0_BASE 0x800000
// See "ug_embedded_ip" p.48
#define SPI_RXDATA_OFFSET			(0x0)	//[31:10]resv, 9:STA, 8:STO, [7:1]AD, 0:RW_D
#define SPI_TXDATA_OFFSET			(0x1)	//[31:8]resv, [7:0]RXDATA
#define SPI_STATUS_OFFSET			(0x2)
#define SPI_CONTROL_OFFSET			(0x3)
#define SPI_RESERVED_OFFSET			(0x4)
#define SPI_SLAVESELECT_OFFSET		(0x5)
#define SPI_EOP_VALUE_OFFSET		(0x6)


void spi_init(uint32_t spi_base);
void spi_disable_isr(uint32_t spi_base);
uint32_t spi_write(uint32_t spi_base, uint8_t data);
uint32_t spi_read(uint32_t spi_base);
void spi_slave_select(uint32_t spi_base, uint32_t slaveselect_mask);
void spi_slave_deselect(uint32_t spi_base, uint32_t slaveselect_mask);


#endif // SCR_QSYS_SPI_H
