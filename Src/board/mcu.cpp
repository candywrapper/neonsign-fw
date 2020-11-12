#include "mcu.h"
#include "stm32f0xx.h"

void Mcu::processFault()
{
	for (;;);
}

void Mcu::initialize()
{
	setHsi();
	setPortAClock();
	setSpiClock();
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

void Mcu::setSpiClock() {
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
}

extern "C" {

	void HardFault_Handler() { Mcu::processFault(); }

	void MemManage_Handler() { Mcu::processFault(); }

	void BusFault_Handler() { Mcu::processFault(); }

	void UsageFault_Handler() {	Mcu::processFault(); }
};
