#include "device.h"

class Algorithm : public BusinessLogic {
public:

	virtual uint32_t getModuleCount() {
		return 1;
	}

	void execute() override {
		for(;;) {
			delay(112230);
			setOff(0);
			delay(112230);
			setOn(0);
		}
	}

};


int main(void)
{
	Algorithm algorithm;
	Device device(algorithm);
	device.operate();
}
