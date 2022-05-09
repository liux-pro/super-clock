/*
 * show_time.cpp
 *
 *  Created on: 2022年5月9日
 *      Author: Legend
 */
//这是个双关
//
#include "show_time.h"
#include "fcal/fdatefunc.h"


uint8_t led_map[4][11]={
		{49,63,62,61,60,59,58,57,56,48,50},
		{43,51,52,53,54,55,47,46,45,44},
		{17,31,30,29,28,27,26,25,24,16,18},
		{11,19,20,21,22,23,15,14,13,12},
};

uint8_t led_week_map[]={7,1,2,3,4,5,6};
uint8_t led_temperature = 35;
uint8_t led_humidity = 36;
uint8_t led_brightness = 37;
uint8_t led_alarm = 38;
uint8_t led_bluetooth = 39;
uint8_t led_leap = 41;
uint8_t led_lunar = 42;
uint8_t led_month = 40;
uint8_t led_year = 32;
uint8_t led_hour = 33;
uint8_t led_point = 34;
uint8_t led_week = 10;
uint8_t led_day = 9;
uint8_t led_minute = 8;
uint8_t led_legend = 0;


static uint8_t r,g,b;
static uint8_t _r,_g,_b;

void show_set_color(uint8_t red, uint8_t green, uint8_t blue){
	r=red;
	g=green;
	b=blue;
}
void show_set_color2(uint8_t _red, uint8_t _green, uint8_t _blue){
	_r=_red;
	_g=_green;
	_b=_blue;
}


uint8_t split1(uint16_t num){
	return num%10;
}
uint8_t split10(uint16_t num){
	return num/10%10;
}
uint8_t split100(uint16_t num){
	return num/100%10;
}
uint8_t split1000(uint16_t num){
	return num/1000%10;
}



//显示数字，自动处理符合阅读规则
//在上面两排或下面两排显示，参数宏定义  LED_SHOW_UP LED_SHOW_DOWN
void show_num(uint16_t num,uint8_t pos){
    if(split10(num)>0){
    	//拾
        ws2812_set_color(led_map[pos][10], r, g, b);
        //十位2到9
        if(split10(num)!=1){
            ws2812_set_color(led_map[pos][split10(num)],  r, g, b);
        }
    }
    //大于10的，个位是0的，个位不显示
    if((split10(num)==0)||(split1(num)!=0)){
        ws2812_set_color(led_map[pos+1][split1(num)],  r, g, b);
    }
}

//显示数字，只考虑0-9
//在上面两排或下面两排显示，参数宏定义  LED_SHOW_UP LED_SHOW_DOWN
void show_num_simple(uint16_t num,uint8_t pos){
    ws2812_set_color(led_map[pos][split10(num)],  r, g, b);
    ws2812_set_color(led_map[pos+1][split1(num)],  r, g, b);
}

void show_icon(uint8_t icon){
    ws2812_set_color(icon, _r,_g,_b);
}


//_time.tm_min, _time.tm_sec
void show_minute(){
    uint8_t minute=rtc_get_time()->tm_min;
    show_num(minute,LED_SHOW_DOWN);
    show_icon(led_minute);
}
void show_hour(){
    uint8_t hour=rtc_get_time()->tm_hour;
    show_num(hour,LED_SHOW_UP);
    show_icon(led_hour);
}
// 如果blink为真，偶数秒时候才亮，即闪烁
void show_legend(bool blink){
	if(blink){
		uint8_t second=rtc_get_time()->tm_sec;
	    if(second%2==0){
		    show_icon(led_legend);
	    }
	}else{
	    show_icon(led_legend);
	}

}
// 显示周
void show_week(){
    uint8_t wday=rtc_get_time()->tm_wday;
    ws2812_set_color(led_week_map[wday],  r, g, b);
}


void show_year(){
    int year=rtc_get_time()->tm_year;
    year+=1900;
    show_num_simple(year,LED_SHOW_UP);
    show_icon(led_year);

	if(isLeapYear(year)){
	    show_icon(led_leap);
	}


}

extern uint8_t week_of_year;
void show_year_week(){
    show_num(week_of_year,LED_SHOW_DOWN);
    show_icon(led_week);
}


extern uint8_t lunar_month;
extern uint8_t lunar_day;
extern bool lunar_leap;

void show_lunar_month(){
    show_num(lunar_month,LED_SHOW_UP);
    show_icon(led_month);
    show_icon(led_lunar);
	if(lunar_leap){
	    show_icon(led_leap);
	}
}
void show_lunar_day(){
    show_num(lunar_day,LED_SHOW_DOWN);
    show_icon(led_day);
}

void show_month(){
    show_num(rtc_get_time()->tm_mon+1,LED_SHOW_UP);
    show_icon(led_month);
}
void show_day(){
    show_num(rtc_get_time()->tm_mday,LED_SHOW_DOWN);
    show_icon(led_day);
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
