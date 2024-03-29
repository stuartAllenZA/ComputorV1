#include <header.hpp>

int main(int argc, char **argv) {
	if (argc == 2) {
		Lexer lexer(argv[1]);
		Computor computor;
		computor.calculate(lexer.getExpression());
	}
	else std::cout << "run with params\n";
}
