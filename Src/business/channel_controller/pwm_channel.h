#ifndef BUSINESS_CHANNEL_CONTROLLER_PWM_CHANNEL_H_
#define BUSINESS_CHANNEL_CONTROLLER_PWM_CHANNEL_H_

#include "channel_controller.h"

class PwmChannel : public ChannelController {
public:

	PwmChannel(uint8_t *serialData, const uint8_t channelIndex, const uint32_t period, const uint8_t dutyCycle);

	void updateState(const uint64_t currentTime) override;

private:

	enum {
		MIN_DUTY_CYCLE = 0,
		MAX_DUTY_CYCLE = 100,
	};

	const uint32_t pulsePeriod;

	const uint32_t delayPeriod;

	bool pulseState;

	uint64_t processedTime;

	int64_t waitTime;

	inline uint32_t getPulsePeriod(const uint32_t period, const uint8_t dutyCycle);

};

#endif /* BUSINESS_CHANNEL_CONTROLLER_PWM_CHANNEL_H_ */
