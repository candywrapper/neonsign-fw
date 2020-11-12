#ifndef BOARD_BUSINESS_LOGIC_H_
#define BOARD_BUSINESS_LOGIC_H_

#include <stdint.h>
#include "timer_handler.h"

class BusinessLogic : public TimerHandler {
public:

	BusinessLogic();

	virtual ~BusinessLogic() = default;

	virtual uint32_t getModuleCount() = 0;

	virtual void execute() = 0;

	void processTick() override;

protected:

	/**
	 * @param timeout ms
	 */
	void delay(const uint32_t timeout);

	void on(const uint32_t channelIndex);

	void off(const uint32_t channelIndex);

	void pwm(const uint32_t channelIndex, const uint32_t period, const uint32_t dutyCycle);

	void random(const uint32_t channelIndex, const uint32_t min, const uint32_t max);

	void repeat(const uint32_t channelIndex, const uint32_t sourceChannelIndex);

private:

	uint32_t currentTick;

	void sendData();

	void processChannels();

};

#endif /* BOARD_BUSINESS_LOGIC_H_ */
