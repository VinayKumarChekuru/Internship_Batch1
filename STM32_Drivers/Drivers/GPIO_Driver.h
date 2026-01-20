/*
 * GPIO_Driver.h
 *
 *  Created on: Jan 14, 2026
 *      Author: vinaykumar
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#include"STM32F051.h"


/*
 * GPIO Configuration structure
 */

	__vo ui32 MODER;
	__vo ui32 OTYPER;
	__vo ui32 OSPEEDR;
	__vo ui32 PUPDR;
typedef struct
{
	uint8_t Pin_Num;   //Pin Number of a Port
	uint8_t Mode;      //Pin MOde
	uint8_t OutPut_Type;
	uint8_t OutPut_Speed;
	uint8_t PuPd;

}GPIO_Config_t;





void GPIO_Clk_EnorDi(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi);
void GPIO_Init(GPIO_RegDef_t *PGPIOx,GPIO_Config_t GPIO_Config);

#endif /* GPIO_DRIVER_H_ */
