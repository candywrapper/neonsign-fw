#ifndef BOARD_TIMER_H_
#define BOARD_TIMER_H_

#include "timer_handler.h"

class Timer {
public:

	enum {
		TICK_PERIOD_US = 1000,
	};

	static void processTick();

	static void setIrqState(const bool state);

	void initialize(TimerHandler &timerHandler);

private:

	enum {
		CLOCK_FREQ = 48000000,
	};

	static TimerHandler *tHandler;

	inline void configureSysTick();

};

#endif /* BOARD_TIMER_H_ */
