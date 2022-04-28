/*
 * timer0.c
 *
 *  Created on: 2022年4月22日
 *      Author: Legend
 */
#include "timer0.h"
#include "debug/debug.h"
//测试一秒输出一个alive\n


void timer0_callback(timer_callback_args_t *p_args) {
	if (TIMER_EVENT_CYCLE_END == p_args->event) {
		debug("alive\n");
	}
}

void timer0_init(){
	R_GPT_Open(&g_timer0_ctrl, &g_timer0_cfg);
	(void) R_GPT_Start(&g_timer0_ctrl);
}
