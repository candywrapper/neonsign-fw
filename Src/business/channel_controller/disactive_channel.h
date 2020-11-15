#ifndef BOARD_CHANNEL_CONTROLLER_DISACTIVE_CHANNEL_H_
#define BOARD_CHANNEL_CONTROLLER_DISACTIVE_CHANNEL_H_

#include "channel_controller.h"

class DisactiveChannel : public ChannelController {
public:

	DisactiveChannel(uint8_t *serialData, const uint8_t channelIndex);

	void updateState(const uint64_t currentTime) override;

};

#endif /* BOARD_CHANNEL_CONTROLLER_DISACTIVE_CHANNEL_H_ */
