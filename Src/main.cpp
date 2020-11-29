#include "board/device.h"
#include "algorithm.h"
#include "stm32f0xx.h"

int main(void)
{
	Algorithm algorithm;
	Device device(algorithm);
	device.operate();
}
