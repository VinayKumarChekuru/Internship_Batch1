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
 * Modes of GPIO
 */
#define GPIO_MODE_IN            0
#define GPIO_MODE_OUT           1
#define GPIO_MODE_ALTFN         2
#define GPIO_MODE_ANALOG        3

/*
 * GPIO Output type
 */

#define GPIO_PUSHPULL           0
#define GPIO_OPENDRAIN          1


/*
 * GPIO Output speeds
 */

#define GPIO_SPEED_LOW         0
#define GPIO_SPEED_MED         1
#define GPIO_SPEED_HIGH        3



/*
 * GPIO Configuration structure
 */


typedef struct
{
	uint8_t Pin_Num;   //Pin Number of a Port
	uint8_t Mode;      //Pin MOde
	uint8_t OutPut_Type;
	uint8_t OutPut_Speed;
	uint8_t PuPd;

}GPIO_Config_t;


/*
 * GPIO Handler Structure
 */

typedef struct
{
	GPIO_RegDef_t *PGPIOx;
	GPIO_Config_t GPIO_Config;

}GPIO_Handler_t;



void GPIO_Clk_EnorDi(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi);
void GPIO_Init(GPIO_Handler_t GPIO_Handler);
void GPIO_Deint(GPIO_RegDef_t *PGPIOx);

#endif /* GPIO_DRIVER_H_ */
