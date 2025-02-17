/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.c
  * @brief   This file provides code for the configuration
  *          of the USART instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */

#include "cli.h"

#define UART_BUF_SIZE 256
#define BACK_SPACE    "\b \b"

uint8_t uart3_rx_buf[UART_BUF_SIZE];
volatile uint16_t uart3_rx_idx = 0;

volatile bool cmd_ready = false;
char cmd_buf[UART_BUF_SIZE];

int _write(int file, char *ptr, int len)
{
  HAL_UART_Transmit(&huart3, (uint8_t*)ptr, len, HAL_MAX_DELAY);
  return len;
}

/* USER CODE END 0 */

UART_HandleTypeDef huart3;

/* USART3 init function */

void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */
  HAL_UART_Receive_IT(&huart3, &uart3_rx_buf[uart3_rx_idx], 1);
  /* USER CODE END USART3_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspInit 0 */

  /* USER CODE END USART3_MspInit 0 */
    /* USART3 clock enable */
    __HAL_RCC_USART3_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    GPIO_InitStruct.Pin = STLK_RX_Pin|STLK_TX_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USART3 interrupt Init */
    HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspInit 1 */

  /* USER CODE END USART3_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART3)
  {
  /* USER CODE BEGIN USART3_MspDeInit 0 */

  /* USER CODE END USART3_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART3_CLK_DISABLE();

    /**USART3 GPIO Configuration
    PB10     ------> USART3_TX
    PB11     ------> USART3_RX
    */
    HAL_GPIO_DeInit(GPIOB, STLK_RX_Pin|STLK_TX_Pin);

    /* USART3 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USART3_IRQn);
  /* USER CODE BEGIN USART3_MspDeInit 1 */

  /* USER CODE END USART3_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if (huart->Instance == USART3)
  {
    {
      if (uart3_rx_buf[uart3_rx_idx] == '\n' || uart3_rx_buf[uart3_rx_idx] == '\r')
      {
        uart3_rx_buf[uart3_rx_idx] = '\0';
        uart3_rx_idx = 0;
        
        cmd_ready = true;
        strcpy(cmd_buf, (char*)uart3_rx_buf);
      }
      else if (uart3_rx_buf[uart3_rx_idx] == '\b')
      {
        uart3_rx_buf[uart3_rx_idx] = '\0';
        // printf("\b \b");
        HAL_UART_Transmit(&huart3, (uint8_t*)BACK_SPACE, 3, HAL_MAX_DELAY);
        uart3_rx_idx = (uart3_rx_idx - 1) % UART_BUF_SIZE;
      }
      else
      {
        HAL_UART_Transmit(&huart3, &uart3_rx_buf[uart3_rx_idx], 1, HAL_MAX_DELAY);
        // printf("%c", &uart3_rx_buf[uart3_rx_idx]);
        uart3_rx_idx = (uart3_rx_idx + 1) % UART_BUF_SIZE;
      }
      HAL_UART_Receive_IT(&huart3, &uart3_rx_buf[uart3_rx_idx], 1);
    } 
  }
}

void uart_check_cmd_recv(void)
{
  if (cmd_ready)
  {
    cmd_ready = false;
    cli_process(cmd_buf);
  }
}

/* USER CODE END 1 */
