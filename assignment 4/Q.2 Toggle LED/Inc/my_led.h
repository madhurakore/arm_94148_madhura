/*
 * my_led.h
 *
 *  Created on: Dec 17, 2025
 *      Author: kiran_z6dopa8
 */

#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx.h"
#include <stdint.h>

void GPIO_Init(void);
uint8_t Read_Switch(void);
void LED_Toggle(void);

#endif

