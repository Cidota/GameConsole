/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_ll_crs.h"
#include "stm32l4xx_ll_rcc.h"
#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_system.h"
#include "stm32l4xx_ll_exti.h"
#include "stm32l4xx_ll_cortex.h"
#include "stm32l4xx_ll_utils.h"
#include "stm32l4xx_ll_pwr.h"
#include "stm32l4xx_ll_dma.h"
#include "stm32l4xx_ll_usart.h"
#include "stm32l4xx_ll_gpio.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B0_Pin LL_GPIO_PIN_13
#define B0_GPIO_Port GPIOC
#define LCD_RST_A4_Pin LL_GPIO_PIN_1
#define LCD_RST_A4_GPIO_Port GPIOC
#define LCD_RD_A0_Pin LL_GPIO_PIN_0
#define LCD_RD_A0_GPIO_Port GPIOA
#define LCD_WR_A1_Pin LL_GPIO_PIN_1
#define LCD_WR_A1_GPIO_Port GPIOA
#define USART_TX_Pin LL_GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin LL_GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LCD_RS_A2_Pin LL_GPIO_PIN_4
#define LCD_RS_A2_GPIO_Port GPIOA
#define B3_Pin LL_GPIO_PIN_5
#define B3_GPIO_Port GPIOC
#define LCD_CS_A3_Pin LL_GPIO_PIN_0
#define LCD_CS_A3_GPIO_Port GPIOB
#define B7_Pin LL_GPIO_PIN_1
#define B7_GPIO_Port GPIOB
#define B8_Pin LL_GPIO_PIN_2
#define B8_GPIO_Port GPIOB
#define LCD_D6_D6_Pin LL_GPIO_PIN_10
#define LCD_D6_D6_GPIO_Port GPIOB
#define B2_Pin LL_GPIO_PIN_6
#define B2_GPIO_Port GPIOC
#define LCD_D1_D9_Pin LL_GPIO_PIN_7
#define LCD_D1_D9_GPIO_Port GPIOC
#define B1_Pin LL_GPIO_PIN_8
#define B1_GPIO_Port GPIOC
#define B6_Pin LL_GPIO_PIN_9
#define B6_GPIO_Port GPIOC
#define LCD_D7_D7_Pin LL_GPIO_PIN_8
#define LCD_D7_D7_GPIO_Port GPIOA
#define LDC_D0_D8_Pin LL_GPIO_PIN_9
#define LDC_D0_D8_GPIO_Port GPIOA
#define LCD_D2_D2_Pin LL_GPIO_PIN_10
#define LCD_D2_D2_GPIO_Port GPIOA
#define B5_Pin LL_GPIO_PIN_11
#define B5_GPIO_Port GPIOA
#define B4_Pin LL_GPIO_PIN_12
#define B4_GPIO_Port GPIOA
#define TMS_Pin LL_GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin LL_GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LCD_D3_D3_Pin LL_GPIO_PIN_3
#define LCD_D3_D3_GPIO_Port GPIOB
#define LCD_D5_D5_Pin LL_GPIO_PIN_4
#define LCD_D5_D5_GPIO_Port GPIOB
#define LCD_D4_D4_Pin LL_GPIO_PIN_5
#define LCD_D4_D4_GPIO_Port GPIOB
#ifndef NVIC_PRIORITYGROUP_0
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
                                                                 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
                                                                 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
                                                                 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
                                                                 1 bit  for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
                                                                 0 bit  for subpriority */
#endif
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
