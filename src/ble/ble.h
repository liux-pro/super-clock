/*
 * ble.h
 *
 *  Created on: 2022年5月7日
 *      Author: Legend
 */

#ifndef BLE_BLE_H_
#define BLE_BLE_H_
#include "hal_data.h"

void ble_init();
void ble_send(uint8_t*buffer,uint16_t len);
void ble_send_sync(uint8_t*buffer,uint16_t len);
bool ble_get_data(uint8_t **buffer,uint16_t *len);

#endif /* BLE_BLE_H_ */
