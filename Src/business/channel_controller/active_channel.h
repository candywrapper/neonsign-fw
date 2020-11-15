#ifndef BOARD_CHANNEL_CONTROLLER_ACTIVE_CHANNEL_H_
#define BOARD_CHANNEL_CONTROLLER_ACTIVE_CHANNEL_H_

#include "channel_controller.h"

class ActiveChannel : public ChannelController {
public:

	ActiveChannel(uint8_t *serialData, const uint8_t channelIndex);

	void updateState(const uint64_t currentTime) override;

};

#endif /* BOARD_CHANNEL_CONTROLLER_ACTIVE_CHANNEL_H_ */
