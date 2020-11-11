#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "business_logic.h"

class Algorithm : public BusinessLogic {
public:

	uint32_t getModuleCount() override;

	void execute() override;

};

#endif /* ALGORITHM_H_ */
