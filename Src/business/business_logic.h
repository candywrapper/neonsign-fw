#ifndef BOARD_BUSINESS_LOGIC_H_
#define BOARD_BUSINESS_LOGIC_H_

#include <stdint.h>
#include "timer_handler.h"
#include "timer.h"
#include "spi.h"
#include "di.h"
#include "serial_interface.h"
#include "channel_controller/channel_controller.h"

class BusinessLogic : public TimerHandler {
public:

	BusinessLogic();

	virtual ~BusinessLogic();

	virtual void execute() = 0;

	void processTick() override;

	void setInterface(SerialInterface &interface);

	void setDi(Di &input);

protected:

	void setModulesCount(const uint8_t count);

	bool input(const uint32_t channelIndex);

	void delay(const uint32_t timeout);

	void on(const uint32_t channelIndex);

	void off(const uint32_t channelIndex);

	void random(const uint32_t channelIndex, const uint32_t min, const uint32_t max);

	void repeat(const uint32_t channelIndex, const uint32_t sourceChannelIndex);

	void invert(const uint32_t channelIndex, const uint32_t sourceChannelIndex);

private:

	enum {
		USEC_IN_MSEC = 1000,
		TIMER_PERIOD_MSEC = (Timer::TICK_PERIOD_US / USEC_IN_MSEC),
		MIN_MODULES_COUNT = 1,
		MAX_MODULES_COUNT = 8,
		MODULE_CHANNELS_COUNT = 8,
		MAX_CHANNELS = (MAX_MODULES_COUNT * MODULE_CHANNELS_COUNT)
	};

	uint64_t currentTime;

	SerialInterface *serialInterface;

	Di *di;

	uint8_t serialData[MAX_MODULES_COUNT];

	uint8_t modulesCount;

	ChannelController *channelController[MAX_CHANNELS];

	void sendData();

	void processChannels();

};

#endif /* BOARD_BUSINESS_LOGIC_H_ */
