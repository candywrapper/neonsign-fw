#include "algorithm.h"

uint32_t Algorithm::getModuleCount()
{
	return 1;
}

void Algorithm::execute()
{
	for(;;) {
		delay(500);
		off(0);
		delay(500);
		on(0);
	}
}
