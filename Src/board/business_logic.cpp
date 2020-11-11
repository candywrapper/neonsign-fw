#include "business_logic.h"
#include "stm32f0xx.h"

BusinessLogic::BusinessLogic()
	: currentTick(0)
{

}

void BusinessLogic::delay(const uint32_t timeout)
{
	const uint32_t startTick = currentTick;
	while (currentTick - startTick < timeout);
}

void BusinessLogic::on(const uint32_t channel)
{
	GPIOA->ODR &= ~GPIO_ODR_4;
}

void BusinessLogic::off(const uint32_t channel)
{
	GPIOA->ODR |= GPIO_ODR_4;
}


void BusinessLogic::pwm(const uint32_t channel, const uint32_t period, const uint32_t dutyCycle)
{

}

void BusinessLogic::random(const uint32_t channel, const uint32_t min, const uint32_t max)
{

}

void BusinessLogic::repeater(const uint32_t channel, const uint32_t sourceChannel)
{

}

void BusinessLogic::processTick()
{
	currentTick++;
	processChannels();
	sendData();
}

void BusinessLogic::sendData()
{

}

void BusinessLogic::processChannels()
{

}
