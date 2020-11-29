#include <algorithm>
#include "business_logic.h"
#include "stm32f0xx.h"
#include "channel_controller/active_channel.h"
#include "channel_controller/disactive_channel.h"
#include "channel_controller/random_channel.h"
#include "channel_controller/repeat_channel.h"
#include "channel_controller/invert_channel.h"


BusinessLogic::BusinessLogic()
	: currentTime(0),
	  serialInterface(nullptr),
	  modulesCount(MIN_MODULES_COUNT)
{
	Timer::setIrqState(true);
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

bool BusinessLogic::input(const uint32_t channelIndex)
{
	return di->getState(channelIndex);
}

void BusinessLogic::delay(const uint32_t timeout)
{
	const uint64_t startTime = currentTime;
	while (currentTime - startTime < (uint64_t)timeout);
}

void BusinessLogic::on(const uint32_t channelIndex)
{
	Timer::setIrqState(false);
	if (channelController[channelIndex] != nullptr)
		delete channelController[channelIndex];
	channelController[channelIndex] = new ActiveChannel(serialData, channelIndex);
	Timer::setIrqState(true);
}

void BusinessLogic::off(const uint32_t channelIndex)
{
	Timer::setIrqState(false);
	if (channelController[channelIndex] != nullptr)
		delete channelController[channelIndex];
	channelController[channelIndex] = new DisactiveChannel(serialData, channelIndex);
	Timer::setIrqState(true);
}

void BusinessLogic::random(const uint32_t channelIndex, const uint32_t min, const uint32_t max)
{
	Timer::setIrqState(false);
	if (channelController[channelIndex] != nullptr)
		delete channelController[channelIndex];
	channelController[channelIndex] = new RandomChannel(serialData, channelIndex, min, max);
	Timer::setIrqState(true);
}

void BusinessLogic::repeat(const uint32_t channelIndex, const uint32_t sourceChannelIndex)
{
	Timer::setIrqState(false);
	if (channelController[channelIndex] != nullptr)
		delete channelController[channelIndex];
	channelController[channelIndex] =  new RepeatChannel(serialData, channelIndex, sourceChannelIndex, &(channelController[sourceChannelIndex]));
	Timer::setIrqState(true);
}

void BusinessLogic::invert(const uint32_t channelIndex, const uint32_t sourceChannelIndex)
{
	Timer::setIrqState(false);
	if (channelController[channelIndex] != nullptr)
		delete channelController[channelIndex];
	channelController[channelIndex] =  new InvertChannel(serialData, channelIndex, sourceChannelIndex, &(channelController[sourceChannelIndex]));
	Timer::setIrqState(true);
}

void BusinessLogic::processTick()
{
	currentTime += TIMER_PERIOD_MSEC;
	processChannels();
	sendData();
}

void BusinessLogic::setInterface(SerialInterface &interface)
{
	serialInterface = &interface;
}

void BusinessLogic::setDi(Di &input)
{
	di = &input;
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
