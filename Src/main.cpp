#include "board/device.h"
#include "algorithm.h"

int main(void)
{
	Algorithm algorithm;
	Device device(algorithm);
	device.operate();
}
