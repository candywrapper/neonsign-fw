#include "di.h"

Di::PortInfo Di::portInfo[] = {
		{
			.port = GPIOA,
			.pupdrMask = GPIO_PUPDR_PUPDR9_0,
			.idrMask = GPIO_IDR_9,
			.prevState = false
		},
		{
			.port = GPIOA,
			.pupdrMask = GPIO_PUPDR_PUPDR10_0,
			.idrMask = GPIO_IDR_10,
			.prevState = false
		}
};

void Di::initialize()
{
	configurePorts();
	for (uint8_t i = 0; i < portCount(); i++)
        portInfo[i].prevState = getState(i);
}

bool Di::getState(const uint8_t index)
{
	return (index < portCount()) ? ((portInfo[index].port->IDR & portInfo[index].idrMask) == 0) : false;
}

bool Di::getRised(const uint8_t index)
{
    const bool currentState = getState(index);
    const bool rised = ((portInfo[index].prevState != currentState) && currentState);
    portInfo[index].prevState = currentState;
    return rised;
}

bool Di::getFallen(const uint8_t index)
{
    const bool currentState = getState(index);
    const bool fallen = ((portInfo[index].prevState != currentState) && (!currentState));
    portInfo[index].prevState = currentState;
    return fallen;
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
