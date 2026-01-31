/*
 * GPIO_Driver.c
 *
 * Created on: 15-Jan-2026
 * Author: sahilhande
 */

#include"GPIO_Driver.h"

/*
 * @name        : GPIO_Clk_EnorDi
 * @return      : void
 * @parameters  : GPIO_RegDef_t *pGPIOx, uint8_t EnorDi
 * @Description : Manages the peripheral clock for a specific GPIO port.
 * It toggles the AHBENR register bits in the RCC block
 * depending on the requested EnorDi state.
 */

void GPIO_Clk_EnorDi(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
    {
        // Logic to turn clock ON
        if(pGPIOx == pGPIOA)      {
        	pRCC->AHBENR |= (SET << RCC_AHBENR_GPIOAEN); }
        else if(pGPIOx == pGPIOB) {
        	pRCC->AHBENR |= (SET << RCC_AHBENR_GPIOBEN); }
        else if(pGPIOx == pGPIOC) {
        	pRCC->AHBENR |= (SET << RCC_AHBENR_GPIOCEN); }
        else if(pGPIOx == pGPIOD) {
        	pRCC->AHBENR |= (SET << RCC_AHBENR_GPIODEN); }
        else if(pGPIOx == pGPIOF) {
        	pRCC->AHBENR |= (SET << RCC_AHBENR_GPIOFEN); }
    }
    else
    {
        // Logic to turn clock OFF
        if(pGPIOx == pGPIOA)      {
        	pRCC->AHBENR &= ~(SET << RCC_AHBENR_GPIOAEN); }
        else if(pGPIOx == pGPIOB) {
        	pRCC->AHBENR &= ~(SET << RCC_AHBENR_GPIOBEN); }
        else if(pGPIOx == pGPIOC) {
        	pRCC->AHBENR &= ~(SET << RCC_AHBENR_GPIOCEN); }
        else if(pGPIOx == pGPIOD) {
        	pRCC->AHBENR &= ~(SET << RCC_AHBENR_GPIODEN); }
        else if(pGPIOx == pGPIOF) {
        	pRCC->AHBENR &= ~(SET << RCC_AHBENR_GPIOFEN); }
    }
}

/*
 * @name        : GPIO_Init
 * @return      : void
 * @parameters  : GPIO_Handler_t GPIO_Handler
 * @Description : Sets up the hardware registers for the selected GPIO pin.
 * This includes configuring the mode, speed, pull-up/pull-down
 * resistors, and output driver type.
 */
void GPIO_Init(GPIO_Handler_t GPIO_Handler)
{
    // 1. Setting the Pin Mode (Input/Output/AltFn/Analog)
    GPIO_Handler.PGPIOx->MODER |= GPIO_Handler.GPIO_Config.Mode << (2 * GPIO_Handler.GPIO_Config.Pin_Num);

    // 2. Setting the Output Type (Push-Pull or Open-Drain)
    GPIO_Handler.PGPIOx->OTYPER |= GPIO_Handler.GPIO_Config.OutPut_Type << GPIO_Handler.GPIO_Config.Pin_Num;

    // 3. Setting the Pin Speed
    GPIO_Handler.PGPIOx->OSPEEDR |= GPIO_Handler.GPIO_Config.OutPut_Speed << (2 * GPIO_Handler.GPIO_Config.Pin_Num);

    // 4. Setting the Pull-up or Pull-down resistors
    GPIO_Handler.PGPIOx->PUPDR |= GPIO_Handler.GPIO_Config.PuPd << (2 * GPIO_Handler.GPIO_Config.Pin_Num);
}



/*
 * @name        : GPIO_Deint
 * @return      : void
 * @parameters  : GPIO_RegDef_t *pGPIOx
 * @Description : Triggers a hardware reset for the specified GPIO port
 * using the RCC reset registers (AHBRSTR).
 */
void GPIO_Deint(GPIO_RegDef_t *pGPIOx)
{
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


