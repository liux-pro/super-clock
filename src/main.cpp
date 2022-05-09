/*
 * main.cpp
 *
 *  Created on: 2022年5月6日
 *      Author: Legend
 */
#include "ws2812/ws2812.h"
#include "ws2812/logo.h"
#include "debug/debug.h"
#include "timer/fps.h"
#include "gxht30/gxht30.h"
#include "rtc/rtc.h"
#include "utils.h"
#include "adc/adc.h"
#include "buzzer/buzzer.h"
#include "color/fast_hsv2rgb.h"
#include "ble/ble.h"
#include "ws2812/show_time.h"
#include "fcal/fdatefunc.h"
#include "time.h"
#include "LEGEND.H"

void setup();
void loop();

void setup() {
	debug("legend-tech\n");
	debug("hello world\n");
	ble_init();
	uint8_t aaa[]={0xaa,0xcc,0x33};
	ble_send_sync(aaa,3);
	ws2812_init();
	logo_init();
	fps_init();
	gxht30_init();
	buzzer_init();
	adc_init();
	rtc_init();
}

int32_t switcher;
const uint8_t switch_time=5;
bool rtc_ready = false;
void loop() {
	if (fps_need_refresh()) {
		/*
		 * 轮询检查蓝牙有没有发来数据
		 * 有就处理一下。
		 */
		static uint8_t *ble_data;
		static uint16_t ble_data_len;
		if(ble_get_data(&ble_data,&ble_data_len)){
//			for(int i =0;i<ble_data_len;i++){
//				   debug("%x ",ble_data[i]);
//			   }
			if(ble_grep_receiver(ble_data)==LEGEND_DEVICE_CURRENT){
	            switch (ble_grep_command(ble_data)){
	            //TODO 幂等
	            	case  LEGEND_CMD_SET_TIME:
	    				time_t timestamp=(((time_t)(ble_data[3]))<<56)
	    								   |(((time_t)(ble_data[4]))<<48)
	    								   |(((time_t)(ble_data[5]))<<40)
	    								   |(((time_t)(ble_data[6]))<<32)
	    								   |((ble_data[7])<<24)
	    								   |((ble_data[8])<<16)
	    								   |((ble_data[9])<<8)
	    								   |((ble_data[10])<<0);
	    	            rtc_set_time(timestamp);
	    	            rtc_ready=true;
	            	    break;
	            }
			}
		}


		//时钟未初始化前，这段代码接管显示。
		if(!rtc_ready){
			if(fps_get_sync()>(FPS/2)){
				ws2812_black();
				ws2812_set_color(led_bluetooth,100,0,0);
			}else{
				ws2812_black();
			}
			ws2812_send();
		  return;
		}


		//每秒自增1；
		if(fps_get_sync()==1){
		    static uint8_t simple_timer=0;
		    simple_timer++;
			if(simple_timer>switch_time){
				simple_timer=0;
				switcher++;
			}
		}
		//计算彩虹颜色
		static uint8_t r, g, b;
		static uint8_t _r, _g, _b;

		static uint16_t logo_hue = 0;
		logo_hue++;
		logo_hue = logo_hue % HSV_HUE_MAX;
		fast_hsv2rgb_8bit(logo_hue, HSV_SAT_MAX, HSV_VAL_MAX / 8, &r, &g, &b);
		fast_hsv2rgb_8bit((logo_hue+HSV_HUE_MAX/2)% HSV_HUE_MAX, HSV_SAT_MAX, HSV_VAL_MAX / 8, &_r, &_g, &_b);

		/*
		 * 主屏幕刷新
		 */
		ws2812_black();
		show_set_color(_r,_g,_b);
		show_set_color2(r,g,b);

		switch (switcher%4){
		case 0:
				show_minute();
				show_hour();
				break;
		case 1:
				show_year_week();
				show_year();
				break;
		case 2:
				show_month();
				show_day();
				break;
		case 3:
				show_lunar_month();
				show_lunar_day();
				break;
		}

		show_week();

		show_legend(true);
		ws2812_send();
		/*
		 * logo灯
		 */
		logo_black();
		logo_set_color(0, r, g, b);
		logo_set_color(1, r, g, b);
		logo_send();

		/*
		 * 每隔0.5s读一次温湿度，避免在一次循环里既读温度又读亮度
		 */
		if (fps_get_sync() == 0 || fps_get_sync() == 30) {
			gxht30_read();
		}
		/*
		 * 每隔0.5s读一次亮度，避免在一次循环里既读温度又读亮度
		 */
		if (fps_get_sync() == 5 || fps_get_sync() == 35) {
			adc_async_scan();
		}
	}

}

