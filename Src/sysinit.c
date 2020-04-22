/*
 * sysinit.c
 *
 *  Created on: Apr 22, 2020
 *      Author: muaddib
 */

#include "sysinit.h"

volatile uint32_t SystemTicktimer = 0;

void SysTick_Handler(void)
{
	SystemTicktimer++;
}


int initRCC(void)
{
	uint32_t tmp;
	//enable clock power
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;

	//
	PWR->CR |= PWR_CR_VOS;

	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));

	//disable PLL
	RCC->CR &= ~RCC_CR_PLLON;
	while(RCC->CR & RCC_CR_PLLRDY);

	// PLLM == 4 (BIT2)
	// PLMN == 168
	// PLLP == 2
	// PLLQ == 7
	// PLLR == 2
	RCC->PLLCFGR = (RCC_PLLCFGR_PLLSRC_HSE | RCC_PLLCFGR_PLLM_2 | (168 << RCC_PLLCFGR_PLLN_Pos) | ((2 >> 1) - 1) << RCC_PLLCFGR_PLLP_Pos | ( 7 << RCC_PLLCFGR_PLLQ_Pos));

	//enable PLL
	RCC->CR |= RCC_CR_PLLON;
	while(!(RCC->CR & RCC_CR_PLLRDY));

	if((FLASH->ACR & FLASH_ACR_LATENCY) < FLASH_ACR_LATENCY_5WS)
	{
		FLASH->ACR |= FLASH_ACR_LATENCY_5WS;
		if((FLASH->ACR & FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_5WS)
		{
			return -1;
		}
	}

	//X3 why, but in HAL
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV16;
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV16;

	//ABHPresc = 1
	tmp = RCC->CFGR;
	tmp &= ~RCC_CFGR_HPRE;
	tmp |= RCC_CFGR_HPRE_DIV1;
	RCC->CFGR = tmp;

	//set PPL as systemclock
	tmp = RCC->CFGR;
	tmp &= RCC_CFGR_SW;
	tmp |= RCC_CFGR_SW_PLL;
	RCC->CFGR |= tmp;
	while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));

	if((FLASH->ACR & FLASH_ACR_LATENCY) < FLASH_ACR_LATENCY_5WS)
	{
		FLASH->ACR |= FLASH_ACR_LATENCY_5WS;
		if((FLASH->ACR & FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_5WS)
		{
			return -1;
		}
	}

	tmp = RCC->CFGR;
	tmp &= ~RCC_CFGR_PPRE1;
	tmp &= ~RCC_CFGR_PPRE2;
	tmp |= RCC_CFGR_PPRE1_DIV4;
	tmp |= RCC_CFGR_PPRE2_DIV2;
	RCC->CFGR = tmp;

	//RCC->APB1ENR |= RCC_APB1ENR_USBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

	SystemCoreClockUpdate();
	//	set systick timer to 1 ms delay
	SysTick_Config(SystemCoreClock / 200);

	return 0;
}

void initGPIO(void)
{
	GPIOD->MODER &= ~GPIO_MODER_MODER12;
	GPIOD->MODER  |= GPIO_MODER_MODER12_0; //gp output

	GPIOD->OTYPER &= ~GPIO_OTYPER_OT12; //push pull

	GPIOD->OSPEEDR |= GPIO_OSPEEDR_OSPEED12; //very h speed

	GPIOD->PUPDR &= ~GPIO_PUPDR_PUPD12; //no pull up or down

}

void sysInit(void)
{
	initRCC();
	initGPIO();
}
