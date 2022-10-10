#include "set.hpp"
#include <set>
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
	std::cout << "get_allocator\n";

	std::cout << "ITERATORS\n";
	std::cout << "begin\n";
	std::cout << "end\n";
	std::cout << "rbegin\n";
	std::cout << "rend\n";

	std::cout << "CAPACITY\n";
	std::cout << "empty\n";
	std::cout << "size\n";
	std::cout << "max_size\n";

	std::cout << "MODIFIERS\n";
	std::cout << "clear\n";
	std::cout << "insert\n";
	std::cout << "erase\n";
	std::cout << "swap\n";

	std::cout << "LOOKUP\n";
	std::cout << "count\n";
	std::cout << "find\n";
	std::cout << "equal_range\n";
	std::cout << "lower_bound\n";
	std::cout << "upper_bound\n";

	std::cout << "OBSERVERS\n";
	std::cout << "key_comp\n";
	std::cout << "valu_comp\n";

	std::cout << "NON-MEMBER FUNCTIONS\n";
	std::cout << "swap\n";
	std::cout << "operator==\n";
	std::cout << "operator!=\n";
	std::cout << "operator<\n";
	std::cout << "operator>\n";
	std::cout << "operator<=\n";
	std::cout << "operator>=\n";

	return 0;
}