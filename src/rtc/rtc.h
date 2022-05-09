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

//东八区时区修正
#define TIME_ZONE_UTC_8_OFFSET 60*60*8


void rtc_set_time(time_t timestmp);
void rtc_init();
tm* rtc_get_time();



#endif /* RTC_RTC_H_ */
