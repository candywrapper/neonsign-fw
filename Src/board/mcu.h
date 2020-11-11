#ifndef BOARD_MCU_H_
#define BOARD_MCU_H_

#include "timer_handler.h"

class Mcu {
public:

	static void processTick();

	static void processFault();

	void initialize(TimerHandler &timerHandler);

private:

	enum {
		CLOCK_FREQ = 48000000,
	};

	static TimerHandler *tHandler;

	inline void setHsi();

	inline void setPortAClock();

	inline void configurePortA4();

	inline void configureSysTick(TimerHandler &timerHandler);

};

#endif /* BOARD_MCU_H_ */
