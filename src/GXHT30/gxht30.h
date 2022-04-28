/*
 * gxht30.h
 *
 *  Created on: 2022年4月27日
 *      Author: Legend
 */

#ifndef SHT30_GXHT30_H_
#define SHT30_GXHT30_H_

#include "hal_data.h"
#include "debug/debug.h"
struct gxht30_result {
	int32_t temperature;   //温度 10000倍
	int32_t humidity;    //湿度  10000倍
};
void gxht30_init();
bool gxht30_read(gxht30_result *p_result);

#endif /* SHT30_GXHT30_H_ */
