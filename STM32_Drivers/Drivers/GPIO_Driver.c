

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


