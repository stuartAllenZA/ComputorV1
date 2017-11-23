#include <ComputorClass.hpp>

Computor::Computor(){}

Computor::~Computor(){}

void	Computor::calculate(std::vector<Term*> expression) {
	std::vector<Term*>::iterator it;
	for (it = expression.begin(); it != expression.end(); it++) {
		(*it)->sayClean();
	}
}

/*
 * iterate through vector and execute in order
 * begin with looking for div, then mul, then add,the sub
 */
