#include "channel_controller.h"

ChannelController::ChannelController(uint8_t *serialData, const uint8_t channelIndex)
	: m_serialData(serialData),
	  byteIndex(channelIndex / 8),
	  bitMask((uint8_t)1 << (channelIndex % 8))
{

}

void ChannelController::setChannelState(const bool active)
{
	if (active)
		m_serialData[byteIndex] &= ~bitMask;
	else
		m_serialData[byteIndex] |= bitMask;
}
