/*
 * my_led.c
 *
 *  Created on: Dec 30, 2025
 *      Author: shrey
 */

#include "my_led.h"

#define LED_PORT   GPIOD
#define LED_PIN    GPIO_PIN_15


void LED_On(void)
{
    HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
}

void LED_Off(void)
{
    HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
}


