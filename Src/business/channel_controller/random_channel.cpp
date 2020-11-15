#include <algorithm>
#include "random_channel.h"

RandomChannel::RandomChannel(uint8_t *serialData, const uint8_t channelIndex, const uint32_t min, const uint32_t max)
 	 : ChannelController(serialData, channelIndex),
	   m_min(min),
	   m_max(max),
	   processedTime(0),
	   waitTime(0)
{
}

void RandomChannel::updateState(const uint64_t currentTime)
{
	if (currentTime <= processedTime)
		return;

	if (waitTime <= 0) {
		waitTime = getRandomPeriod(m_min, m_max);
		toggleChannelState();
	}
	else {
		waitTime -= currentTime - processedTime;
	}

	processedTime = currentTime;
}

uint32_t RandomChannel::getRandomPeriod(const uint32_t min, const uint32_t max)
{
	return (std::rand() % (max - min)) + min;
}
