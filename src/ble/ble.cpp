/*
 * ble.cpp
 *
 *  Created on: 2022年5月7日
 *      Author: Legend
 */
/*
 * 通过串口与蓝牙芯片ch571k通讯。
 *
 *
 * 定时器超时时间设为n毫秒（这里实际设置为n=1），超时后计时器自动停止（瑞萨称为one-shot模式）。
 *
 * 串口接收数据时，收到第一个数据时启动定时器，以后只要接到数据，
 * 就重置定时器，保证定时器在接收数据时一直不会溢出。
 * 超过n毫秒没收到数据后，定时器就会溢出进到定时器中断。
 * 代表接收完成。
 * sci channel 1
 * TXD P213
 * RXD P212
 * 115200Hz
 */

#include "ble.h"
#include "debug/debug.h"

//定义缓冲区大小，256字节+1个校验位
#define BLE_RECEIVE_BUFFER (256+1)
#define BLE_SEND_BUFFER (256+1)


uint8_t ble_receive_buffer[BLE_RECEIVE_BUFFER];
uint8_t ble_send_buffer[BLE_SEND_BUFFER];

volatile bool ble_busy = false;

volatile bool ble_receiving = false;
volatile uint16_t ble_receive_count = 0;

volatile bool ble_received = false;


uint8_t calc_xor(uint8_t* data,uint16_t len);

void ble_send(uint8_t*buffer,uint16_t len) {
	if(buffer!=ble_send_buffer){
		memcpy(ble_send_buffer,buffer,len);
	}
	ble_send_buffer[len]=calc_xor(ble_send_buffer,len);
	R_SCI_UART_Write(&uart1_ble_ctrl, ble_send_buffer, len+1);
}

void ble_send_sync(uint8_t*buffer,uint16_t len) {
	ble_busy = true;
	ble_send(buffer,len);
	while(ble_busy);
}

void ble_init(){
	//初始化串口。
	R_SCI_UART_Open(&uart1_ble_ctrl, &uart1_ble_cfg);
	//初始化定时器
	R_GPT_Open(&gpt5_uart1_timeout_ctrl, &gpt5_uart1_timeout_cfg);
}

void gpt5_callback(timer_callback_args_t *p_args) {
	if (TIMER_EVENT_CYCLE_END == p_args->event) {
	   //标记接收完成
	   ble_receiving = false;
	   //进行异或校验。
	   //发的时候把所有数据异或运算结果拼在数据最后
	   //校验的时候把所有数据和校验值一起异或，结果应该是0
       if(calc_xor(ble_receive_buffer,ble_receive_count)==0){
    	   ble_received=true;
       }

	}
}


//主循环轮询获取数据。
bool ble_get_data(uint8_t **buffer,uint16_t *len) {
	if (ble_received) {
		//被读取后自动清除标志
		ble_received = false;
		*buffer = ble_receive_buffer;
		//减去校验位。
		*len = ble_receive_count -1;
		return true;
	};
	return false;
}


void uart1_callback(uart_callback_args_t *p_args) {
	//发送成功
	if (p_args->event == UART_EVENT_TX_COMPLETE) {
		ble_busy=false;
	}
	//收到一个字节
	if (p_args->event == UART_EVENT_RX_CHAR) {
		if(ble_receiving){    //正在接收，以前已经收到过数据了
			//能到这里接收计数应该大于0
			//接收不能超过缓冲区。
			if(ble_receive_count>0 &&
					ble_receive_count<BLE_RECEIVE_BUFFER){
				ble_receive_buffer[ble_receive_count++]=(uint8_t)p_args->data;
				//重置定时器
				R_GPT_Reset(&gpt5_uart1_timeout_ctrl);
			}else{
				//正常应该不会走到这里
				//除非发的数据超长，挤爆buffer
				ble_receiving=false;
				ble_receive_count=0;
				R_GPT_Stop(&gpt5_uart1_timeout_ctrl);
			}
		}else{       //收到第一个数据
			//标记数据接收开始。
			ble_receiving=true;
			//开启定时器
			R_GPT_Start(&gpt5_uart1_timeout_ctrl);
			//不太清除会不会自动reset，所以加上保险点。
			R_GPT_Reset(&gpt5_uart1_timeout_ctrl);
			//初始化接收计数器
			ble_receive_count=0;
		    //保存这第一个数据到缓冲区
			ble_receive_buffer[ble_receive_count++]=(uint8_t)p_args->data;
		}

	}
}

//异或校验
uint8_t calc_xor(uint8_t* data,uint16_t len){
	uint8_t result = data[0];
	for(uint16_t i=1;i<len;i++){
		result^=data[i];
	}
	return result;
}
