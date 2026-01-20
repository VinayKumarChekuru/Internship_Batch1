/*
 * STM32F051.h
 *
 *  Created on: Jan 7, 2026
 *      Author: vinaykumar
 */

/*Device Specific header file*/



#ifndef STM32F051_H_
#define STM32F051_H_
#include<stdint.h>


#define ui32   uint32_t
#define __vo   volatile

#define ENABLE   1
#define DISABLE  0

#define SET      ENABLE
#define CLEAR    DISABLE
#define RESET    DISABLE

/*
 * BIT Positions of RCC_AHBENR
 */
#define RCC_AHBENR_GPIOAEN     17
#define RCC_AHBENR_GPIOBEN     18
#define RCC_AHBENR_GPIOCEN     19
#define RCC_AHBENR_GPIODEN     20
#define RCC_AHBENR_GPIOEEN     21
#define RCC_AHBENR_GPIOFEN     22

/*
 * Base Addresses of System Buses
 */

#define AHB1_BASE_ADDR     0x40020000
#define AHB2_BASE_ADDR     0x48000000
#define APB_BASE_ADDR      0x40000000


/*
 * GPIO Base addresses
 */
#define GPIOA_BASE_ADDR     ((AHB2_BASE_ADDR) + (0x0000))
#define GPIOB_BASE_ADDR     ((AHB2_BASE_ADDR) + (0x0400))
#define GPIOC_BASE_ADDR     ((AHB2_BASE_ADDR) + (0x0800))
#define GPIOD_BASE_ADDR     ((AHB2_BASE_ADDR) + (0x0C00))
#define GPIOF_BASE_ADDR     ((AHB2_BASE_ADDR) + (0x1400))

/*
 * Reset and clock control(RCC) Base address
 *
 */
#define RCC_BASE_ADDR      ((AHB1_BASE_ADDR) + (0x1000))

/*
 * Register definition structure of GPIOs
 */
typedef struct
{
	__vo ui32 MODER;
	__vo ui32 OTYPER;
	__vo ui32 OSPEEDR;
	__vo ui32 PUPDR;
	__vo ui32 IDR;
	__vo ui32 ODR;
	__vo ui32 BSRR;
	__vo ui32 LCKR;
	__vo ui32 AFRL;
	__vo ui32 AFRH;
	__vo ui32 BRR;

}GPIO_RegDef_t;




/*
 * Register Definition structure of RCC
 */
typedef struct
{
	__vo ui32 CR;
	__vo ui32 CFGR;
	__vo ui32 CIR;
	__vo ui32 APB2RSTR;
	__vo ui32 APB1RSTR;
	__vo ui32 AHBENR;
	__vo ui32 APB2ENR;
	__vo ui32 APB1ENR;
	__vo ui32 BDCR;
	__vo ui32 CSR;
	__vo ui32 AHBRSTR;
	__vo ui32 CFGR2;
	__vo ui32 CFGR3;
	__vo ui32 CR2;

}RCC_RegDef_t;


/*
 * GPIO Pointers for GPIO_RegDef_t
 */

GPIO_RegDef_t *pGPIOA = (GPIO_RegDef_t*)GPIOA_BASE_ADDR;
GPIO_RegDef_t *pGPIOB = (GPIO_RegDef_t*)GPIOB_BASE_ADDR;
GPIO_RegDef_t *pGPIOC = (GPIO_RegDef_t*)GPIOC_BASE_ADDR;
GPIO_RegDef_t *pGPIOD = (GPIO_RegDef_t*)GPIOD_BASE_ADDR;
GPIO_RegDef_t *pGPIOF = (GPIO_RegDef_t*)GPIOF_BASE_ADDR;

/*
 * Pointer of type RCC_RegDef_t and pointing RCC_BASE_ADDR
 */

RCC_RegDef_t *pRCC = (RCC_RegDef_t*)RCC_BASE_ADDR;




#endif /* STM32F051_H_ */
