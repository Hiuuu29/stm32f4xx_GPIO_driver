/*
 * stm32f407xx.h
 *
 *  Created on: Feb 24, 2025
 *      Author: Huynh Trung Hieu
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

/*
 * BASE ADDRESS
 * using RM0090 Reference Manual Stm32F407
 * the page will be mention in the following macros
 * */

#define BASE_FLASH 		0x08000000U 		// 75
#define BASE_SRAM1 		0x20000000U			// 68
#define BASE_SRAM 		BASE_SRAM1 			// 75
#define ROM 		 	0x1FFF0000  		// 75
#define OTP 		 	0x1FFF7800  		// 75

/*
 * TABLE 1: PAGE 65 TO 67
 * Define all base address for FUTURE USE
 * */
#define BASE_RNG 		0x50060800U
#define BASE_HASH 		0x50060400U
#define BASE_CRYP 		0x50060000U
#define BASE_DCMI 		0x50050000U
#define BASE_USB_OTG_FS 0x50000000U
#define BASE_USB_OTG_HS 0x40040000U
#define BASE_DMA2D 		0x4002B000U
#define BASE_ETHERNET_MAC 				0x40028000U
#define BASE_DMA2 		0x40026400U
#define BASE_DMA1 		0x40026000U
#define BASE_BKPSRAM 	0x40024000U
#define BASE_FLASH_INTERFACE_REGISTER 	0x40023C00U
#define BASE_RCC 		0x40023800U
#define BASE_CRC 		0x40023000U
#define BASE_GPIOK 		0x40022800U
#define BASE_GPIOJ 		0x40022400U
#define BASE_GPIOI 		0x40022000U
#define BASE_GPIOH 		0x40021C00U
#define BASE_GPIOG 		0x40021800U
#define BASE_GPIOF 		0x40021400U
#define BASE_GPIOE 		0x40021000U
#define BASE_GPIOD 		0x40020C00U
#define BASE_GPIOC 		0x40020800U
#define BASE_GPIOB 		0x40020400U
#define BASE_GPIOA 		0x40020000U
#define BASE_LCD_TFT 	0x40016800U
#define BASE_SAI1 		0x40015800U
#define BASE_SPI6 		0x40015400U
#define BASE_SPI5 		0x40015000U

#define BASE_TIM11         0x40014800U
#define BASE_TIM10         0x40014400U
#define BASE_TIM9          0x40014000U
#define BASE_EXTI          0x40013C00U
#define BASE_SYSCFG        0x40013800U
#define BASE_SPI4          0x40013400U
#define BASE_SPI1          0x40013000U
#define BASE_SDIO          0x40012C00U
#define BASE_ADC1_ADC2_ADC3 0x40012000U
#define BASE_USART6        0x40011400U
#define BASE_USART1        0x40011000U
#define BASE_TIM8          0x40010400U
#define BASE_TIM1          0x40010000U
#define BASE_UART8         0x40007C00U
#define BASE_UART7         0x40007800U

#define BASE_DAC          0x40007400U
#define BASE_PWR          0x40007000U
#define BASE_CAN2         0x40006800U
#define BASE_CAN1         0x40006400U
#define BASE_I2C3         0x40005C00U
#define BASE_I2C2         0x40005800U
#define BASE_I2C1         0x40005400U
#define BASE_UART5        0x40005000U
#define BASE_UART4        0x40004C00U
#define BASE_USART3       0x40004800U
#define BASE_USART2       0x40004400U
#define BASE_I2S3EXT      0x40004000U
#define BASE_SPI3_I2S3    0x40003C00U
#define BASE_SPI2_I2S2    0x40003800U
#define BASE_I2S2EXT      0x40003400U
#define BASE_IWDG         0x40003000U
#define BASE_WWDG         0x40002C00U
#define BASE_RTC_BKP      0x40002800U
#define BASE_TIM14        0x40002000U
#define BASE_TIM13        0x40001C00U
#define BASE_TIM12        0x40001800U
#define BASE_TIM7         0x40001400U
#define BASE_TIM6         0x40001000U
#define BASE_TIM5         0x40000C00U
#define BASE_TIM4         0x40000800U
#define BASE_TIM3         0x40000400U
#define BASE_TIM2         0x40000000U






#endif /* INC_STM32F407XX_H_ */
