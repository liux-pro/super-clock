/*
 * logo.cpp
 *
 *  Created on: 2022年5月5日
 *      Author: Legend
 */
#include "logo.h"
//控制两个logo ws2812
/*
 * 天坑：瑞萨的 sci spi channel 2 9 在mosi上发送信号时候.
 * 每次发送前会先把mosi拉高几微秒，然后正常发送信号。
 * 在正常spi通信时候，因为有clk信号，这没有问题。
 * 但是如果控制ws2812，这几个微秒会破环信号，导致第一个比特翻转，
 * 导致灯带第一个led收到的信号的最高位一直是1.
 * 邪门的是只有channel 2 9会这样，专用spi以及sci0，1都没有这个问题。
 * 参考：https://renesasrulz.com/embedded-system-platform/synergy/f/forum/19774/r_sci_spi-simple-spi-the-rising-edge-of-the-first-pulse-occurs-much-earlier-than-expected?ReplySortBy=CreatedDate&ReplySortOrder=Ascending
 * 官方例程采用了sci0，所以“恰好”没遇到这个问题。
 * 只能暂时发之前多发几个0xff，让这个脉冲信号远离真正的信号，希望瑞萨解解决个问题
 */


//LED 灯珠数量 不要超内存
#define LED_NUMBER 2
#define TOTAL   LED_NUMBER * 24
#define BUG_DELAY  100

//buffer 显存 GRB888  加这个10就是发BUG_DELAY个0xff，避免天坑
static uint8_t _buffer[LED_NUMBER * 24 + BUG_DELAY] = { 0 };
static uint8_t* buffer=&_buffer[BUG_DELAY];

//spi模拟0码 1100 0000
static uint8_t CODE0 = 0XC0;
//spi模拟1码 1111 1100
static uint8_t CODE1 = 0xFC;

//记录信号是否发完
static volatile bool logo_busy = false;



void logo_init() {
	//打开spi
	R_SCI_SPI_Open(&g_spi1_ctrl, &g_spi1_cfg);
	logo_black();
}

void logo_fill(uint8_t r, uint8_t g, uint8_t b) {
	for (uint16_t i = 0; i < LED_NUMBER; i++) {
		logo_set_color(i, r, g, b);
	}
}

void logo_red() {
	logo_fill(255, 0, 0);
}
void logo_green() {
	logo_fill(0, 255, 0);
}
void logo_blue() {
	logo_fill(0, 0, 255);
}
void logo_black() {
	logo_fill(0, 0, 0);
}

void logo_set_color(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
	uint8_t *p_buffer = &buffer[n * 24];

	for (int mask = 1 << 7; mask > 0; mask = mask >> 1) {
		if ((g & mask) > 0) {
			*p_buffer = CODE1;
		} else {
			*p_buffer = CODE0;
		}
		if ((r & mask) > 0) {
			*(p_buffer + 8) = CODE1;
		} else {
			*(p_buffer + 8) = CODE0;
		}
		if ((b & mask) > 0) {
			*(p_buffer + 16) = CODE1;
		} else {
			*(p_buffer + 16) = CODE0;
		}
		p_buffer++;
	}

}

void logo_copy_to_buffer(uint8_t *source, uint16_t size) {
	memcpy(buffer, source, size);
	logo_send();
}

uint8_t* logo_get_buffer(){
	return buffer;
}


//发送颜色数据
void logo_send() {
	logo_busy = true;
	R_SPI_Write(&g_spi0_ctrl, _buffer, sizeof(_buffer),
			SPI_BIT_WIDTH_8_BITS);
}
//同步发送颜色数据
void logo_send_sync() {
	logo_busy = true;
	R_SCI_SPI_Write(&g_spi1_ctrl, _buffer, sizeof(_buffer),
			SPI_BIT_WIDTH_8_BITS);
    while(logo_is_busy());
}

bool logo_is_busy(){
	return logo_busy;
}

//spi 事件回调
void sci_spi_callback(spi_callback_args_t *p_args) {
	if (SPI_EVENT_TRANSFER_COMPLETE == p_args->event) {
		logo_busy = false;
	}else{
		logo_busy = false;
	}
}
