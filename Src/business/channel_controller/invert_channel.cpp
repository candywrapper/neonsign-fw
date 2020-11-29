#include "invert_channel.h"

InvertChannel::InvertChannel(uint8_t *serialData, const uint8_t channelIndex, const uint8_t sourceChannelIndex, ChannelController **sourceChannelController)
	: ChannelController(serialData, channelIndex),
	  m_sourceChannelController(sourceChannelController),
	  processedTime(0),
	  sourceByteIndex(sourceChannelIndex / 8),
	  sourceBitMask((uint8_t)1 << (sourceChannelIndex % 8)),
	  m_serialData(serialData)
{

}

void InvertChannel::updateState(const uint64_t currentTime)
{
	ChannelController *sourceController = *m_sourceChannelController;
	if (sourceController != nullptr)
		sourceController->updateState(currentTime);

	const bool sourceChannelState = (m_serialData[sourceByteIndex] & sourceBitMask) != 0;
	setChannelState(sourceChannelState);
}
