// i2c driver (For Altera FPGA)


#include "qsys_mem_map.h"
#include "qsys_spi.h"
#include "uart.h"


#define SPI_RXDATA_OFFSET			(0x0)	//[31:10]resv, 9:STA, 8:STO, [7:1]AD, 0:RW_D
#define SPI_TXDATA_OFFSET			(0x1)	//[31:8]resv, [7:0]RXDATA
#define SPI_STATUS_OFFSET			(0x2)
#define SPI_CONTROL_OFFSET			(0x3)
#define SPI_RESERVED_OFFSET			(0x4)
#define SPI_SLAVESELECT_OFFSET		(0x5)
#define SPI_EOP_VALUE_OFFSET		(0x6)


void spi_init(uint32_t spi_base){
	return;
}
void spi_disable_isr(uint32_t spi_base){
	// todo: fix this
	return;
}

uint32_t spi_write(uint32_t spi_base, uint8_t data){
	uint32_t recv_data = 0;
	uint32_t **rxdata, **txdata, **status, **control, **slaveselect, **eop_value;

	rxdata    	= CAL_ADDR(spi_base, SPI_RXDATA_OFFSET);
	txdata    	= CAL_ADDR(spi_base, SPI_TXDATA_OFFSET);
	status    	= CAL_ADDR(spi_base, SPI_STATUS_OFFSET);
	control    	= CAL_ADDR(spi_base, SPI_CONTROL_OFFSET);
	eop_value	= CAL_ADDR(spi_base, SPI_EOP_VALUE_OFFSET);
	
	//*(volatile uint32_t*)status = 0;
	// status[6]=1:ready to Send(=0b0100_0000)
	while(!(*(volatile uint32_t *)status & 0x0040));
	*(volatile uint32_t*)txdata = data;
	
	// status[7]=1:ready to recv(=0b1000_0000)
	while(!(*(volatile uint32_t *)status & 0x0080));
	recv_data = (uint32_t)*(volatile uint32_t*)rxdata;
		
	return recv_data;
}

uint32_t spi_read(uint32_t spi_base){
	return (spi_write(spi_base,0x00));
}

void spi_slave_select(uint32_t spi_base, uint32_t slaveselect_mask){
	
	uint32_t recv_data = 0;
	uint32_t **rxdata, **txdata, **status, **control, **slaveselect, **eop_value;

	rxdata    	= CAL_ADDR(spi_base, SPI_RXDATA_OFFSET);
	txdata    	= CAL_ADDR(spi_base, SPI_TXDATA_OFFSET);
	status    	= CAL_ADDR(spi_base, SPI_STATUS_OFFSET);
	control    	= CAL_ADDR(spi_base, SPI_CONTROL_OFFSET);
	slaveselect = CAL_ADDR(spi_base, SPI_SLAVESELECT_OFFSET);
	eop_value	= CAL_ADDR(spi_base, SPI_EOP_VALUE_OFFSET);
	
	*(volatile uint32_t*)slaveselect = slaveselect_mask;
	
	// control[10]=SSO:force select SS(=0b10_0000_0000)
	*(volatile uint32_t*)control |= (1U << 10);
	
}

void spi_slave_deselect(uint32_t spi_base, uint32_t slaveselect_mask){
	
	uint32_t recv_data = 0;
	uint32_t **rxdata, **txdata, **status, **control, **slaveselect, **eop_value;

	rxdata    	= CAL_ADDR(spi_base, SPI_RXDATA_OFFSET);
	txdata    	= CAL_ADDR(spi_base, SPI_TXDATA_OFFSET);
	status    	= CAL_ADDR(spi_base, SPI_STATUS_OFFSET);
	control    	= CAL_ADDR(spi_base, SPI_CONTROL_OFFSET);
	slaveselect = CAL_ADDR(spi_base, SPI_SLAVESELECT_OFFSET);
	eop_value	= CAL_ADDR(spi_base, SPI_EOP_VALUE_OFFSET);
	
	*(volatile uint32_t*)slaveselect = slaveselect_mask;
	
	// control[10]=SSO:force deselect SS(=0b0100_0000_0000)
	*(volatile uint32_t*)control &= 0xFFFFFBFF;
	
}

