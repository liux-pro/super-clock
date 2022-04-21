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


void ws2812_init();
void ws2812_red();
void ws2812_copy_to_buffer(uint8_t* source,uint16_t size);
uint8_t* ws2812_get_buffer();
void ws2812_send();
bool ws2812_is_busy();
void sci_spi_callback(spi_callback_args_t *p_args);


#endif /* WS2812_H_ */
