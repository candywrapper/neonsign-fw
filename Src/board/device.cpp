#include "device.h"

Device::Device(BusinessLogic &businessLogic)
	: m_businessLogic(businessLogic)
{
	mcu.initialize();
	spi.initialize();
	m_businessLogic.setInterface(spi);
	timer.initialize(m_businessLogic);
}

void Device::operate()
{
	m_businessLogic.execute();
}
