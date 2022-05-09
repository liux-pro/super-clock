/*
 * show_time.h
 *
 *  Created on: 2022年5月9日
 *      Author: Legend
 */

#ifndef WS2812_SHOW_TIME_H_
#define WS2812_SHOW_TIME_H_
#include "ws2812.h"
#include "rtc/rtc.h"
#define LED_SHOW_UP 0
#define LED_SHOW_DOWN 2

void show_minute();
void show_hour();
void show_legend(bool blink);
void show_week();
void show_year();
void show_year_week();

void show_lunar_month();
void show_lunar_day();

void show_month();
void show_day();

void show_set_color(uint8_t red, uint8_t green, uint8_t blue);
void show_set_color2(uint8_t red, uint8_t green, uint8_t blue);

#endif /* WS2812_SHOW_TIME_H_ */
