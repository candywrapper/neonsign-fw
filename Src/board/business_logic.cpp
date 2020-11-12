#include "business_logic.h"
#include "stm32f0xx.h"

BusinessLogic::BusinessLogic()
	: currentTick(0),
	  serialInterface(nullptr)
{

}

void BusinessLogic::delay(const uint32_t timeout)
{
	const uint32_t startTick = currentTick;
	while (currentTick - startTick < timeout);
}

void BusinessLogic::on(const uint32_t channelIndex)
{
	uint8_t byteIndex = channelIndex / 8;
	uint8_t bitIndex = channelIndex % 8;
	serialData[byteIndex] |= 1 << bitIndex;
}

void BusinessLogic::off(const uint32_t channelIndex)
{
	uint8_t byteIndex = channelIndex / 8;
	uint8_t bitIndex = channelIndex % 8;
	serialData[byteIndex] &= ~((uint8_t)1 << bitIndex);
}


void BusinessLogic::pwm(const uint32_t channelIndex, const uint32_t period, const uint32_t dutyCycle)
{

}

void BusinessLogic::random(const uint32_t channelIndex, const uint32_t min, const uint32_t max)
{

}

void BusinessLogic::repeat(const uint32_t channelIndex, const uint32_t sourceChannelIndex)
{

}

void BusinessLogic::processTick()
{
	currentTick++;
	processChannels();
	sendData();
}

void BusinessLogic::setInterface(SerialInterface &interface)
{
	serialInterface = &interface;
}

void BusinessLogic::sendData()
{
	if (serialInterface)
		serialInterface->send(serialData, getModuleCount());
}

void BusinessLogic::processChannels()
{

}
