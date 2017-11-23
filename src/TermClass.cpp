#include <TermClass.hpp>

Term::Term() {
	std::cout << "Term constructed by default method\n";
}

Term::~Term() {
	std::cout << "Term destructed\n";
}

Term::Term(char operation) {
	std::cout << "Term constructed with (char) overload:\n"
		<< operation
		<< std::endl;
}

Term::Term(int term) {
	std::cout << "Term constructed with (int) overload:\n"
		<< std::to_string(term)
		<< std::endl;
	this->_type = "constant";
}

Term::Term(std::pair<char, int> term) {
	std::cout << "Term constructed with (std::pair<char, int>) overload:\n"
		<< term.first << "^" << std::to_string(term.second)
		<< std::endl;
	this->_coefficient = term.first;
	this->_degree = term.second;
	this->_type = "coefficient";
}

void Term::say() {
	std::cout << "Coefficient: " << this->_coefficient
		<< " Degree: " << this->_degree << std::endl;
}
