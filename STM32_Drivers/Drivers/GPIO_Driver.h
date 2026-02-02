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
#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3

/*
 * GPIO output type
 */
#define GPIO_PUSHPULL		0
#define GPIO_OPENDRAIN		1

/*
 * GPIO Output Speed
 */
#define GPIO_SPEED_LOW		0	// 0 2 ALSO LOWSPEED
#define GPIO_SPEED_MED		1
#define GPIO_SPEED_HIGH		3
/*
 * GPIO Peripheral Reset
 */
#define GPIOPARST		17
#define GPIOPBRST		18
#define GPIOPCRST		19
#define GPIOPDRST		20
#define GPIOPERST		21//Not Available
#define GPIOPFRST		22
typedef struct
{
	uint8_t Pin_Num;   //Pin Number of a Port
	uint8_t Mode;      //Pin MOde
	uint8_t OutPut_Type;
	uint8_t OutPut_Speed;
	uint8_t PuPd;

}GPIO_Config_t;

/*
 * GPIO Handler structure
 */
typedef struct
{
	GPIO_RegDef_t *PGPIOx;//pointer variable so access data ->(arrow operator)
	GPIO_Config_t GPIO_Config;//variable so access data .(dot operator)
}GPIO_Handler_t;


void GPIO_Clk_EnorDi(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi);
void GPIO_Init(GPIO_Handler_t GPIO_Handler);
void GPIO_Deint(GPIO_RegDef_t *pGPIOx);
void GPIO_Write_To_Port(GPIO_RegDef_t *pGPIOx,uint16_t Data);
void GPIO_Write_To_Pin(GPIO_RegDef_t *pGPIOx,uint8_t PinNum,uint8_t Data);
uint16_t GPIO_Read_From_Port(GPIO_RegDef_t *pGPIOx);
uint8_t GPIO_Read_From_Pin(GPIO_RegDef_t *pGPIOx,uint8_t PinNum);

#endif /* GPIO_DRIVER_H_ */
