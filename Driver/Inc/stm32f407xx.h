/*
 * stm32f407xx.h
 *
 *  Created on: Feb 24, 2025
 *      Author: Huynh Trung Hieu
 *		MCU SPECIFICS DATA
 */
#include<stdint.h>

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#define __vo volatile

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

//----------------------------------------- FOR Stm32F407 MCU ONLY-----------------------------
/*
 * TABLE 1: PAGE 65 TO 67
 * Define all base address of peripheral for FUTURE USE
 * NOTE*** : IN BIG PROJECT THEY USUALLY ADD SUFFIX IN MACRO
 * 			 EX : HAL_BASE_RNG OR LL_BASE_RNG
 * 			 DOING THIS PREVENT CONFICT FROM ORTHER FILE
 * 		IM DOING THIS PROJECT ALONE SO THESE MACROS IT FINE ENOUGH
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
//#define BASE_GPIOK 		0x40022800U
//#define BASE_GPIOJ 		0x40022400U
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



////----------------------------------------- FLEXIBILITY FOR ALL MCU -----------------------------
////// DEFINE THE BASE OF BUS PERIPHERAL THEN CALCULATE PERIPHERAL BY
////// BASE_PERIPHERAL + OFFSET
///*
// * ------STEP 1 : Define all base address of BUS PERIPHERAL BASE ----------------
// * TABLE 1: PAGE 65 TO 67
// * */
//#define BASE_AHB1         		0x40020000U
//
///*
// * ------STEP 2 : Define all base address of PERIPHERAL ----------------
// * TABLE 1: PAGE 65 TO 67
// * Using addition document RM1472 to check STM32F407VGT6 BLOCK DIAGRAM
// * Page 12 / RM1472 to view what peripheral connect to the following bus
// * */
//// In this case of STM32F407VGT6 GPIO A to I all connect to AHB1 BUS
//
//#define GPIOA_BASE				(BASE_AHB1 + 0X0000) // 0X00 IS OFFSET CHECK TABLE 1 FOR MORE INFO



////----------------------------------------- DEFINE ALL GPIO REG -----------------------------
/*
 * DOCUMENT RM0090 PAGE 284 - 291, 8.4 GPIO REGISTER
 * WHEN HAVE THE BASE OF GPIOx EX: GPIOA, IN GPIOA HAVE VARIOUS REGISTER LIKE MODE, SPEED, OUTPUT
 * HAVE TO DEFINE THEM USING BASE_GPIO + OFFSET but in A MCU THERE ARE A LOT OF REGISTER LIKE THIS
 * SO THE BETTER WAY IS USING A C STRUCTURE
 * */

/*
 * PERIPHERAL REGISTER DEFINITION STRUCT FOR GPIO
 * RM0090 page 284 - 291
 * */
typedef struct
{
	__vo uint32_t MODER;    // Address offset: 0x00 -> Chế độ của các chân GPIO
	__vo uint32_t OTYPER;   // Address offset: 0x04 -> Cấu hình kiểu output (push-pull/open-drain)
	__vo uint32_t OSPEEDR;  // Address offset: 0x08 -> Cấu hình tốc độ output
	__vo uint32_t PUPDR;    // Address offset: 0x0C -> Cấu hình pull-up/pull-down
	__vo uint32_t IDR;      // Address offset: 0x10 -> Đọc giá trị input
	__vo uint32_t ODR;      // Address offset: 0x14 -> Ghi giá trị output
	__vo uint16_t BSRRL;    // Address offset: 0x18 -> Đặt bit output (low)
	__vo uint16_t BSRRH;    // Address offset: 0x1A -> Đặt bit output (high)
	__vo uint32_t LCKR;     // Address offset: 0x1C -> Khóa cấu hình GPIO
	__vo uint32_t AFR[2];   // Address offset: 0x20-0x24 -> Alternate function (AFR[0] cho pin 0-7, AFR[1] cho pin 8-15)
} GPIO_RegDef_t;


/*
 * PERIPHERAL REGISTER DEFINITION STRUCT FOR RCC (RCC IS NEEDED WHEN USING GPIO)
 * RM0090 page 212 - 214
 * */

