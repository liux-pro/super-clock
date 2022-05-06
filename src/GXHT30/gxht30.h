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
void gxht30_init();
bool gxht30_read();
int32_t gxht30_get_temperature();
int32_t gxht30_get_humidity();


#endif /* SHT30_GXHT30_H_ */
