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


int main(void){
	scr_rtc_init();
    sc1f_uart_init();
    sc1f_leds_init();

	uart_puts("unko");

	*(volatile unsigned int*)PIO_LED_BASE = 0x000000AA;
	while(1);
	return 0;
}