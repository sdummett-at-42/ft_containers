#include "stack.hpp"
#include <stack>
#include <iostream>

#ifdef FT
using namespace ft;
#else
using namespace std;
#endif

int main() {
	#ifdef FT
	std::cout << "FT\n";
	#else
	std::cout << "STD\n";
	#endif

	std::cout << "Launching vector tests\n\n";

	std::cout << "Constructor\n";
	std::cout << "Destructor\n";
	std::cout << "operator=\n";

	std::cout << "ELEMENT ACCESS\n";
	std::cout << "top\n";

	std::cout << "CAPACITY\n";
	std::cout << "empty\n";
	std::cout << "size\n";

	std::cout << "MODIFIERS\n";
	std::cout << "push\n";
	std::cout << "pop\n";

	std::cout << "NON-MEMBER FUNCTIONS\n";
	std::cout << "operator==\n";
	std::cout << "operator!=\n";
	std::cout << "operator<\n";
	std::cout << "operator>\n";
	std::cout << "operator<=\n";
	std::cout << "operator>=\n";

	return 0;
}