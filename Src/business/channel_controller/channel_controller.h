#ifndef BOARD_PROCESSORS_CHANNEL_CONTROLLER_H_
#define BOARD_PROCESSORS_CHANNEL_CONTROLLER_H_

#include <stdint.h>

class ChannelController {
public:

	ChannelController(uint8_t *serialData, const uint8_t channelIndex);

	virtual ~ChannelController() = default;

	virtual void updateState(const uint64_t currentTime) = 0;

protected:

	void setChannelState(const bool active);

	void toggleChannelState();

private:

	uint8_t *m_serialData;

	const uint8_t byteIndex;

	const uint8_t bitMask;

};

#endif /* BOARD_PROCESSORS_CHANNEL_CONTROLLER_H_ */
