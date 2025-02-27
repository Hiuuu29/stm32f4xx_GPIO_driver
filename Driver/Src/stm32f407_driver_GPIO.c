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
			GPIOA_CLK_EN();			// Macros stm32f407xx.h 228 to 238
		else if(pGPIO == GPIOB)
			GPIOB_CLK_EN();
		else if(pGPIO == GPIOC)
			GPIOC_CLK_EN();
		else if(pGPIO == GPIOD)
			GPIOD_CLK_EN();
		else if(pGPIO == GPIOE)
			GPIOE_CLK_EN();
		else if(pGPIO == GPIOF)
			GPIOF_CLK_EN();
		else if(pGPIO == GPIOG)
			GPIOG_CLK_EN();
		else if(pGPIO == GPIOH)
			GPIOH_CLK_EN();
		else if(pGPIO == GPIOI)
			GPIOI_CLK_EN();
	}
	else{
		if(pGPIO == GPIOA) 			// pointer point to the base address of GPIO (look at stm32f407xx.h for more info) 205-215
			GPIOA_CLK_DIS();			// Macros stm32f407xx.h 277 to 287
		else if(pGPIO == GPIOB)
			GPIOB_CLK_DIS();
		else if(pGPIO == GPIOC)
			GPIOC_CLK_DIS();
		else if(pGPIO == GPIOD)
			GPIOD_CLK_DIS();
		else if(pGPIO == GPIOE)
			GPIOE_CLK_DIS();
		else if(pGPIO == GPIOF)
			GPIOF_CLK_DIS();
		else if(pGPIO == GPIOG)
			GPIOG_CLK_DIS();
		else if(pGPIO == GPIOH)
			GPIOH_CLK_DIS();
		else if(pGPIO == GPIOI)
			GPIOI_CLK_DIS();
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

	GPIO_CLK(pGPIO_Handle->pGPIOx, ENABLE);
	/*Nguoi dung da khai bao tat ca cac gia tri can thiet, bay h chi huong con tro
	 * den vi tri thanh ghi dung voi nguoi dung nhap
	*/
	//-----------------------------------------------------------------------------------------------
	//1. Mode
	uint32_t tmp = 0;
	// Check if mode interrupt or not (IRQ have value > GPIO_MODE_ANALOG (3))
	if(pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_mode <= GPIO_MODE_ANALOG){
		// not an interrupt
		// Shift value of mode to the right register
		tmp = (pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_mode << (2 * pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num));
		pGPIO_Handle->pGPIOx->MODER &= ~(0x03 << (2 * pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num)); // clear bit at that position
		pGPIO_Handle->pGPIOx->MODER |= tmp; //only change the bit that is being config, not check other bit
	}else{
		// 1. CHECK WHAT KIND OF INTERRUPT IS THIS
		if(pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_mode == GPIO_MODE_IN_FE){
			// config falling trigger selection register (FISR)
			EXTI->EXTI_FTSR |= (1 << pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num); 	// ENABLE FISR ON SELECTED PIN
			EXTI->EXTI_RTSR &= ~(1 << pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num); 	// DISABLE RISR ON SELECTED PIN
		}
		else if(pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_mode == GPIO_MODE_IN_RE){
			// config rising trigger selection register (RISR)
			EXTI->EXTI_RTSR |= (1 << pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num); 	// ENABLE RISR ON SELECTED PIN
			EXTI->EXTI_FTSR &= ~(1 << pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num); 	// DISABLE FISR ON SELECTED PIN
		}
		else{
		// 1. config falling, rising trigger selection register (FISR and RTSR)
			EXTI->EXTI_FTSR |= (1 << pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num); 	// ENABLE FISR ON SELECTED PIN
			EXTI->EXTI_RTSR |= (1 << pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num); 	// ENABLE RISR ON SELECTED PIN
		}

		// 2. congif GPIO port selection is SYSCFG_EXTICR
			uint8_t tmp1 = pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num / 4; // determine what EXTICR[] 1 2 3 4 to use base on the pin
			uint8_t tmp2 = pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num % 4; // var to shift it to the correct PORT
			uint8_t port_code = GPIO_ADDR_TO_CODE(pGPIO_Handle->pGPIOx);

			SYSCFG_CLOCK_ENABLE()
			SYSCFG->SYSCFG_EXTICR[tmp1] |= (port_code << (4 * tmp2));

		// 3. enable EXTI interrupt delivery in IMR (interrupt mask register)
			EXTI->EXTI_IMR |= (1 << pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num);
	}




	tmp = 0;
	//-----------------------------------------------------------------------------------------------
	// 2. Speed
	tmp = pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_speed << (2 * pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num);
	pGPIO_Handle->pGPIOx->OSPEEDR &= ~(0x03 << (2 * pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num));
	pGPIO_Handle->pGPIOx->OSPEEDR |= tmp;
	tmp = 0;
	//-----------------------------------------------------------------------------------------------
	// 3. pull up pull down
	tmp = pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_PuPdCONTROL << (2 * pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num);
	pGPIO_Handle->pGPIOx->PUPDR &= ~(0x03 << (2 * pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num));
	pGPIO_Handle->pGPIOx->PUPDR |= tmp;
	tmp = 0;
	//-----------------------------------------------------------------------------------------------
	// 4. out put type
	tmp = pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_OUTPUT_TYPE << pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num;
	pGPIO_Handle->pGPIOx->OTYPER &= ~(0x01 << pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num);
	pGPIO_Handle->pGPIOx->OTYPER |= tmp;
	tmp = 0;
	//-----------------------------------------------------------------------------------------------
	// 5. Alternate Function
	if(pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_mode == GPIO_MODE_ALT){
		// configure the alternate function registers
		uint8_t temp1 , temp2 ;

		temp1 = pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num/ 8 ;
		temp2 = pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_num % 8 ;
		pGPIO_Handle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2)) ;
		pGPIO_Handle->pGPIOx->AFR[temp1] |= (pGPIO_Handle->GPIO_PIN_CONFIG.GPIO_Pin_AltFunc << (4 * temp2)) ;
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
void GPIO_DeInit(GPIO_RegDef_t *pGPIO){
	GPIO_CLK(pGPIO, DISABLE);
	// ALL YOU HAVE TO DO IT RESET IT AT THE RCC RM0090 PAGE - 235 (RESET : SET THE BIT 1 AND THEN 0)
	if(pGPIO == GPIOA)
		GPIOA_RESET();
	if(pGPIO == GPIOB)
		GPIOB_RESET();
	if(pGPIO == GPIOC)
		GPIOC_RESET();
	if(pGPIO == GPIOD)
		GPIOD_RESET();
	if(pGPIO == GPIOE)
		GPIOE_RESET();
	if(pGPIO == GPIOF)
		GPIOF_RESET();
	if(pGPIO == GPIOG)
		GPIOG_RESET();
	if(pGPIO == GPIOH)
		GPIOH_RESET();
	if(pGPIO == GPIOI)
		GPIOI_RESET();
}

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
	return (uint8_t)((pGPIO->IDR >> number) & 0x00000001 );
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
 *@return					: State is either H or L 16 of them so uint16_t
 *
 *@note						: None
 *
 */
