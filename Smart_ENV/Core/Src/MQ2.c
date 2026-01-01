/*
 * MQ2.c
 *
 *  Created on: Dec 30, 2025
 *      Author: shrey
 */


#include"main.h"
#include"MQ2.h"
#include"my_lcd.h"
#include "my_led.h"
#include "Buzzer.h"
#include<stdio.h>
#include<string.h>
#include "stm32f4xx_hal.h"
#define SMOKE_THRESHOLD  500

void smoke_moniter_task(void){
	uint32_t sum = 0;
	uint32_t adc_val = 0;
	char lcd_buf[16];

	for(int i=0;i<10;i++){
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1,HAL_MAX_DELAY);
		sum+= HAL_ADC_GetValue(&hadc1);
		HAL_ADC_Stop(&hadc1);
		HAL_Delay(5);

	}
 adc_val = sum / 10;

 lcd16x2_i2c_clear();
 if(adc_val > SMOKE_THRESHOLD){
	 LED_On();
	 Buzzer_Toggle();
	 lcd16x2_i2c_setCursor(0, 0);
	 lcd16x2_i2c_printf("SMOKE DETECTED");

	 sprintf(lcd_buf,"ADC:%1u",adc_val);
	 lcd16x2_i2c_setCursor(1, 0);
	 lcd16x2_i2c_printf(lcd_buf);
 }
 else{
	     LED_Off();
	     Buzzer_Off();
		 lcd16x2_i2c_setCursor(0, 0);
		 lcd16x2_i2c_printf("AIR NORMAL");

		 sprintf(lcd_buf,"ADC:%1u",adc_val);
		 lcd16x2_i2c_setCursor(1, 0);
		 lcd16x2_i2c_printf(lcd_buf);
 }

}



