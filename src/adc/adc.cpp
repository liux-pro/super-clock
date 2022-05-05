/*
 * adc.cpp
 *
 *  Created on: 2022年5月5日
 *      Author: Legend
 */
#include "adc.h"
uint16_t brightness=0;

void adc_callback(adc_callback_args_t *p_args) {
	FSP_PARAMETER_NOT_USED(p_args);
	R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_19, &brightness);
}

void adc_init(){
	R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);
	R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);
}

void adc_async_scan(){
	R_ADC_ScanStart(&g_adc0_ctrl);
}

uint16_t adc_get_brightness(){
	return brightness;
}
