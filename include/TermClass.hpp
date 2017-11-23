// default to degree of 1
#ifndef TERM_CLASS_HPP_
#define TERM_CLASS_HPP_

// external includes
#include <iostream>

class Term {
	private:
		char 		_coefficient;
		int			_degree;
		char		_symbol;
		std::string _type;

	public:
		Term();
		~Term();
		Term(char);
		Term(int);
		Term(std::pair<char, int>);
		void	say();

		// getters
		char 		getCoefficient();
		int 		getDegree();
		char		getSymbol();
		std::string getType();

		// setters
		void	setCoefficient(char);
		void	setDegree(int);
		void	setSymbol(char);
		void	setType(std::string);
};

#endif
