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
}
void loop() {
	if (fps_need_refresh()) {
		static uint8_t r, g, b;
		/*
		 * 主屏幕刷新
		 */
		ws2812_black();
		for (int i = 0; i < 60; i++) {
			fast_hsv2rgb_8bit(((fps_get_sync() + i) % 60) * 256 / 10,
					HSV_SAT_MAX, HSV_VAL_MAX/8, &r, &g, &b);
			ws2812_set_color(fps_get_sync(), r, g, b);
		}
		ws2812_send();
		/*
		 * logo灯
		 */
		static uint16_t logo_hue = 0;
		logo_hue++;
		logo_hue = logo_hue % HSV_HUE_MAX;
		logo_black();
		fast_hsv2rgb_8bit(logo_hue, HSV_SAT_MAX, HSV_VAL_MAX / 8, &r, &g, &b);
		logo_set_color(0, r, g, b);
		logo_set_color(1, r, g, b);
		logo_send();

		/*
		 * 轮询检查蓝牙有没有发来数据
		 * 有就处理一下。
		 */
		static uint8_t *ble_data;
		static uint16_t ble_data_len;
		if(ble_get_data(&ble_data,&ble_data_len)){
			for(int i =0;i<ble_data_len;i++){
				   debug("%x ",ble_data[i]);
			   }
			   debug("\n");
		}

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

