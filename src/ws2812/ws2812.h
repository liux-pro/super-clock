/*
 * ws2812.h
 *
 *  Created on: 2022年4月21日
 *      Author: Legend
 */

#ifndef WS2812_H_
#define WS2812_H_

#include "hal_data.h"
#include <stdint.h>
#include <stdint.h>

extern volatile bool ws2812_busy;


void ws2812_init();
void ws2812_set_color(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
void ws2812_fill(uint8_t r, uint8_t g, uint8_t b);
void ws2812_red();
void ws2812_green();
void ws2812_blue();
void ws2812_black();
void ws2812_copy_to_buffer(uint8_t* source,uint16_t size);
uint8_t* ws2812_get_buffer();
bool ws2812_is_busy();
void ws2812_send();
void ws2812_send_sync();
void sci_spi_callback(spi_callback_args_t *p_args);


#endif /* WS2812_H_ */
