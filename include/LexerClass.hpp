#ifndef LEXER_CLASS_HPP_
#define LEXER_CLASS_HPP_

// external includes
#include <iostream>
#include <vector>
#include <sstream>
#include <regex>

// internal includes
#include <TermClass.hpp>

class Lexer {
	private:
		std::vector<Term*> _finalExpression;

	public:
		Lexer();
		~Lexer();
		Lexer(const char *);
		bool isConstant(std::string);
		std::vector<Term*> getExpression();
};

#endif

