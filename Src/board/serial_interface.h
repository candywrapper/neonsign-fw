#ifndef BOARD_SERIAL_INTERFACE_H_
#define BOARD_SERIAL_INTERFACE_H_


class SerialInterface {
public:

	virtual void send(const uint8_t *data, uint8_t length) = 0;

};

#endif /* BOARD_SERIAL_INTERFACE_H_ */
