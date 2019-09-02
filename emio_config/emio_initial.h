/*
 * emio_initial.h
 *
 *  Created on: 2016Äê10ÔÂ22ÈÕ
 *      Author: Administrator
 */
#include"xgpiops.h"

#ifndef EMIO_INITIAL_H_
#define EMIO_INITIAL_H_


int Miz702_EMIO_init(void);
//I2C
#define SCL_PIN1 54
#define SDA_PIN1 55
#define SCL_PIN2 56
#define SDA_PIN2 57
#define SCL_PIN3 58
#define SDA_PIN3 59
#define SCL_PIN4 60
#define SDA_PIN4 61
#define DIRECTION_INPUT 5
#define DIRECTION_OUTPUT 1

void CLOCK_HIGH(u8 Channel);

void CLOCK_LOW(u8 Channel);

void DATA_HIGH(u8 Channel);

void DATA_LOW(u8 Channel);

#endif /* EMIO_INITIAL_H_ */
