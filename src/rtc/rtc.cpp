/*
 * rtc.cpp
 *
 *  Created on: 2022年5月9日
 *      Author: Legend
 */
#include "rtc.h"
#include "fcal/fdatefunc.h"


static rtc_time_t _time;
SunDate sunDate;
uint8_t lunar_month;
uint8_t lunar_day;
bool lunar_leap;



uint8_t week_of_year;

void rtc_init(){
	R_RTC_Open(&g_rtc0_ctrl, &g_rtc0_cfg);
//    R_RTC_PeriodicIrqRateSet (&g_rtc0_ctrl, RTC_PERIODIC_IRQ_SELECT_1_DIV_BY_64_SECOND);
    R_RTC_PeriodicIrqRateSet (&g_rtc0_ctrl, RTC_PERIODIC_IRQ_SELECT_1_SECOND);
}

//午夜时分和新设置时间的时候需要重新计算日期。
void rtc_calc_date(){
	//更新阳历
	sunDate.year=(U16)(_time.tm_year + 1900);
	sunDate.month=(U8)(_time.tm_mon + 1);
	sunDate.day=(U8)_time.tm_mday;

	{
	    //计算现在是一年的第几周
		//https://stackoverflow.com/a/274913
		int julian = daysOfSunYear(sunDate);
		int dow = sunDate.day;
		SunDate sunJan1;
		sunJan1.year=sunDate.year;
		sunJan1.month=1;
		sunJan1.day=1;
		int dowJan1 = year4Quotient(sunJan1);
		int weekNum = ((julian + 6) / 7);   // probably better.  CHECK THIS LINE. (See comments.)
		if (dow < dowJan1)                 // adjust for being after Saturday of week #1
		    ++weekNum;
		week_of_year=weekNum;
	}

	{
		LunarDate lunarDate;
	    LunarDate* pLD = &lunarDate;
	    BL* bl;

	    int tmp=lunarLeapMonth(sunDate.year);
	    bl=getLunarBLArray(sunDate.year);

	    int ret;
	    ret=sunToLunar(pLD,&sunDate,bl,tmp);
	    if(ret<0){
	    	debug("convert fail");
	        return;
	    }
	    if(tmp){
	        if(pLD->month<tmp){
	        	lunar_month=(pLD->month+1)%12;
				lunar_leap=false;
	        }else if(pLD->month>tmp){
	        	lunar_month=pLD->month;
				lunar_leap=false;
	        }else
	        	lunar_month=tmp;
				lunar_leap=true;
	    }
	    else{
	    	lunar_month=pLD->month;
	    	lunar_leap=false;
	    }
	    lunar_day=pLD->day;
	}
}

//通过时间戳设置时间。
void rtc_set_time(time_t timestmp){
	//修正东八区
	timestmp += TIME_ZONE_UTC_8_OFFSET;
	//时间戳转换
	gmtime_r(&timestmp,&_time);
	R_RTC_CalendarTimeSet(&g_rtc0_ctrl, &_time);
	rtc_calc_date();
}

//反正一秒才变。不如缓存它，从中断更新。
tm* rtc_get_time(){
    return &_time;
}


void rtc_callback(rtc_callback_args_t *p_args){
	FSP_PARAMETER_NOT_USED(p_args);
	R_RTC_CalendarTimeGet(&g_rtc0_ctrl, &_time);
	//凌晨更新日期。
	if(_time.tm_hour==0
		&&	_time.tm_min==0
		&&	_time.tm_sec==0
	){
		rtc_calc_date();
	}

//    debug("\r\n RTC Report : %d/%d/%d \n Time  : %d : %d : %d \r\n\n",_time.tm_year+1900,
//    		_time.tm_mon+1, _time.tm_mday,  _time.tm_hour,
//			_time.tm_min, _time.tm_sec);
}


//struct tm {
//int tm_sec; /* 秒 – 取值区间为[0,59] */
//int tm_min; /* 分 - 取值区间为[0,59] */
//int tm_hour; /* 时 - 取值区间为[0,23] */
//int tm_mday; /* 一个月中的日期 - 取值区间为[1,31] */
//int tm_mon; /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */
//int tm_year; /* 年份，其值等于实际年份减去1900 */
//int tm_wday; /* 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推 */
//int tm_yday; /* 从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推 */
//int tm_isdst; /* 夏令时标识符，实行夏令时的时候，tm_isdst为正。不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。*/
//};
