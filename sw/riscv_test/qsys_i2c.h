
#ifndef SCR_QSYS_I2C_H
#define SCR_QSYS_I2C_H

#include <stdint.h>
#include <stdbool.h>
#include "plf_de10lite_scr1.h"
#include  "qsys_mem_map.h"

#ifndef SYSTEM_BUS_WIDTH
#define SYSTEM_BUS_WIDTH 32
#endif

#ifndef CAL_ADDR(BASE, REGNUM)
#define CAL_ADDR(BASE, REGNUM) (((BASE) + ((REGNUM) * (SYSTEM_BUS_WIDTH/8))))
#endif

// define I2C_0_BASE 0x800000
// See "ug_embedded_ip" p.172"
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

void i2c_init(uint32_t i2c_base, uint32_t i2c_freq);
void i2c_disable_isr(uint32_t i2c_base);
void i2c_start_transmit(uint32_t i2c_base, uint8_t i2c_slave_address);
//uint32_t i2c_start_transmit(uint32_t* i2c_base, uint8_t i2c_slave_address);

uint32_t i2c_start_receive(uint32_t i2c_base, uint8_t i2c_slave_address);
uint32_t i2c_write(uint32_t i2c_base, uint8_t data, bool send_stop_bit);
uint32_t i2c_read(uint32_t i2c_base, bool send_stop_bit);



#endif // SCR_QSYS_I2C_H
