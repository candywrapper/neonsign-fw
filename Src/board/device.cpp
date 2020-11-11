#include "device.h"
#include "mcu.h"

Device::Device(BusinessLogic &businessLogic)
	: m_businessLogic(businessLogic)
{
	Mcu mcu;
	mcu.initialize(businessLogic);
}

void Device::operate()
{
	m_businessLogic.execute();
}
