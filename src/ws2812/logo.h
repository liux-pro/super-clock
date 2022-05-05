/*
 * logo.h
 *
 *  Created on: 2022年5月5日
 *      Author: Legend
 */

#ifndef LOGO_LOGO_H_
#define LOGO_LOGO_H_
#include "hal_data.h"
#include "debug/debug.h"

void logo_init();
void logo_fill(uint8_t r, uint8_t g, uint8_t b);
void logo_red();
void logo_green();
void logo_blue();
void logo_black();
void logo_set_color(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
void logo_copy_to_buffer(uint8_t *source, uint16_t size);
uint8_t* logo_get_buffer();
//发送颜色数据
void logo_send();
//同步发送颜色数据
void logo_send_sync();
bool logo_is_busy();
#endif /* LOGO_LOGO_H_ */
