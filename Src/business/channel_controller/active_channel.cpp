#include "active_channel.h"

ActiveChannel::ActiveChannel(uint8_t *serialData, const uint8_t channelIndex)
 	 : ChannelController(serialData, channelIndex)
{
	setChannelState(true);
}

void ActiveChannel::updateState(const uint64_t currentTime)
{

}
