#include <algorithm>
#include "business_logic.h"
#include "stm32f0xx.h"
#include "timer.h"

BusinessLogic::BusinessLogic()
	: currentTime(0),
	  serialInterface(nullptr),
	  modulesCount(MIN_MODULES_COUNT)
{

}

void BusinessLogic::setModulesCount(const uint8_t count)
{
	modulesCount = std::min((uint8_t)MAX_MODULES_COUNT, std::max((uint8_t)MIN_MODULES_COUNT, count));
}

void BusinessLogic::delay(const uint32_t timeout)
{
	const uint64_t startTime = currentTime;
	while (currentTime - startTime < (uint64_t)timeout);
}

void BusinessLogic::on(const uint32_t channelIndex)
{
	uint8_t byteIndex = channelIndex / 8;
	uint8_t bitIndex = channelIndex % 8;
	serialData[byteIndex] |= (uint8_t)1 << bitIndex;
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
	currentTime += Timer::TICK_PERIOD_US;
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
		serialInterface->send(serialData, modulesCount);
}

void BusinessLogic::processChannels()
{

}
