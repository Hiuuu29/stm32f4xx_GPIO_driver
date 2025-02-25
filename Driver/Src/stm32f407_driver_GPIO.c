/*
 * stm32f407_driver_GPIO.c
 *
 *  Created on: Feb 25, 2025
 *      Author: Huynh Trung Hieu
 */


#include"stm32f407xx_driver.h"


/**
 * 							  					Enable or Disable clock on GPIO
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_CLK
 *
 *@Descripes 				: Enable or Disable Clock of given GPIO
 *
 *@para[1]					: Base address of GPIO peri to config
 *@para[2]					: Enable or Disable Macros
 *
 *@return					: None
 *
 *@note						: None
 *
 */
void GPIO_CLK(GPIO_RegDef_t *pGPIO, uint8_t EnorDis){
	if(EnorDis){ // if enable clk
		if(pGPIO == GPIOA) 			// pointer point to the base address of GPIO (look at stm32f407xx.h for more info) 205-215
			GPIOA_CLK_EN;			// Macros stm32f407xx.h 228 to 238
		if(pGPIO == GPIOB)
			GPIOB_CLK_EN;
		if(pGPIO == GPIOC)
			GPIOC_CLK_EN;
		if(pGPIO == GPIOD)
			GPIOD_CLK_EN;
		if(pGPIO == GPIOE)
			GPIOE_CLK_EN;
		if(pGPIO == GPIOF)
			GPIOF_CLK_EN;
		if(pGPIO == GPIOG)
			GPIOG_CLK_EN;
		if(pGPIO == GPIOH)
			GPIOH_CLK_EN;
		if(pGPIO == GPIOI)
			GPIOI_CLK_EN;
		if(pGPIO == GPIOJ)
			GPIOJ_CLK_EN;
		if(pGPIO == GPIOK)
			GPIOK_CLK_EN;
	}
	else{
		if(pGPIO == GPIOA) 			// pointer point to the base address of GPIO (look at stm32f407xx.h for more info) 205-215
			GPIOA_CLK_DIS;			// Macros stm32f407xx.h 277 to 287
		if(pGPIO == GPIOB)
			GPIOB_CLK_DIS;
		if(pGPIO == GPIOC)
			GPIOC_CLK_DIS;
		if(pGPIO == GPIOD)
			GPIOD_CLK_DIS;
		if(pGPIO == GPIOE)
			GPIOE_CLK_DIS;
		if(pGPIO == GPIOF)
			GPIOF_CLK_DIS;
		if(pGPIO == GPIOG)
			GPIOG_CLK_DIS;
		if(pGPIO == GPIOH)
			GPIOH_CLK_DIS;
		if(pGPIO == GPIOI)
			GPIOI_CLK_DIS;
		if(pGPIO == GPIOJ)
			GPIOJ_CLK_DIS;
		if(pGPIO == GPIOK)
			GPIOK_CLK_DIS;
	}
}

/**
 * 							  					initialize GPIO
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_Init
 *
 *@Descripes 				: initialize GPIO
 *
 *@para[1]					: pointer to struct in that struct have base address to config
 *
 *@return					: None
 *
 *@note						: In this Func we need to config the given PORT and the given pin, mode, speed, output type, pull up-down resistor, alternate func
 *
 */
void GPIO_Init(GPIO_HAL *pGPIO_Handle){

	// 1. Mode
	// 2. Speed
	// 3. pull up pull down
	// 4. out put type
	// 5. Alternate Function
	if(pGPIO_Handle->pGPIOx == GPIOA){

	}else{

	}
}

/**
 * 							  					de-initialize GPIO
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_DeInit
 *
 *@Descripes 				: de-initialize GPIO
 *
 *@para[1]					: Base address of GPIO peri to config
 *
 *@return					: None
 *
 *@note						: None
 *
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIO);

/**
 * 							  					Read the state of pin x of GPIO y
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_Read_Pin
 *
 *@Descripes 				: Read the state pin x of GPIO y
 *
 *@para[1]					: Base address of GPIO peri to read
 *@para[2]					: number indicate state 1 or 0
 *
 *@return					: State is either H or L then return type should be bool or uint8_t
 *
 *@note						: None
 *
 */
uint8_t GPIO_Read_Pin(GPIO_RegDef_t *pGPIO, uint8_t number){

}

/**
 * 							  					Read the state of GPIO
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_Read_Port
 *
 *@Descripes 				: Read the state of GPIO x
 *
 *@para[1]					: Base address of GPIO peri to read
 *
 *@return					: State is either H or L then return type should be bool or uint8_t
 *
 *@note						: None
 *
 */
uint16_t GPIO_Read_Port(GPIO_RegDef_t *pGPIO){

}

/**
 * 							  					Write state for pin x GPIO y
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_Write_Pin
 *
 *@Descripes 				: Write the state of pin y GPIO x
 *
 *@para[1]					: Base address of GPIO peri to Write
 *@para[2]					: number of pin x
 *@para[3]					: value want to output of that pin H or L
 *
 *@return					: None
 *
 *@note						: None
 *
 */
void GPIO_Write_Pin(GPIO_RegDef_t *pGPIO, uint8_t number, uint8_t value){

}

/**
 * 							  					Write state for GPIO x
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_Write_Port
 *
 *@Descripes 				: Write the state GPIO x
 *
 *@para[1]					: Base address of GPIO peri to Write
 *@para[2]					: value want to output of that PORT H or L
 *
 *@return					: None
 *
 *@note						: None
 *
 */
void GPIO_Write_Port(GPIO_RegDef_t *pGPIO, uint8_t value){

}

/**
 * 							  					Toggle state for GPIO x (Switch state)
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_Toggle_Output
 *
 *@Descripes 				: Toggle the state
 *
 *@para[1]					: Base address of GPIO peri to Write
 *@para[2]					: number want to output of that PORT H or L
 *
 *@return					: None
 *
 *@note						: None
 *
 */
void GPIO_Toggle_Output(GPIO_RegDef_t *pGPIO, uint8_t number);

/**
 * 							  					Config Interrupt on IRQ
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_IRQ_Config
 *
 *@Descripes 				: Config interrupt
 *
 *@para[1]					: IRQ number
 *@para[2]					: set priority for that IRQ
 *@para[3]					: Enable or Disable IRQ
 *
 *@return					: None
 *
 *@note						: None
 *
 */
void GPIO_IRQ_Config(uint8_t IRQnum, uint8_t Prio, uint8_t EnorDis){

}

/**
 * 							  					What to do in Interrupt
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_IRQ_Handling
 *
 *@Descripes 				: What to do in Interrupt
 *
 *@para[1]					: IRQ number
 *
 *@return					: None
 *
 *@note						: None
 *
 */
void GPIO_IRQ_Handling(uint8_t number){

}
