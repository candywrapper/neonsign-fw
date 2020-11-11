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

void BusinessLogic::setOn(const uint32_t channel)
{
	GPIOA->ODR &= ~GPIO_ODR_4;
}

void BusinessLogic::setOff(const uint32_t channel)
{
	GPIOA->ODR |= GPIO_ODR_4;
}


void BusinessLogic::setPwm(const uint32_t channel, const uint32_t period, const uint32_t dutyCycle)
{

}

void BusinessLogic::setRandom(const uint32_t channel, const uint32_t min, const uint32_t max)
{

}

void BusinessLogic::setRepeater(const uint32_t channel, const uint32_t sourceChannel)
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
