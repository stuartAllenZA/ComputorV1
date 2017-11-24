#include <TermClass.hpp>

Term::Term() {
//	std::cout << "Term constructed by default method\n";
}

Term::~Term() {
//	std::cout << "Term destructed\n";
}

Term::Term(char operation) {
//	std::cout << "Term constructed with (char) overload:\n"
//		<< operation
//		<< std::endl;
	this->_symbol = operation;
	this->_type = "operation";
}

Term::Term(double term) {
//	std::cout << "Term constructed with (int) overload:\n"
//		<< std::to_string(term)
//		<< std::endl;
	this->_value = term;
	this->_type = "constant";
}

Term::Term(std::pair<char, int> term) {
//	std::cout << "Term constructed with (std::pair<char, int>) overload:\n"
//		<< term.first << "^" << std::to_string(term.second)
//		<< std::endl;
	/*
	std::cout << "Here: value is: " << term.second << std::endl;
	if (term.second > 2) {
		std::cout << "error\n";
	}
	*/

	if (term.second == 0) {
		this->_value = 1;
		this->_type = "constant";
	}

	else {
		this->_coefficient = term.first;
		this->_degree = term.second;
		this->_type = "coefficient";
	}
}

void Term::say() {
	if (this->_type == "coefficient") {
	std::cout << "Coefficient: " << this->_coefficient
		<< " Degree: " << this->_degree << std::endl;
	}
	else if (this->_type == "constant")
	   std::cout << "Value: " << this->_value << std::endl;	
	else std::cout << "Operator: " << this->_symbol << std::endl;
}

void Term::sayClean() {
	if (this->_type == "coefficient") {
	std::cout << this->_coefficient << "^" << this->_degree << " ";
	}
	else if (this->_type == "constant")
	   std::cout << this->_value << " ";	
	else std::cout << this->_symbol << " ";
}

std::string	Term::getType() {
	return this->_type;
}

int		Term::getConstValue() {
	return this->_value;
}

std::pair<char, int>	Term::getCoefValue(){
	std::pair<char, int> temp;
	temp.first = this->_coefficient;
	temp.second = this->_degree;
	return temp;
}
