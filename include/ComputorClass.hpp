#ifndef COMPUTOR_CLASS_HPP_
#define COMPUTOR_CLASS_HPP_

#include <vector>

#include <TermClass.hpp>

class Computor {
	private:
	public:
		Computor();
		~Computor();
		void	calculate(std::vector<Term*>);
};

#endif

