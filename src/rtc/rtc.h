/*
 * rtc.h
 *
 *  Created on: 2022年5月4日
 *      Author: Legend
 */

#ifndef RTC_RTC_H_
#define RTC_RTC_H_
#include "hal_data.h"
#include "time.h"
#include "debug/debug.h"

static rtc_time_t _time;
void rtc_set_time(time_t timestmp);
void rtc_init();
void rtc_init(){
	R_RTC_Open(&g_rtc0_ctrl, &g_rtc0_cfg);
	rtc_set_time(12312312);
//    R_RTC_PeriodicIrqRateSet (&g_rtc0_ctrl, RTC_PERIODIC_IRQ_SELECT_1_DIV_BY_64_SECOND);
    R_RTC_PeriodicIrqRateSet (&g_rtc0_ctrl, RTC_PERIODIC_IRQ_SELECT_1_SECOND);
}

//通过时间戳设置事件。
void rtc_set_time(time_t timestmp){
	gmtime_r(&timestmp,&_time);
	R_RTC_CalendarTimeSet(&g_rtc0_ctrl, &_time);
}
void rtc_callback(rtc_callback_args_t *p_args){
	FSP_PARAMETER_NOT_USED(p_args);
	debug("%s", "from rtc\n");
}

#endif /* RTC_RTC_H_ */
