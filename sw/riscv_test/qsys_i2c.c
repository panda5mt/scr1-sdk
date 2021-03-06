// i2c driver (For Altera FPGA)

#include "qsys_mem_map.h"
#include "qsys_i2c.h"
#include "uart.h"

/*
#define TFR_CMD_OFFSET				(0x0)	//[31:10]resv, 9:STA, 8:STO, [7:1]AD, 0:RW_D
#define RX_DATA_OFFSET				(0x1)	//[31:8]resv, [7:0]RXDATA
#define CTRL_OFFSET					(0x2)
#define ISER_OFFSET					(0x3)
#define ISR_OFFSET					(0x4)
#define STATUS_OFFSET				(0x5)
#define TFR_CMD_FIFO_LVL_OFFSET		(0x6)
#define RX_DATA_FIFO_LVL_OFFSET		(0x7)
#define SCL_LOW_OFFSET				(0x8)
#define SCL_HIGH_OFFSET				(0x9)
#define SDA_HOLD_OFFSET				(0xA)

*/
void i2c_init(uint32_t i2c_base, uint32_t i2c_freq){
	volatile uint32_t **tfr_cmd, **rx_data, **ctrl, **iser,  **isr, **status, **tfr_cmd_f_lvl, **rx_data_f_lvl,
	**scl_low, **scl_high, **sda_hold;
	
	tfr_cmd 	= CAL_ADDR(i2c_base, TFR_CMD_OFFSET);
	ctrl    	= CAL_ADDR(i2c_base, CTRL_OFFSET);
	isr 		= CAL_ADDR(i2c_base, ISR_OFFSET);
	ctrl    	= CAL_ADDR(i2c_base, CTRL_OFFSET);
	scl_low		= CAL_ADDR(i2c_base, SCL_LOW_OFFSET);
	scl_high    = CAL_ADDR(i2c_base, SCL_HIGH_OFFSET);
	sda_hold	= CAL_ADDR(i2c_base, SDA_HOLD_OFFSET);
	
	*(volatile uint32_t *)ctrl		&= 0xFFFFFFFFE; // disable i2c core
	*(volatile uint32_t *)ctrl		|= 0x02;
	
	// 400kHz config
	*(volatile uint32_t *)scl_low	= (i2c_freq/400000)/2;
	*(volatile uint32_t *)scl_high	= (i2c_freq/400000)/2;
	*(volatile uint32_t *)sda_hold	= (i2c_freq/400000)/2;

	*(volatile uint32_t *)ctrl |= 0x03; // enable i2c core
}

void i2c_disable_isr(uint32_t i2c_base){}

void i2c_start_transmit(uint32_t i2c_base, uint8_t i2c_slave_address){
	//[31:10]rsv,[9]STA=1, [8]STO=0,[7:1]AD=i2c_slave_address(7bit),[0]RW_D=0
	volatile uint32_t **tfr_cmd, **rx_data, **ctrl, **iser,  **isr, **status, **tfr_cmd_f_lvl, **rx_data_f_lvl,
	**scl_low, **scl_high, **sda_hold;
	
	tfr_cmd 	= CAL_ADDR(i2c_base, TFR_CMD_OFFSET);
	ctrl    	= CAL_ADDR(i2c_base, CTRL_OFFSET);
	iser 		= CAL_ADDR(i2c_base, ISER_OFFSET);
	isr 		= CAL_ADDR(i2c_base, ISR_OFFSET);
	ctrl    	= CAL_ADDR(i2c_base, CTRL_OFFSET);
	scl_low		= CAL_ADDR(i2c_base, SCL_LOW_OFFSET);
	scl_high    = CAL_ADDR(i2c_base, SCL_HIGH_OFFSET);
	sda_hold	= CAL_ADDR(i2c_base, SDA_HOLD_OFFSET);
	
	//uart_puts("ISR = ");
	//uart_putdec(*(volatile uint32_t*)isr);
	//uart_puts(" \r\n");
	
	// ISR[0]:TX_READY=1?(1:OK to send?)
	while(!(*(volatile uint32_t *)isr & 0x0001));
	// send Start + I2C Slave address
	*(volatile uint32_t *)tfr_cmd =(1U << 9) + (0U << 8) + (i2c_slave_address << 1) + 0;
		
	return;

}

uint32_t i2c_start_receive(uint32_t i2c_base, uint8_t i2c_slave_address){}


uint32_t i2c_write(uint32_t i2c_base, uint8_t data, bool send_stop_bit){
	
	volatile uint32_t **tfr_cmd, **rx_data, **ctrl, **iser,  **isr, **status, **tfr_cmd_f_lvl, **rx_data_f_lvl,
	**scl_low, **scl_high, **sda_hold;
	
	tfr_cmd 	= CAL_ADDR(i2c_base, TFR_CMD_OFFSET);
	ctrl    	= CAL_ADDR(i2c_base, CTRL_OFFSET);
	iser 		= CAL_ADDR(i2c_base, ISER_OFFSET);
	isr 		= CAL_ADDR(i2c_base, ISR_OFFSET);
	ctrl    	= CAL_ADDR(i2c_base, CTRL_OFFSET);
	
	// ISR[0]:TX_READY=1?(1:OK to send?)
	while(!(*(volatile uint32_t *)isr & 0x0001));
	// send Start + I2C Slave address
	if(true == send_stop_bit)
		*(volatile uint32_t *)tfr_cmd =(0U << 9) + (1U << 8) + (data);
	else
		*(volatile uint32_t *)tfr_cmd =(0U << 9) + (0U << 8) + (data);
	return 0;
	
}
uint32_t i2c_read(uint32_t i2c_base, bool send_stop_bit){
	volatile uint32_t **tfr_cmd, **rx_data, **ctrl, **iser,  **isr, **status, **tfr_cmd_f_lvl, **rx_data_f_lvl,
	**scl_low, **scl_high, **sda_hold;
	tfr_cmd 	= CAL_ADDR(i2c_base, TFR_CMD_OFFSET);
	rx_data		= CAL_ADDR(i2c_base, RX_DATA_OFFSET);
	ctrl    	= CAL_ADDR(i2c_base, CTRL_OFFSET);
	iser 		= CAL_ADDR(i2c_base, ISER_OFFSET);
	isr 		= CAL_ADDR(i2c_base, ISR_OFFSET);
	ctrl    	= CAL_ADDR(i2c_base, CTRL_OFFSET);
	scl_low		= CAL_ADDR(i2c_base, SCL_LOW_OFFSET);
	scl_high    = CAL_ADDR(i2c_base, SCL_HIGH_OFFSET);
	sda_hold	= CAL_ADDR(i2c_base, SDA_HOLD_OFFSET);
	
	// ISR[0]:TX_READY=1?(1:OK to send?)
	while(!(*(volatile uint32_t *)isr & 0x0001));
	
	if(true == send_stop_bit)
		*(volatile uint32_t *)tfr_cmd =(0U << 9) + (1U << 8) + (0x00);
	else
		*(volatile uint32_t *)tfr_cmd =(0U << 9) + (0U << 8) + (0x00);
	// ISR[1]:RX_READY=1?(1:RX finish)
	while(!(*(volatile uint32_t *)isr & 0x0002));
	
	return *(volatile uint32_t*)rx_data;
}
