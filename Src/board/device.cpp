#include "device.h"

Device::Device(BusinessLogic &businessLogic)
	: m_businessLogic(businessLogic)
{

}

void Device::operate()
{
	m_businessLogic.execute();
}
