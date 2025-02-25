/*
 * stm32f407xx_driver.h
 *
 *  Created on: Feb 25, 2025
 *      Author: Huynh Trung Hieu
 *      DRIVER SPECIFICS DATA
 *      THIS LAYERS WILL GIVE THE USER CONFIGURATION OPTIONS TO CHOOSE WHEN USING GPIO LIKE : WHAT PIN TO USE, WHAT PORT, SPEED, INPUT OR OUTPUT,...
 *      THE USER WILL FILL OR INITIALIZE NECESSARY INFO THEN IT WILL PASS TO THIS DRIVER API, DRIVER WILL TAKE INFO USER WANT AND INITIALIZE FOR THEIR
 *      NEEDED
 */

#ifndef INC_STM32F407XX_DRIVER_H_
#define INC_STM32F407XX_DRIVER_H_

// NEED TO INCLUDE THIS FIRST
#include"stm32f407xx.h"

//----------------------------------------------------CREATE 2 STRUCTURE HANDLE AND CONFIG STRUCTURE------------------------------------------------

// pin config struct to config specifig thing like pin, speed, mode ----------------------------------- DO NGUOI DUNG NHAP
typedef struct{

	uint8_t GPIO_Pin_num;				// chan so may trong GPIO (0-15)
	uint8_t GPIO_Pin_mode;				// mode input or output
	uint8_t GPIO_Pin_speed;				// set up speed
	uint8_t GPIO_Pin_PuPdCONTROL;		// Pull up Pull down resistor
	uint8_t GPIO_Pin_OUTPUT_TYPE;		// output type : open drain or push pull
	uint8_t GPIO_Pin_AltFunc;			// Alternative Function

}GPIO_PIN_CONFIG;

// hanlde struct to config which port to choose
typedef struct{ //------------------------------------------------------------------------------------- DO NGUOI DUNG NHAP

	// pointer point to the base address of GPIO peripheral
	GPIO_RegDef_t *pGPIOx;				//Hold the base address of GPIOx of the pinx belong
	GPIO_PIN_CONFIG *GPIO_PIN_CONFIG;

}GPIO_HAL;
//------------------------------------------------------------- POSSIBLE VALUE IN STRUCT-----------------------------------------------------

/*
 * GPIO NUMBER
 * */
#define GPIO_PIN_0   0
#define GPIO_PIN_1   1
#define GPIO_PIN_2   2
#define GPIO_PIN_3   3
#define GPIO_PIN_4   4
#define GPIO_PIN_5   5
#define GPIO_PIN_6   6
#define GPIO_PIN_7   7
#define GPIO_PIN_8   8
#define GPIO_PIN_9   9
#define GPIO_PIN_10  10
#define GPIO_PIN_11  11
#define GPIO_PIN_12  12
#define GPIO_PIN_13  13
#define GPIO_PIN_14  14
#define GPIO_PIN_15  15


/*
 * GPIO INPUT MODE OF THE PIN - REFER TO RM0090 PAGE 284
 * */
#define GPIO_MODE_INPUT 	0
#define GPIO_MODE_OUTPUT 	1
#define GPIO_MODE_ALT 		2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IN_FE 	4 // HAVE NO IDEA WHAT THIS IS
#define GPIO_MODE_IN_RE 	5 // HAVE NO IDEA WHAT THIS IS
#define GPIO_MODE_IN_RFT 	6 // HAVE NO IDEA WHAT THIS IS

/*
 * GPIO OUT PUT TYPE OF THE PIN - REFER TO RM0090 PAGE 284
 * 0 PUSH PULL
 * 1 OPEN DRAIN
 * */
#define GPIO_MODE_OUTPUT_PP 	0
#define GPIO_MODE_OUTPUT_OD 	1

/*
 * GPIO SPEED - REFER TO RM0090 PAGE 285
 * */
#define GPIO_SPEED_L 	0
#define GPIO_SPEED_M 	1
#define GPIO_SPEED_H 	2
#define GPIO_SPEED_VH 	3 // VERY HIGH

/*
 * GPIO PULL UP PULL DOWN RESIS - REFER TO RM0090 PAGE 285
 * */
#define GPIO_PUPD_DIS 	0
#define GPIO_PUPD_PU 	1 // PULL UP
#define GPIO_PUPD_PD 	2 // PULL DOWN


/**************************************************************************************************************************************************
 *
 * 														WRITE API FOR THIS DRIVER
 * 									DECRIPSTION FOR EACH API WITH CHECK API FUNCTION DEFITNITIONS
 *
 * ************************************************************************************************************************************************/
/*
 * How to do it:
 * 1. Write Func with no argument to figure out what GPIO will do (En/Dis GPIO, setup in/output, switch state,...)
 * 2. Decide to put which argument to the correspond func
 * */

/**
 * Enable or Disable clock on GPIO
 *
 *
 * ARUI : pointer point to CLK address to set bit
 * 		  a var to show the state
 */
void GPIO_CLK(GPIO_RegDef_t *pGPIO, uint8_t EnorDis);					// En/Dis CLK on GPIO

/**
 * initialize or deinitialize GPIO
 */
void GPIO_Init(GPIO_HAL *pGPIO_Handle); // init GPIO,  needed is a pointer to GPIO_Handlde (in GPIO_Handlde have base address to config)
void GPIO_DeInit(GPIO_RegDef_t *pGPIO);		// Send GPIO to reset state,  needed is a pointer to RCC reg? (in RCC Reg have a RCC_AHB1RSTR reg help reset)

/**
 * INPUT IN GPIO AND GPIO PIN
 */
// Read have to state 0 or 1 : so we can use bool or uint8_t as return type
uint8_t GPIO_Read_Pin(GPIO_RegDef_t *pGPIO, uint8_t number);				// input of specific pin x of GPIO x
uint16_t GPIO_Read_Port(GPIO_RegDef_t *pGPIO);				// input of all 16 pin on GPIO x

/**
 * OUTPUT IN GPIO AND GPIO PIN
 */
void GPIO_Write_Pin(GPIO_RegDef_t *pGPIO, uint8_t number, uint8_t value);				// output of all 16 pin on GPIO x
void GPIO_Write_Port(GPIO_RegDef_t *pGPIO, uint8_t value);				// output of all 16 pin on GPIO x
void GPIO_Toggle_Output(GPIO_RegDef_t *pGPIO, uint8_t number);			// switch state H or L

/**
 * INTERRUPT CONFIG AND INTERRUPT HANDLER
 */
void GPIO_IRQ_Config(uint8_t IRQnum, uint8_t Prio, uint8_t EnorDis);				// config interrupt, en/dis interrupt, setup prio,..
void GPIO_IRQ_Handling(uint8_t number);			// The func will handle what happen in interrupt










#endif /* INC_STM32F407XX_DRIVER_H_ */
