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

	virtual uint32_t getModuleCount() = 0;

	virtual void execute() = 0;

	void processTick() override;

	void setInterface(SerialInterface &interface);

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

	enum {
		MAX_MODULE_COUNT = 8,
	};

	uint32_t currentTick;

	SerialInterface *serialInterface;

	uint8_t serialData[MAX_MODULE_COUNT];

	void sendData();

	void processChannels();

};

#endif /* BOARD_BUSINESS_LOGIC_H_ */
