#ifndef BOARD_BUSINESS_LOGIC_H_
#define BOARD_BUSINESS_LOGIC_H_

class BusinessLogic {
public:

	virtual ~BusinessLogic() = default;

	virtual void execute() = 0;

};

#endif /* BOARD_BUSINESS_LOGIC_H_ */
