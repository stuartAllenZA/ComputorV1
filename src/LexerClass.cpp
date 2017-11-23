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

	std::vector<Term*> finalExpression;

	int i = 0;
	for (it = terms.begin(); it != terms.end(); it++) {
		if (std::regex_match(*it, std::regex("([A-Z])+\\^[0-2])"))) {
		
			std::istringstream tempSs(*it);
			std::string tempToken;
			std::vector<std::string> tempVec;
			std::pair<char, int> tempPair;

			std::cout << "match: " << *it << std::endl;

			while(std::getline(tempSs, tempToken, '^'))
				tempVec.push_back(tempToken);
			tempPair.first = tempVec[0][0];
			tempPair.second = tempVec[1][0] - 48;
			Term *termToPush = new Term(tempPair);
			finalExpression.push_back(termToPush);
		}
		i++;
	}

	std::vector<Term*>::iterator finalIt;
	for (finalIt = finalExpression.begin(); finalIt != finalExpression.end(); finalIt++)
		(*finalIt)->say();

	/*
	 * organize vector into the correct order (leader, descending, etc...)
	 */
}

Lexer::~Lexer() {
	std::cout << "Lexer Destructed\n";
}
