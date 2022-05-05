/*
 * buzzer.h
 *
 *  Created on: 2022年5月5日
 *      Author: Legend
 */

#ifndef BUZZER_BUZZER_H_
#define BUZZER_BUZZER_H_
#include "hal_data.h"


void buzzer_init();
//开始输出特定频率的pwm，占空比固定50%
void buzzer_start(uint16_t freq);
//停止输出
void buzzer_stop();

#endif /* BUZZER_BUZZER_H_ */
