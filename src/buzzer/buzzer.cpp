/*
 * buzzer.cpp
 *
 *  Created on: 2022年5月5日
 *      Author: Legend
 */
/*
 * pwm控制蜂鸣器，使用gpt4(general pwm timer).
 * 瑞萨的gpt0是32位，其他是16位，谨防溢出。
 */
#include "buzzer.h"

void buzzer_init(){
    R_GPT_Open(&gpt4_speaker_ctrl, &gpt4_speaker_cfg);
}

//开始输出特定频率的pwm，占空比固定50%
void buzzer_start(uint16_t freq){
    //设置频率。TODO 根据当前pclockd计算
	uint32_t pclkd_freq_hz = BSP_STARTUP_PCLKD_HZ >> gpt4_speaker_cfg.source_div;
	uint32_t period_counts =
		(uint32_t) (((uint64_t) pclkd_freq_hz) / 4000);
    R_GPT_PeriodSet(&gpt4_speaker_ctrl, period_counts);
    //设置占空比50%
    R_GPT_DutyCycleSet(&gpt4_speaker_ctrl, period_counts/2, GPT_IO_PIN_GTIOCA_AND_GTIOCB);
    R_GPT_Reset(&gpt4_speaker_ctrl);
    //开始输出pwm
	R_GPT_Start(&gpt4_speaker_ctrl);
}
void buzzer_stop(){
    //停止输出
    R_GPT_Stop(&gpt4_speaker_ctrl);
}