typedef struct
{
	__vo uint32_t CR;    			// Address offset: 0x00
	__vo uint32_t PLLCFGR;  		// Address offset: 0x04
	__vo uint32_t CFGR;  			// Address offset: 0x08
	__vo uint32_t CIR;    			// Address offset: 0x0C
	__vo uint32_t AHB1RSTR;      	// Address offset: 0x10
	__vo uint32_t AHB2RSTR;      	// Address offset: 0x14
	__vo uint32_t AHB3RSTR;    		// Address offset: 0x18

	__vo uint32_t APB1RSTR;    		// Address offset: 0x20
	__vo uint32_t APB2RSTR;     	// Address offset: 0x24

	__vo uint32_t AHB1ENR;   		// Address offset: 0x30
	__vo uint32_t AHB2ENR;   		// Address offset: 0x34
	__vo uint32_t AHB3ENR;   		// Address offset: 0x38

	__vo uint32_t APB1ENR;   		// Address offset: 0x40
	__vo uint32_t APB2ENR;   		// Address offset: 0x44

	__vo uint32_t AHB1LPENR; 		// Address offset: 0x50
	__vo uint32_t AHB2LPENR;   		// Address offset: 0x54
	__vo uint32_t AHB3LPENR;   		// Address offset: 0x58

	__vo uint32_t APB1LPENR;   		// Address offset: 0x60
	__vo uint32_t APB2LPENR;   		// Address offset: 0x64

	__vo uint32_t BDCR;   			// Address offset: 0x70
	__vo uint32_t CSR;   			// Address offset: 0x74

	__vo uint32_t SSCGR;   			// Address offset: 0x80
	__vo uint32_t PLLI2SCFGR;   	// Address offset: 0x84
	__vo uint32_t PLLSAICFGR;   	// Address offset: 0x88
	__vo uint32_t DCKCFGR;   		// Address offset: 0x8C
} RCC_RegDef_t;

/*
 * type cast the GPIO base address
 * */

#define GPIOA			((GPIO_RegDef_t*)BASE_GPIOA)
#define GPIOB			((GPIO_RegDef_t*)BASE_GPIOB)
#define GPIOC			((GPIO_RegDef_t*)BASE_GPIOC)
#define GPIOD			((GPIO_RegDef_t*)BASE_GPIOD)
#define GPIOE			((GPIO_RegDef_t*)BASE_GPIOE)
#define GPIOF			((GPIO_RegDef_t*)BASE_GPIOF)
#define GPIOG			((GPIO_RegDef_t*)BASE_GPIOG)
#define GPIOH			((GPIO_RegDef_t*)BASE_GPIOH)
#define GPIOI			((GPIO_RegDef_t*)BASE_GPIOI)
#define GPIOJ			((GPIO_RegDef_t*)BASE_GPIOJ)
#define GPIOK			((GPIO_RegDef_t*)BASE_GPIOK)

#define RCC				((RCC_RegDef_t*)BASE_RCC)

//------------------------------------------ ENABLE CLOCK ----------------------------------------
/*
 * Using Peripherals like GPIO, I2C, SPI NEED CLOCK SO, IT NECESSARY TO ENABLE IT
 * */

/*
 * Enable clock for GPIOx
 * REFER TO RM0090 page 182		AHB1 BUS
 * */
#define GPIOA_CLK_EN			(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_CLK_EN			(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_CLK_EN			(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_CLK_EN			(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_CLK_EN			(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_CLK_EN			(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_CLK_EN			(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_CLK_EN			(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_CLK_EN			(RCC->AHB1ENR |= (1 << 8))

/*
 * Enable clock for I2Cx
 * REFER TO RM0090  -  APB1 BUS
 * */
#define I2C1_CLK_EN			(RCC->APB1ENR |= (1 << 21))
#define I2C2_CLK_EN			(RCC->APB1ENR |= (1 << 22))
#define I2C3_CLK_EN			(RCC->APB1ENR |= (1 << 23))

/*
 * Enable clock for SPIx
 * REFER TO RM0090  -  APB1 BUS, APB2 BUS
 * */
#define SPI1_CLK_EN			(RCC->APB2ENR |= (1 << 12))// APB2
#define SPI2_CLK_EN			(RCC->APB1ENR |= (1 << 14))// APB1
#define SPI3_CLK_EN			(RCC->APB1ENR |= (1 << 15))// APB1

/*
 * Enable clock for USARTx
 * REFER TO RM0090  -  APB1 BUS, APB2 BUS
 * */
#define USART1_CLK_EN			(RCC->APB2ENR |= (1 << 4))// APB2
#define USART6_CLK_EN			(RCC->APB2ENR |= (1 << 5))// APB2

