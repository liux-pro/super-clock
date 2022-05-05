/*
 * utils.h
 *
 *  Created on: 2022年5月5日
 *      Author: Legend
 */

#ifndef UTILS_H_
#define UTILS_H_
void stop();
void stop(){
	while(1);
}
void get_random_number(uint8_t *  buffer, uint32_t bytes);
void get_random_number(uint8_t *  buffer, uint32_t bytes){
	static bool init = false;
    if(!init){
    	init=true;
    	RM_TINCYRYPT_PORT_Init();
    }
	RM_TINCYRYPT_PORT_TRNG_Read(buffer, bytes);
}



#endif /* UTILS_H_ */
