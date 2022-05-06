/*
 * debug.cpp
 *
 *  Created on: 2022年4月22日
 *      Author: Legend
 */

#include "debug.h"
#include <stdarg.h>
#include <stdio.h>
#define DEBUG_BUFFER_SIZE 100

volatile bool debug_busy = false;
static void debug_init();

uint8_t receive_buff[DEBUG_BUFFER_SIZE];
volatile uint8_t length = 0;
volatile uint8_t index = 0;

void debug(const char *fmt, ...) {
	//自动初始化
	debug_init();
	//参考https://www.ibm.com/docs/en/zos/2.1.0?topic=functions-vsprintf-format-print-data-buffer
	va_list arg_ptr;
	va_start(arg_ptr, fmt);
	static unsigned char send_buff[DEBUG_BUFFER_SIZE];
	vsprintf((char*) send_buff, fmt, arg_ptr);
	uint32_t len = strlen((char*) send_buff);
	debug_busy = true;
	R_SCI_UART_Write(&g_uart0_ctrl, send_buff, len);
	while(debug_busy);
	va_end(arg_ptr);
}
static void debug_init(){
	bool init = false;
	if(!init){
		init=true;
		R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);
	}
}
//感觉这么没啥用 先不管他
void user_uart_callback(uart_callback_args_t *p_args) {
	if (p_args->event == UART_EVENT_TX_COMPLETE) {
		debug_busy=false;
	}
	if (p_args->event == UART_EVENT_RX_CHAR) {
		receive_buff[index++]=p_args->data;
	}
}