uint16_t GPIO_Read_Port(GPIO_RegDef_t *pGPIO){
	return (uint16_t)(pGPIO->IDR & 0xFFFF);
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
void GPIO_Write_Pin(GPIO_RegDef_t *pGPIO, uint8_t number, uint8_t value) {
    if (value)
        pGPIO->ODR |= (1 << number);  // Set bit (1)
    else
        pGPIO->ODR &= ~(1 << number); // Clear bit (0)
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
void GPIO_Write_Port(GPIO_RegDef_t *pGPIO, uint16_t value){
	// overwrite all the bit in register
	pGPIO->ODR = ~(1 << value);
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
void GPIO_Toggle_Output(GPIO_RegDef_t *pGPIO, uint8_t number){
	pGPIO->ODR ^= (1 << number);
}

/**
 * 							  					Config Interrupt on IRQ
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_IRQ_Config
 *
 *@Descripes 				: Config interrupt (NVIC REGISTER) BASE ON VECTOR TABLE RM0090-375
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
void GPIO_IRQ_Config(uint8_t IRQnum, uint8_t EnorDis){
	if(EnorDis){
		if(IRQnum <= 31){
			//ISER0
			NVIC_ISER0 |= (1 << IRQnum);
		}
		else if(IRQnum > 31 && IRQnum < 64){ // 32-63
			//ISER1
			NVIC_ISER1 |= (1 << IRQnum);
		}
		else if(IRQnum >= 64  && IRQnum < 96){ // 64-95
			//ISER2
			NVIC_ISER2 |= (1 << IRQnum);
		}
	}
	else{
		if(IRQnum <= 31){
			//ICER0
			NVIC_ICER0 |= (1 << IRQnum);
		}
		else if(IRQnum > 31 && IRQnum < 64){ // 32-63
			//ICER1
			NVIC_ICER1 |= (1 << IRQnum);
		}
		else if(IRQnum >= 64  && IRQnum < 96){ // 64-95
			//ICER2
			NVIC_ICER2 |= (1 << IRQnum);
		}
	}
}
/**
 * 							  					Config Interrupt on IRQ
 *
 ******************************************************************************************************************************
 *@Function name 			: GPIO_IRQ_Config
 *
 *@Descripes 				: Config interrupt (NVIC REGISTER) BASE ON VECTOR TABLE RM0090-375
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
void GPIO_IRQ_Prio_Config(uint8_t IRQnum, uint8_t Prio){
	uint8_t irqx = IRQnum / 4;
	uint8_t irqx_section = IRQnum % 4;
	uint8_t shift_amount = (8 * irqx_section) + (8 - NO_IRQ_IMPELMENT);

	*(NVIC_PRIO_BASE + (irqx * 4)) |= (Prio << shift_amount);

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
	// Clear Pending register
	if((EXTI->EXTI_PR) & (1 << number)){
		EXTI->EXTI_PR |= (1 << number);
	}
}
