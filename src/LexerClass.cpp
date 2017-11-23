#include <LexerClass.hpp>

Lexer::Lexer() {
	std::cout << "Lexer constructed with default method\n";
}

Lexer::Lexer(const char *expression) {
	std::cout << "Lexer constructed with (const char *) overload:\n"
		<< expression
		<< std::endl;

	std::istringstream ss(expression);
	std::string term;
	std::vector<std::string> terms;
	std::vector<std::string>::iterator it;

	// vector<Term>
	// while(ss) {
	// if (makeNeg = true) {
	//		makeNeg ?
	// }
	//	if (coefficients and degrees) {
	//		split these
	//		form pair
	//		create new term
	//		push term to vector
	//	}
	//	else if ('=') {
	//		bool makeNeg = true;
	//	}
	// }
	//
	while(std::getline(ss, term, ' '))
		terms.push_back(term);


	int i = 0;
	for (it = terms.begin(); it != terms.end(); it++) {
		if (std::regex_match(*it, std::regex("([A-Z])+\\^[0-2])"))) {
		
			std::istringstream tempSs(*it);
			std::string tempToken;
			std::vector<std::string> tempVec;
			std::pair<char, int> tempPair;

		//	std::cout << "match: " << *it << std::endl;

			while(std::getline(tempSs, tempToken, '^'))
				tempVec.push_back(tempToken);
			tempPair.first = tempVec[0][0];
			tempPair.second = tempVec[1][0] - 48;
			Term *termToPush = new Term(tempPair);
			_finalExpression.push_back(termToPush);
		}
		else if (isConstant(*it)) {
			Term *termToPush = new Term(strtod((*it).c_str(), nullptr));
			_finalExpression.push_back(termToPush);
		}
		else {
			Term *termToPush = new Term((*it)[0]);
			_finalExpression.push_back(termToPush);
		}
		i++;
	}

	std::vector<Term*>::iterator finalIt;
	for (finalIt = _finalExpression.begin(); finalIt != _finalExpression.end(); finalIt++) {
		(*finalIt)->sayClean();
	}
	std::cout << std::endl;

	/*
	 * organize vector into the correct order (leader, descending, etc...)
	 */
}

bool Lexer::isConstant(std::string input) {
	char *p;
	strtod(input.c_str(), &p);
	return *p == 0;
}

Lexer::~Lexer() {
	std::cout << "Lexer Destructed\n";
}

std::vector<Term*> Lexer::getExpression() {
	return this->_finalExpression;
}
