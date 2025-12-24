/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : UART Command Based LED Control (Polling)
  ******************************************************************************
  */
 /* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <string.h>

/* USER CODE BEGIN Includes */
#define MAX_LEN 100
uint8_t rx_byte;
char rx_buffer[MAX_LEN];
uint16_t rx_index = 0;
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);

/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  /* Welcome message */
  char msg[] = "UART LED Control Ready\r\n";
  HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

  while (1)
  {
    /* Receive one byte (polling) */
    HAL_UART_Receive(&huart2, &rx_byte, 1, HAL_MAX_DELAY);

    /* Echo */
    HAL_UART_Transmit(&huart2, &rx_byte, 1, HAL_MAX_DELAY);

    /* ENTER key */
    if (rx_byte == '\r')
    {
      rx_buffer[rx_index] = '\0';

      char newline[] = "\r\n";
      HAL_UART_Transmit(&huart2, (uint8_t*)newline, strlen(newline), HAL_MAX_DELAY);

      /* Command processing */
      if (strcmp(rx_buffer, "LED_RED") == 0)
      {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
      }
      else if (strcmp(rx_buffer, "LED_ORANGE") == 0)
      {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
      }
      else
      {
        char invalid[] = "Invalid Command\r\n";
        HAL_UART_Transmit(&huart2, (uint8_t*)invalid, strlen(invalid), HAL_MAX_DELAY);
      }

      rx_index = 0;
    }
    else
    {
      if (rx_index < MAX_LEN - 1)
      {
        rx_buffer[rx_index++] = rx_byte;
      }
    }
  }
}

/* ---------------- Clock Config ---------------- */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 50;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;

  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                               RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);
}

/* ---------------- USART2 Init ---------------- */
static void MX_USART2_UART_Init(void)
{
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart2);
}

/* ---------------- GPIO Init ---------------- */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOD_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
}

/* ---------------- Error Handler ---------------- */
void Error_Handler(void)
{
  __disable_irq();
  while (1) {}
}
