#include <algorithm>
#include <math.h>
#include "pwm_channel.h"

PwmChannel::PwmChannel(uint8_t *serialData, const uint8_t channelIndex, const uint32_t period, const uint8_t dutyCycle)
 	 : ChannelController(serialData, channelIndex),
	   pulsePeriod(getPulsePeriod(period, dutyCycle)),
	   delayPeriod(period - pulsePeriod),
	   pulseState(false),
	   processedTime(0),
	   waitTime(0)
{
}

void PwmChannel::updateState(const uint64_t currentTime)
{
	if (currentTime <= processedTime)
		return;

	if (waitTime <= 0) {
		pulseState = !pulseState;
		waitTime = pulseState ? pulsePeriod : delayPeriod;
		if (waitTime > 0)
			setChannelState(pulseState);
	}
	else {
		waitTime -= currentTime - processedTime;
	}

	processedTime = currentTime;
}

uint32_t PwmChannel::getPulsePeriod(const uint32_t period, const uint8_t dutyCycle)
{
	const uint8_t correctDutyCycle = std::min((uint8_t)MAX_DUTY_CYCLE, std::max((uint8_t)MIN_DUTY_CYCLE, dutyCycle));
	const float pulsePeriod = std::round((float)period * (float)correctDutyCycle / MAX_DUTY_CYCLE);
	return pulsePeriod;
}
