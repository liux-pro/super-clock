/*
 * ws2812.c
 *
 *  Created on: 2022年4月21日
 *      Author: Legend
 *  spi 方式驱动 ws2812
 *  原理参考 http://bbs.mydigit.cn/read.php?tid=2622343
 */

#include <ws2812/ws2812.h>
#include <memory.h>

//使用硬件spi0控制ws2812
//从fsp中配置spi0，速率设为8M，MSB,并自动生成代码
//MOSI接ws2812

//LED 灯珠数量 不要超内存
#define LED_NUMBER 64
#define TOTAL   LED_NUMBER * 24

//buffer 显存 GRB888
uint8_t buffer[LED_NUMBER * 24] = { 0 };

//spi模拟0码 1100 0000
uint8_t CODE0 = 0XC0;
//spi模拟1码 1111 1100
uint8_t CODE1 = 0xFC;

//记录信号是否发完
volatile bool ws2812_busy = false;

fsp_err_t err;

//初始化串口，参数已经自动生成了，所以这里没参数
void ws2812_init() {
	//打开spi
	err = R_SPI_Open(&g_spi0_ctrl, &g_spi0_cfg);
	assert(FSP_SUCCESS == err);
	//初始化显存
	ws2812_black();
}

void ws2812_fill(uint8_t r, uint8_t g, uint8_t b) {
	for (uint16_t i = 0; i < LED_NUMBER; i++) {
		ws2812_set_color(i, r, g, b);
	}
}

void ws2812_red() {
	ws2812_fill(255, 0, 0);
}
void ws2812_green() {
	ws2812_fill(0, 255, 0);
}
void ws2812_blue() {
	ws2812_fill(0, 0, 255);
}
void ws2812_black() {
	ws2812_fill(0, 0, 0);
}

//void ws2812_fill_color(uint8_t r, uint8_t g, uint8_t b)
//{
//    for (uint16_t i = 0; i < LED_NUMBER; i++)
//    {
//
//    }
//}

void ws2812_set_color(uint16_t n, uint8_t r, uint8_t g, uint8_t b) {
	uint8_t *p_buffer = buffer+(n * 24);

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

void ws2812_copy_to_buffer(uint8_t *source, uint16_t size) {
	memcpy(buffer, source, size);
	ws2812_send();
}

//发送颜色数据
void ws2812_send() {
	ws2812_busy = true;
	err = R_SPI_Write(&g_spi0_ctrl, buffer, sizeof(buffer),
			SPI_BIT_WIDTH_8_BITS);
	assert(FSP_SUCCESS == err);
}
//同步发送颜色数据
void ws2812_send_sync() {
	ws2812_busy = true;
	err = R_SPI_Write(&g_spi0_ctrl, buffer, sizeof(buffer),
			SPI_BIT_WIDTH_8_BITS);
	assert(FSP_SUCCESS == err);
    while(ws2812_is_busy());
}

bool ws2812_is_busy(){
	return ws2812_busy;
}

//spi 事件回调
void spi_callback(spi_callback_args_t *p_args) {
	if (SPI_EVENT_TRANSFER_COMPLETE == p_args->event) {
		ws2812_busy = false;
	}else{
		ws2812_busy = false;
	}

}
