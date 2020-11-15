#include <algorithm>
#include "business_logic.h"
#include "stm32f0xx.h"
#include "timer.h"
#include "channel_controller/active_channel.h"
#include "channel_controller/disactive_channel.h"
#include "channel_controller/pwm_channel.h"

BusinessLogic::BusinessLogic()
	: currentTime(0),
	  serialInterface(nullptr),
	  modulesCount(MIN_MODULES_COUNT)
{
	for (uint8_t i = 0; i < MAX_MODULES_COUNT * MODULE_CHANNELS_COUNT; i++)
		channelController[i] = nullptr;

}

BusinessLogic::~BusinessLogic()
{
	for (uint8_t i = 0; i < MAX_MODULES_COUNT * MODULE_CHANNELS_COUNT; i++)
		if (channelController[i] != nullptr)
			delete channelController[i];
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
	if (channelController[channelIndex] != nullptr)
		delete channelController[channelIndex];
	channelController[channelIndex] = new ActiveChannel(serialData, channelIndex);
}

void BusinessLogic::off(const uint32_t channelIndex)
{
	if (channelController[channelIndex] != nullptr)
		delete channelController[channelIndex];
	channelController[channelIndex] = new DisactiveChannel(serialData, channelIndex);
}


void BusinessLogic::pwm(const uint32_t channelIndex, const uint32_t period, const uint8_t dutyCycle)
{
	if (channelController[channelIndex] != nullptr)
		delete channelController[channelIndex];
	channelController[channelIndex] = new PwmChannel(serialData, channelIndex, period, dutyCycle);
}

void BusinessLogic::random(const uint32_t channelIndex, const uint32_t min, const uint32_t max)
{
	if (channelController[channelIndex] != nullptr)
		delete channelController[channelIndex];
	channelController[channelIndex] = nullptr;
}

void BusinessLogic::repeat(const uint32_t channelIndex, const uint32_t sourceChannelIndex)
{
	if (channelController[channelIndex] != nullptr)
		delete channelController[channelIndex];
	channelController[channelIndex] = nullptr;
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
	for (uint8_t i = 0; i < modulesCount * MODULE_CHANNELS_COUNT; i++)
		if (channelController[i] != nullptr)
			channelController[i]->updateState(currentTime);
}
