#include "stm32f0xx.h"
#include "device.h"

class Algorithm : public BusinessLogic {
public:
	void execute() override {
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
		GPIOA->OTYPER |= GPIO_OTYPER_OT_4;
		GPIOA->MODER |= GPIO_MODER_MODER4_0;
		GPIOA->PUPDR &= GPIO_PUPDR_PUPDR4_Msk;
		for(;;) {
			for(unsigned int j = 0; j < 112230; j++);
			GPIOA->ODR &= ~GPIO_ODR_4;

			for(unsigned int j = 0; j < 112230; j++);
			GPIOA->ODR |= GPIO_ODR_4;
		}
	}
};

int main(void)
{
	Algorithm algorithm;
	Device device(algorithm);
	device.operate();
}
