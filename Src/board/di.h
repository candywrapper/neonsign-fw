#ifndef BOARD_DI_H_
#define BOARD_DI_H_

#include "stm32f0xx.h"

class Di {
public:

	void initialize();

	bool getState(const uint8_t index);

private:

	struct PortInfo {
		GPIO_TypeDef *port;
		uint32_t pupdrMask;
		uint32_t idrMask;
	};

	static PortInfo portInfo[];

	inline void configurePorts();

	inline uint32_t portCount();

};

#endif /* BOARD_DI_H_ */
