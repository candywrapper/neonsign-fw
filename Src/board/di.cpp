#include "di.h"

Di::PortInfo Di::portInfo[] = {
		{
			.port = GPIOA,
			.pupdrMask = GPIO_PUPDR_PUPDR9_0,
			.idrMask = GPIO_IDR_9
		},
		{
			.port = GPIOA,
			.pupdrMask = GPIO_PUPDR_PUPDR10_0,
			.idrMask = GPIO_IDR_10
		}
};

void Di::initialize()
{
	configurePorts();
}

bool Di::getState(const uint8_t index)
{
	return (index < portCount()) ? ((portInfo[index].port->IDR & portInfo[index].idrMask) == 0) : false;
}

void Di::configurePorts()
{
	for (uint8_t i = 0; i < portCount(); i++)
		portInfo[i].port->PUPDR |= portInfo[i].pupdrMask;
}

uint32_t Di::portCount()
{
	return sizeof(portInfo) / sizeof(PortInfo);
}
