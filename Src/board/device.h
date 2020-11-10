#ifndef BOARD_DEVICE_H_
#define BOARD_DEVICE_H_

#include "business_logic.h"

class Device {
public:

	Device(BusinessLogic &businessLogic);

	void operate();

private:

	BusinessLogic &m_businessLogic;

};

#endif /* BOARD_DEVICE_H_ */
