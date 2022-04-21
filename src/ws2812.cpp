/*
 * ws2812.c
 *
 *  Created on: 2022年4月21日
 *      Author: Legend
 *  spi 方式驱动 ws2812
 *  原理参考 http://bbs.mydigit.cn/read.php?tid=2622343
 */

#include <ws2812.h>
#include <memory.h>

//使用硬件spi0控制ws2812
//从fsp中配置spi0，速率设为8M，MSB,并自动生成代码
//MOSI接ws2812



//LED 灯珠数量 不要超内存
#define LED_NUMBER 64
#define TOTAL = LED_NUMBER * 24

//buffer 显存 GRB888
uint8_t buffer[LED_NUMBER*24] = {0};


//spi模拟0码 1100 0000
uint8_t CODE0 = 0XC0;
//spi模拟1码 1111 1100
uint8_t CODE1 = 0xFC;

//记录信号是否发完
bool ws2812_busy = false;

fsp_err_t err;

//初始化串口，参数已经自动生成了，所以这里没参数
void ws2812_init()
{
    //打开spi
    err = R_SPI_Open (&g_spi0_ctrl, &g_spi0_cfg);
    assert (FSP_SUCCESS == err);
}

void ws2812_red()
{


}

void ws2812_copy_to_buffer(uint8_t* source,uint16_t size)
{
    memcpy(buffer,source,size);
    ws2812_send();
}

uint8_t* ws2812_get_buffer()
{
    return buffer;
}

void ws2812_send()
{
    err = R_SPI_Write (&g_spi0_ctrl, buffer, sizeof(buffer), SPI_BIT_WIDTH_8_BITS);
    assert (FSP_SUCCESS == err);
}
//掉这个函数检查spi是否发完
bool ws2812_is_busy(){
    return ws2812_busy;
}

//spi 事件回调
void spi_callback(spi_callback_args_t *p_args)
{
    if (SPI_EVENT_TRANSFER_COMPLETE == p_args->event)
    {
        ws2812_busy = true;
    }
    else
    {
        /* Updating the flag here to capture and handle all other error events */
        ws2812_busy = true;
    }
}