#define USART2_CLK_EN			(RCC->APB1ENR |= (1 << 17))// APB1
#define USART3_CLK_EN			(RCC->APB1ENR |= (1 << 18))// APB1


#define UART4_CLK_EN			(RCC->APB2ENR |= (1 << 19))// APB2
#define UART5_CLK_EN			(RCC->APB2ENR |= (1 << 20))// APB2
#define UART7_CLK_EN			(RCC->APB2ENR |= (1 << 30))// APB2
#define UART8_CLK_EN			(RCC->APB2ENR |= (1 << 31))// APB2


//------------------------------------------ DISABLE CLOCK ----------------------------------------
/*
 * Disable clock for GPIOx
 * */
#define GPIOA_CLK_DIS			(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_CLK_DIS			(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_CLK_DIS			(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_CLK_DIS			(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_CLK_DIS			(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_CLK_DIS			(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_CLK_DIS			(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_CLK_DIS			(RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_CLK_DIS			(RCC->AHB1ENR &= ~(1 << 8))

/*
 * Disable clock for I2Cx
 * */
#define I2C1_CLK_DIS			(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_CLK_DIS			(RCC->APB1ENR &= ~(1 << 22))
#define I2C3_CLK_DIS			(RCC->APB1ENR &= ~(1 << 23))

/*
 * Disable clock for SPIx
 * */
#define SPI1_CLK_DIS			(RCC->APB2ENR &= ~(1 << 12))// APB2
#define SPI2_CLK_DIS			(RCC->APB1ENR &= ~(1 << 14))// APB1
#define SPI3_CLK_DIS			(RCC->APB1ENR &= ~(1 << 15))// APB1

/*
 * Disable clock for USARTx
 * */
#define USART1_CLK_DIS			(RCC->APB2ENR &= ~(1 << 4))// APB2
#define USART6_CLK_DIS			(RCC->APB2ENR &= ~(1 << 5))// APB2

#define USART2_CLK_DIS			(RCC->APB1ENR &= ~(1 << 17))// APB1
#define USART3_CLK_DIS			(RCC->APB1ENR &= ~(1 << 18))// APB1


#define UART4_CLK_DIS			(RCC->APB2ENR &= ~(1 << 19))// APB2
#define UART5_CLK_DIS			(RCC->APB2ENR &= ~(1 << 20))// APB2
#define UART7_CLK_DIS			(RCC->APB2ENR &= ~(1 << 30))// APB2
#define UART8_CLK_DIS			(RCC->APB2ENR &= ~(1 << 31))// APB2

//------------------------------------------ MACROS USE TO RESET GPIO ----------------------------------------
#define GPIOA_RESET()  do { RCC->AHB1RSTR |= (1 << 0); RCC->AHB1RSTR &= ~(1 << 0); } while(0)
#define GPIOB_RESET()  do { RCC->AHB1RSTR |= (1 << 1); RCC->AHB1RSTR &= ~(1 << 1); } while(0)
#define GPIOC_RESET()  do { RCC->AHB1RSTR |= (1 << 2); RCC->AHB1RSTR &= ~(1 << 2); } while(0)
#define GPIOD_RESET()  do { RCC->AHB1RSTR |= (1 << 3); RCC->AHB1RSTR &= ~(1 << 3); } while(0)
#define GPIOE_RESET()  do { RCC->AHB1RSTR |= (1 << 4); RCC->AHB1RSTR &= ~(1 << 4); } while(0)
#define GPIOF_RESET()  do { RCC->AHB1RSTR |= (1 << 5); RCC->AHB1RSTR &= ~(1 << 5); } while(0)
#define GPIOG_RESET()  do { RCC->AHB1RSTR |= (1 << 6); RCC->AHB1RSTR &= ~(1 << 6); } while(0)
#define GPIOH_RESET()  do { RCC->AHB1RSTR |= (1 << 7); RCC->AHB1RSTR &= ~(1 << 7); } while(0)
#define GPIOI_RESET()  do { RCC->AHB1RSTR |= (1 << 8); RCC->AHB1RSTR &= ~(1 << 8); } while(0)
//------------------------------------------ MACROS USE IN API ----------------------------------------
#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE
#define PIN_SET 			SET
#define PIN_RESET 			RESET


#endif /* INC_STM32F407XX_H_ */
