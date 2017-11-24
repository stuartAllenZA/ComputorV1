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
		double		_value;

	public:
		Term();
		~Term();
		Term(char);
		Term(double);
		Term(std::pair<char, int>);
		void	say();
		void	sayClean();

		// getters
		char 		getCoefficient();
		int 		getDegree();
		char		getSymbol();
		std::string getType();
		int			getConstValue();
		std::pair<char, int>	getCoefValue();

		// setters
		void	setCoefficient(char);
		void	setDegree(int);
		void	setSymbol(char);
		void	setType(std::string);
		void	setConstValue(int);
		void	setCoefValue(std::pair<char, int>);
};

#endif
