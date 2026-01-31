


#include"GPIO_Driver.h"



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
 *
 * @name : GPIO_Init
 * @return : void
 * @parameters: GPIO_Handler_t GPIO_Handler
 * @Description :
 */

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


void GPIO_Deint(GPIO_RegDef_t *PGPIOx)
{

}


















