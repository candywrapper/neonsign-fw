#include "mcu.h"
#include "stm32f0xx.h"

TimerHandler *Mcu::tHandler = nullptr;

void Mcu::processTick()
{
	if (tHandler)
		tHandler->processTick();
}

void Mcu::processFault()
{
	for (;;);
}


void Mcu::initialize(TimerHandler &timerHandler)
{
	setHsi();
	setPortAClock();
	configurePortA4();
	configureSysTick(timerHandler);
}

void Mcu::setHsi()
{
	// Configure MCU clock to 48 MHz
	// PLLSRC - HCI/2
	RCC->CFGR |= RCC_CFGR_PLLMUL_1 | RCC_CFGR_PLLMUL_3; // PLLMUL - x12
	RCC->CR |= RCC_CR_PLLON; // enable PLL
	while (RCC->CR & RCC_CR_PLLRDY); // wait till unlocked PLL
	RCC->CFGR |= RCC_CFGR_SW_1; // SW - PLLCLK
	//AHB presscaler - x1
	//APB prescaler - x1
}

void Mcu::setPortAClock() {
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
}

void Mcu::configurePortA4() {
	// Open-drain without pullup and pulldown
	GPIOA->OTYPER |= GPIO_OTYPER_OT_4;
	GPIOA->MODER |= GPIO_MODER_MODER4_0;
	GPIOA->PUPDR &= GPIO_PUPDR_PUPDR4_Msk;
}

void Mcu::configureSysTick(TimerHandler &timerHandler) {
	tHandler = &timerHandler;
	SysTick_Config(CLOCK_FREQ / 1000); // 1 ms interrupt
}


extern "C" {
	void SysTick_Handler() { Mcu::processTick(); }

	void HardFault_Handler() { Mcu::processFault(); }

	void MemManage_Handler() { Mcu::processFault(); }

	void BusFault_Handler() { Mcu::processFault(); }

	void UsageFault_Handler() {	Mcu::processFault(); }
};
