#include <ComputorClass.hpp>

Computor::Computor(){}

Computor::~Computor(){}

void	Computor::calculate(std::vector<Term*> expression) {
	int count = 0;
	int firstConst, secondConst;
	firstConst = 0;
	secondConst = 0;
	std::pair<char, int> firstCoef, secondCoef;
	std::vector<Term*>::iterator it;
	for (it = expression.begin(); it != expression.end(); it++) {
		if (count == 0) {
			if ((*it)->getType() == "constant")
				firstConst = (*it)->getConstValue();
			count++;
		}
		else if (count == 1) {
			count++;
		}
		else if (count == 2) {
			count = 0;
		}
		(*it)->sayClean();
	}
	std::cout << std::endl;
}

/*
 * iterate through vector and execute in order
 * begin with looking for div, then mul, then add,the sub
 */
