/*
 * gxht30.cpp
 *
 *  Created on: 2022年4月27日
 *      Author: Legend
 */
#include "gxht30.h"

//gxht30与原版sht30 pin2pin兼容，此程序基于gxht30的说明文档，
//通过i2c链接gxht30，理论上sht30也能用。
//看这个文档，中文的，立创商城上的文档有问题
//http://www.gxcas.com/public/html/index.html#/proDetail?pid=16&id=87

// 参考https://blog.csdn.net/qq_36310253/article/details/102817564

fsp_err_t gxht30_err;
//开始自动周期测量，一秒测四次，高精度地测
uint8_t gxht30_cmd_start_interval_measure[] = { 0x23, 0x34 };
//读取周期测量的命令
uint8_t gxht30_cmd_read_interval_measure[] = { 0xE0, 0x00 };

volatile bool gxht30_busy;

static uint8_t crc8(const uint8_t *data, int len);

void gxht30_init() {
	gxht30_err = R_IIC_MASTER_Open(&g_i2c_master0_ctrl, &g_i2c_master0_cfg);
	gxht30_busy = true;
	gxht30_err = R_IIC_MASTER_Write(&g_i2c_master0_ctrl,
			gxht30_cmd_start_interval_measure,
			sizeof(gxht30_cmd_start_interval_measure), true);
	while (gxht30_busy)
		;
}

bool gxht30_read(gxht30_result *p_result) {
	gxht30_busy = true;
	gxht30_err = R_IIC_MASTER_Write(&g_i2c_master0_ctrl,
			gxht30_cmd_read_interval_measure,
			sizeof(gxht30_cmd_start_interval_measure), true);
	while (gxht30_busy) {
	}
	;
	gxht30_busy = true;
	uint8_t buffer[6] = { 0 };
	R_IIC_MASTER_Read(&g_i2c_master0_ctrl, buffer, sizeof(buffer), false);
	while (gxht30_busy) {
	}
	;
	//TODO check CRC, when fail, return false
	if ( 	buffer[2] != crc8(buffer, 2)
	     || buffer[5] != crc8(&buffer[3], 2)
		 ) {
		debug("gxht30 bad CRC");
		return false;
	}
	p_result->temperature = (int32_t) ((((((buffer[0] * 256.0) + buffer[1])
			* 175) / 65535.0) - 45) * 10000);
	p_result->humidity = (int32_t) (((((buffer[3] * 256.0) + buffer[4]) * 100)
			/ 65535.0) * 10000);
	return true;
}

static uint8_t crc8(const uint8_t *data, int len) {
	const uint8_t POLYNOMIAL = 0x31;
	uint8_t crc = 0xFF;
	int i, j;

	for (i = 0; i < len; ++i) {
		crc ^= *data++;

		for (j = 0; j < 8; ++j) {
			crc = (crc & 0x80) ? (uint8_t) (crc << 1) ^ POLYNOMIAL : (crc << 1);
		}
	}

	return crc;
}

void i2c0_callback(i2c_master_callback_args_t *p_args) {
	FSP_PARAMETER_NOT_USED(p_args);
//    g_i2c_callback_event = p_args->event;
	gxht30_busy = false;
}
