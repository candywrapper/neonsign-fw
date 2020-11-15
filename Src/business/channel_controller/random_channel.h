#ifndef BUSINESS_CHANNEL_CONTROLLER_RANDOM_CHANNEL_H_
#define BUSINESS_CHANNEL_CONTROLLER_RANDOM_CHANNEL_H_

#include "channel_controller.h"

class RandomChannel : public ChannelController {
public:

	RandomChannel(uint8_t *serialData, const uint8_t channelIndex, const uint32_t min, const uint32_t max);

	void updateState(const uint64_t currentTime) override;

private:

	const uint32_t m_min;

	const uint32_t m_max;

	uint64_t processedTime;

	int64_t waitTime;

	inline uint32_t getRandomPeriod(const uint32_t min, const uint32_t max);
};

#endif /* BUSINESS_CHANNEL_CONTROLLER_RANDOM_CHANNEL_H_ */
