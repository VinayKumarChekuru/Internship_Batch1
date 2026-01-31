




#include"GPIO_Driver.h"


/*
 * @name        : GPIO_Clk_EnorDi
 * @return      : void
 * @parameters  : GPIO_RegDef_t *pGPIOx, uint8_t EnorDi
 * @Description : This function manages the clock gating for the specified GPIO port.
 * It interacts with the RCC (Reset and Clock Control) registers to
 * toggle the peripheral clock based on the EnorDi input.*/


void GPIO_Clk_EnorDi(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi)
{
   if(EnorDi == ENABLE)
   {
	   //enable Clock
	   if(pGPIOx == pGPIOA)
	   {
		   pRCC->AHBENR |= (SET << RCC_AHBENR_GPIOAEN);
	   }
	   else if(pGPIOx == pGPIOB)
	   {
		   pRCC->AHBENR |= (SET << RCC_AHBENR_GPIOBEN);
	   }
	   else if(pGPIOx == pGPIOC)
	   {
		   pRCC->AHBENR |= (SET << RCC_AHBENR_GPIOCEN);
	   }
	   else if(pGPIOx == pGPIOD)
	   {
		   pRCC->AHBENR |= (SET << RCC_AHBENR_GPIODEN);
	   }
	   else if(pGPIOx == pGPIOF)
	   {
		   pRCC->AHBENR |= (SET << RCC_AHBENR_GPIOFEN);
	   }

   }
   else
   {
	   //Disable Clock
	   if(pGPIOx == pGPIOA)
	   {
		   pRCC->AHBENR &= ~(SET << RCC_AHBENR_GPIOAEN);
	   }
	   else if (pGPIOx == pGPIOB)
	   {
		   pRCC->AHBENR &= ~(SET << RCC_AHBENR_GPIOBEN);
	   }
	   else if (pGPIOx == pGPIOC)
	   {
		   pRCC->AHBENR &= ~(SET << RCC_AHBENR_GPIOCEN);
	   }
	   else if (pGPIOx == pGPIOD)
	   {
		   pRCC->AHBENR &= ~(SET << RCC_AHBENR_GPIODEN);
	   }
	   else if (pGPIOx == pGPIOF)
	   {
		   pRCC->AHBENR &= ~(SET << RCC_AHBENR_GPIOFEN);
	   }

   }
}

/*
 * @name        : GPIO_Init
 * @return      : void
 * @parameters  : GPIO_Handler_t GPIO_Handler
 * @Description : Performs the hardware initialization of the GPIO pin. This involves
 * setting the mode, output type, speed, and resistor configuration
 * defined in the GPIO_Handler structure.*/

void GPIO_Init(GPIO_Handler_t GPIO_Handler)
{

	//Configure Mode of GPIO Pin
	GPIO_Handler.PGPIOx->MODER |= (GPIO_Handler.GPIO_Config.Mode << (2*GPIO_Handler.GPIO_Config.Pin_Num));

	//Configure GPIO Output type (Push Pull or Open Drain)
    GPIO_Handler.PGPIOx->OTYPER |= (GPIO_Handler.GPIO_Config.OutPut_Type << (GPIO_Handler.GPIO_Config.Pin_Num));

	//Configure GPIO Output Speed
    GPIO_Handler.PGPIOx->OSPEEDR |= (GPIO_Handler.GPIO_Config.OutPut_Speed << (2*GPIO_Handler.GPIO_Config.Pin_Num));

	//Configure GPIO PullUp and PullDown register
    GPIO_Handler.PGPIOx->PUPDR |= (GPIO_Handler.GPIO_Config.PuPd << (2*GPIO_Handler.GPIO_Config.Pin_Num));

}


/*
 * @name        : GPIO_Deint
 * @return      : void
 * @parameters  : GPIO_RegDef_t *pGPIOx
 * @Description : This function performs a software reset on the GPIO peripheral's
 * registers, bringing them back to their default reset values via
 * the RCC reset bus.
 */
void GPIO_Deint(GPIO_RegDef_t *pGPIOx)
{
   /* Trigger the reset bit for the corresponding GPIO port in the RCC reset register */
   if(pGPIOx == pGPIOA)      {
	   pRCC->AHBRSTR |= (SET << RCC_AHBENR_GPIOAEN); }
   else if(pGPIOx == pGPIOB) {
	   pRCC->AHBRSTR |= (SET << RCC_AHBENR_GPIOBEN); }
   else if(pGPIOx == pGPIOC) {
	   pRCC->AHBRSTR |= (SET << RCC_AHBENR_GPIOCEN); }
   else if(pGPIOx == pGPIOD) {
	   pRCC->AHBRSTR |= (SET << RCC_AHBENR_GPIODEN); }
   else if(pGPIOx == pGPIOF) {
	   pRCC->AHBRSTR |= (SET << RCC_AHBENR_GPIOFEN); }
}

















