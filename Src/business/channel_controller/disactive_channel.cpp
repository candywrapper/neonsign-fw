#include "disactive_channel.h"

DisactiveChannel::DisactiveChannel(uint8_t *serialData, const uint8_t channelIndex)
 	 : ChannelController(serialData, channelIndex)
{
	setChannelState(false);
}

void DisactiveChannel::updateState(const uint64_t currentTime)
{

}
