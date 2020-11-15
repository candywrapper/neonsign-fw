#ifndef BOARD_BUSINESS_LOGIC_H_
#define BOARD_BUSINESS_LOGIC_H_

#include <stdint.h>
#include "timer_handler.h"
#include "spi.h"
#include "serial_interface.h"

class BusinessLogic : public TimerHandler {
public:

	BusinessLogic();

	virtual ~BusinessLogic() = default;

	virtual void execute() = 0;

	void processTick() override;

	void setInterface(SerialInterface &interface);

protected:

	void setModulesCount(const uint8_t count);

	void delay(const uint32_t timeout);

	void on(const uint32_t channelIndex);

	void off(const uint32_t channelIndex);

	void pwm(const uint32_t channelIndex, const uint32_t period, const uint32_t dutyCycle);

	void random(const uint32_t channelIndex, const uint32_t min, const uint32_t max);

	void repeat(const uint32_t channelIndex, const uint32_t sourceChannelIndex);

private:

	enum {
		MIN_MODULES_COUNT = 1,
		MAX_MODULES_COUNT = 16,
	};

	uint32_t currentTick;

	SerialInterface *serialInterface;

	uint8_t serialData[MAX_MODULES_COUNT];

	uint8_t modulesCount;

	void sendData();

	void processChannels();

};

#endif /* BOARD_BUSINESS_LOGIC_H_ */
