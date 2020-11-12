#ifndef BOARD_MCU_H_
#define BOARD_MCU_H_

class Mcu {
public:

	static void processFault();

	void initialize();

private:

	inline void setHsi();

	inline void setPortAClock();

	inline void setSpiClock();

};

#endif /* BOARD_MCU_H_ */
