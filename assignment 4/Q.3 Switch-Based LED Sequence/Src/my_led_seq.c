/*
 * my_led.c
 *
 * Created on: Dec 17, 2025
 * Author: kiran_z6dopa8
 */

#include "my_led_seq.h"

void GPIO_Init(void)
{
    /* Enable GPIOA and GPIOD clock */
    RCC->AHB1ENR |= (1U << 0);   // GPIOA
    RCC->AHB1ENR |= (1U << 3);   // GPIOD

    /* PA0 as INPUT */
    GPIOA->MODER &= ~(3U << (0 * 2));

    /* Pull-down for PA0 */
    GPIOA->PUPDR &= ~(3U << (0 * 2));
    GPIOA->PUPDR |=  (2U << (0 * 2));

    /* PD12 and PD15 as OUTPUT */
    GPIOD->MODER &= ~(3U << (12 * 2));
    GPIOD->MODER |=  (1U << (12 * 2));

    GPIOD->MODER &= ~(3U << (15 * 2));
    GPIOD->MODER |=  (1U << (15 * 2));
}

uint8_t Read_Switch(void)
{
    return (GPIOA->IDR & (1U << 0)) ? 1 : 0;
}

void Green_LED_On(void)
{
    GPIOD->ODR |=  (1U << 12);   // Green ON
    GPIOD->ODR &= ~(1U << 15);  // Blue OFF
}

void Blue_LED_On(void)
{
    GPIOD->ODR |=  (1U << 15);  // Blue ON
    GPIOD->ODR &= ~(1U << 12);  // Green OFF
}

void All_LED_Off(void)
{
    GPIOD->ODR &= ~(1U << 12);
    GPIOD->ODR &= ~(1U << 15);
}
