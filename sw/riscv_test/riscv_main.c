#include <stdio.h>
#include <stdint.h>
#include "plf_de10lite_scr1.h"
#include "qsys_mem_map.h"

#include "init.h"
#include "arch.h"
#include "rtc.h"
#include "uart.h"
#include "leds.h"
#include "stringify.h"
#include "qsys_i2c.h"
#include "qsys_spi.h"


int main(void){
	scr_rtc_init();
    sc1f_uart_init();
    sc1f_leds_init();
	//i2c_start_transmit(I2C_0_BASE,0x40);
	//i2c_write(I2C_0_BASE, 0x55, false);
	//i2c_write(I2C_0_BASE, 0xAA, false);
	//i2c_write(I2C_0_BASE, 0xA1, true);

		
	//spi_slave_select(SPI_0_BASE, 0x01);
	//spi_write(SPI_0_BASE, 0x48);
	uart_puts("\r\nHello world!\r\nSCR1!");

	*(volatile unsigned int*)PIO_LED_BASE = 0x000000AA;
	while(1);
	return 0;
}