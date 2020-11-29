#ifndef BOARD_DEVICE_H_
#define BOARD_DEVICE_H_

#include "business_logic.h"
#include "mcu.h"
#include "timer.h"
#include "spi.h"
#include "di.h"

class Device {
public:

	Device(BusinessLogic &businessLogic);

	void operate();

private:

	Mcu mcu;

	Timer timer;

	Spi spi;

	Di di;

	BusinessLogic &m_businessLogic;

};

#endif /* BOARD_DEVICE_H_ */
