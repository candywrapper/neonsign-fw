#include "device.h"

Device::Device(BusinessLogic &businessLogic)
	: m_businessLogic(businessLogic)
{
	mcu.initialize();
	spi.initialize();
	di.initialize();
	m_businessLogic.setInterface(spi);
	m_businessLogic.setDi(di);
	timer.initialize(m_businessLogic);
}

void Device::operate()
{
	m_businessLogic.execute();
}
