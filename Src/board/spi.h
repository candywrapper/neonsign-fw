#ifndef BOARD_SPI_H_
#define BOARD_SPI_H_

#include <stdint.h>
#include "serial_interface.h"

class Spi : public SerialInterface {
public:

	void send(const uint8_t *data, uint8_t length) override;

	void initialize();

private:

	inline void configureMosiPort();

	inline void configureClkPort();

	inline void configureNssPort();

	inline void configureInterface();

};

#endif /* BOARD_SPI_H_ */
