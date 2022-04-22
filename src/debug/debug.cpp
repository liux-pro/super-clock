/*
 * debug.cpp
 *
 *  Created on: 2022年4月22日
 *      Author: Legend
 */

#include "debug.h"
#include <stdarg.h>
#include <stdio.h>

void debug(const char *fmt, ...) {
	//参考https://www.ibm.com/docs/en/zos/2.1.0?topic=functions-vsprintf-format-print-data-buffer
	va_list arg_ptr;
	va_start(arg_ptr, fmt);
	static unsigned char send_buff[100];
	vsprintf((char*) send_buff, fmt, arg_ptr);
	uint8_t len = strlen((char*) send_buff);
	R_SCI_UART_Write(&g_uart0_ctrl, send_buff, len);
	va_end(arg_ptr);
}
void debug_init(){
	R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);
}
//感觉这么没啥用 先不管他
void user_uart_callback(uart_callback_args_t *p_args) {
	if (p_args->event == UART_EVENT_TX_COMPLETE) {
	}
}
