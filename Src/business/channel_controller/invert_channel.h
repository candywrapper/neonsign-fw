#ifndef BUSINESS_CHANNEL_CONTROLLER_INVERT_CHANNEL_H_
#define BUSINESS_CHANNEL_CONTROLLER_INVERT_CHANNEL_H_

#include "channel_controller.h"

class InvertChannel : public ChannelController {
public:

	InvertChannel(uint8_t *serialData, const uint8_t channelIndex, const uint8_t sourceChannelIndex, ChannelController **sourceChannelController);

	void updateState(const uint64_t currentTime) override;

private:

	ChannelController **m_sourceChannelController;

	uint64_t processedTime;

	const uint8_t sourceByteIndex;

	const uint8_t sourceBitMask;

	uint8_t *m_serialData;

};

#endif /* BUSINESS_CHANNEL_CONTROLLER_INVERT_CHANNEL_H_ */
