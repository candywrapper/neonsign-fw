#ifndef BOARD_MCU_H_
#define BOARD_MCU_H_

class Mcu {
public:

	void initialize();

private:

	inline void setHsi();

	inline void setPortAClock();

	inline void setPortA4();

};

#endif /* BOARD_MCU_H_ */
