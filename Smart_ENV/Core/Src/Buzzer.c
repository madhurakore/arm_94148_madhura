/*
 * Buzzer.c
 *
 *  Created on: Dec 30, 2025
 *      Author: shrey
 */



#include"Buzzer.h"
#define BUZZER_PORT   GPIOD
#define BUZZER_PIN    GPIO_PIN_14

void Buzzer_On(void)
{
    HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_SET);
}

void Buzzer_Off(void)
{
    HAL_GPIO_WritePin(BUZZER_PORT, BUZZER_PIN, GPIO_PIN_RESET);
}
void Buzzer_Toggle(void)
{
	HAL_GPIO_TogglePin(BUZZER_PORT,BUZZER_PIN);
}

