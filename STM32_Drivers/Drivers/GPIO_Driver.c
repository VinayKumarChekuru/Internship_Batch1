

#include"GPIO_Driver.h"

/*
 * @name		:GPIO_Clk_EnorDi
 * @return		:void
 * @parameters	:GPIO_RegDef_t, uint8_t
 * @Description	:This function enables or disables the GPIO peripheral clock by
 * 				 configuring the corresponding RCC register based on the provided
 * 				 GPIO register reference and clock state.
 */

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
 * @name		:GPIO_Init
 * @return		:void
 * @parameters	:GPIO_Handler_t
 * @Description	:The GPIO is initialized by configuring its operating mode, output type,
 *  			 output speed, and internal pull-up or pull-down resistors.
 */
void GPIO_Init(GPIO_Handler_t GPIO_Handler)
{

	//Configure Mode of GPIO pin
	GPIO_Handler.PGPIOx->MODER |= GPIO_Handler.GPIO_Config.Mode << (2*GPIO_Handler.GPIO_Config.Pin_Num);

	//Configure Output type of GPIO Pin (Push pull or Open drain)
	GPIO_Handler.PGPIOx->OTYPER |= GPIO_Handler.GPIO_Config.OutPut_Type << GPIO_Handler.GPIO_Config.Pin_Num;

	//Configure GPIO Output Speed
	GPIO_Handler.PGPIOx->OSPEEDR |= GPIO_Handler.GPIO_Config.OutPut_Speed << (2*GPIO_Handler.GPIO_Config.Pin_Num);

	//Configure GPIO Pull up Pull down (output two types when open drain 1state so getting another use this conf)
	GPIO_Handler.PGPIOx->PUPDR |= GPIO_Handler.GPIO_Config.PuPd << (2*GPIO_Handler.GPIO_Config.Pin_Num);

}

/*
 * @name		:GPIO_Deint
 * @return		:void
 * @parameters	:GPIO_RegDef_t
 * @Description	:This function resets the GPIO peripheral clock by
 * 				 configuring the corresponding RCC register based on the provided
 * 				 GPIO register reference.
 */
void GPIO_Deint(GPIO_RegDef_t *pGPIOx)
{

	if(pGPIOx == pGPIOA)
	{
		pRCC->AHBRSTR |= (SET << GPIOPARST);
	}
	else if(pGPIOx == pGPIOB)
	{
		pRCC->AHBRSTR |= (SET << GPIOPBRST);
	}
	else if(pGPIOx == pGPIOC)
	{
		pRCC->AHBRSTR |= (SET << GPIOPCRST);
	}
	else if(pGPIOx == pGPIOD)
	{
		pRCC->AHBRSTR |= (SET << GPIOPDRST);
	}
	else if(pGPIOx == pGPIOF)
	{
		pRCC->AHBRSTR |= (SET << GPIOPFRST);
	}

}

/*
 * @name		:GPIO_Write_To_Port
 * @return		:void
 * @parameters	:GPIO_RegDef_t, uint16_t
 * @Description	:This function Writes the data to a Port
 * 				 based on provided GPIO Register reference.
 */
void GPIO_Write_To_Port(GPIO_RegDef_t *pGPIOx,uint16_t Data)
{

	pGPIOx->ODR = Data;//Over writes the data

}

/*
 * @name		:GPIO_Write_To_Pin
 * @return		:void
 * @parameters	:GPIO_RegDef_t, uint8_t, uint8_t
 * @Description	:This function Writes the data to a Port specific
 * 				 pin based on provided GPIO Register reference.
 */
void GPIO_Write_To_Pin(GPIO_RegDef_t *pGPIOx,uint8_t PinNum,uint8_t Data)
{

	// clear the previous data Before writing to the Data
	pGPIOx->ODR &= ~(SET << PinNum);
	//Write the Data to Pin
	pGPIOx->ODR |= (Data << PinNum);

}

/*
 * @name		:GPIO_Read_From_Port
 * @return		:uint16_t
 * @parameters	:GPIO_RegDef_t
 * @Description	:This function Reads the data from a Port specific
 * 				 pin based on provided GPIO Register reference.
 */
uint16_t GPIO_Read_From_Port(GPIO_RegDef_t *pGPIOx)
{

	return (uint16_t)(pGPIOx->IDR);

}

/*
 * @name		:GPIO_Read_From_Pin
 * @return		:uint8_t
 * @parameters	:GPIO_RegDef_t, uint8_t, uint8_t
 * @Description	:This function Reads the data from a Port specific pin based on
 * 				 provided GPIO Register reference and Pin number.
 */
uint8_t GPIO_Read_From_Pin(GPIO_RegDef_t *pGPIOx,uint8_t PinNum)
{

	return (uint8_t) ((pGPIOx->IDR >> PinNum)&(0X00000001)); //or simply write 1 instead of 0X00000001

}
