/*
 * adc.h
 *
 *  Created on: 2022年5月5日
 *      Author: Legend
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_
#include "hal_data.h"

void adc_init();
void adc_async_scan();
uint16_t adc_get_brightness();
#endif /* ADC_ADC_H_ */
