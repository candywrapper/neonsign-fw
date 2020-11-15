#include "timer.h"
#include "stm32f0xx.h"

TimerHandler *Timer::tHandler = nullptr;

void Timer::processTick()
{
	if (tHandler)
		tHandler->processTick();
}

void Timer::initialize(TimerHandler &timerHandler)
{
	configureSysTick();
	tHandler = &timerHandler;
}

void Timer::configureSysTick() {
	SysTick_Config(CLOCK_FREQ / 1000000 * TICK_PERIOD_US); // 100 us interrupt
}

extern "C" {

	void SysTick_Handler() { Timer::processTick(); }

};
