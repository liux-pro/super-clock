/*
 * ws2812.c
 *
 *  Created on: 2022年4月21日
 *      Author: Legend
 */
/*
 *  spi 方式驱动 ws2812
 *  原理参考 http://bbs.mydigit.cn/read.php?tid=2622343
 */
#include <ws2812/ws2812.h>
#include <memory.h>

//使用硬件spi0控制ws2812
//从fsp中配置spi0，速率设为8M，MSB,并自动生成代码
//MOSI接ws2812
//横纵数量，左下角开始向右蛇形排列
#define LED_X_NUMBER 8
#define LED_Y_NUMBER 8

//LED 灯珠数量 不要超内存
#define LED_NUMBER LED_X_NUMBER * LED_Y_NUMBER
#define TOTAL   LED_NUMBER * 24

//buffer 显存 GRB888
static uint8_t buffer[LED_NUMBER * 24] = { 0 };

//spi模拟0码 1100 0000
static uint8_t CODE0 = 0XC0;
//spi模拟1码 1111 1100
static uint8_t CODE1 = 0xFC;

//记录信号是否发完
volatile bool ws2812_busy = false;

static fsp_err_t ws2812_err;

//初始化spi，参数已经自动生成了，所以这里没参数
void ws2812_init() {
	//打开spi
	ws2812_err = R_SPI_Open(&g_spi0_ctrl, &g_spi0_cfg);
	assert(FSP_SUCCESS == ws2812_err);
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
//xy坐标转led编号 //	蛇形排列
uint16_t ws2812_xy_to_n(uint8_t x, uint8_t  y){
	uint16_t n;
	if(y%2==0){
        n=(uint16_t)(y*LED_X_NUMBER+x);
	}else{
//		y%2==1
        n=(uint16_t)((y+1)*LED_X_NUMBER-x-1);
	}
	return n;
}
void ws2812_set_color_xy(uint8_t x, uint8_t  y, uint8_t r, uint8_t g, uint8_t b) {
	uint16_t n = ws2812_xy_to_n(x ,  y);
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

void ws2812_copy_to_buffer(uint8_t *source, uint16_t size) {
	memcpy(buffer, source, size);
	ws2812_send();
}

uint8_t* ws2812_get_buffer(){
	return buffer;
}


//发送颜色数据
void ws2812_send() {
	ws2812_busy = true;
	ws2812_err = R_SPI_Write(&g_spi0_ctrl, buffer, sizeof(buffer),
			SPI_BIT_WIDTH_8_BITS);
	assert(FSP_SUCCESS == ws2812_err);
}
//同步发送颜色数据
void ws2812_send_sync() {
	ws2812_busy = true;
	ws2812_err = R_SPI_Write(&g_spi0_ctrl, buffer, sizeof(buffer),
			SPI_BIT_WIDTH_8_BITS);
	assert(FSP_SUCCESS == ws2812_err);
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
