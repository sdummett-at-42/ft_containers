#include "vector.hpp"
#include <vector>
#include <iostream>

#ifdef FT
using namespace ft;
#else
using namespace std;
#endif

int main()
{
	#ifdef FT
	std::cout << "FT\n";
	#else
	std::cout << "STD\n";
	#endif
	std::cout << "Launching vector tests\n\n";

	std::cout << "Constructor\n";
	std::cout << "Destructor\n";
	std::cout << "operator=\n";
	std::cout << "assign\n";
	std::cout << "get_allocator\n";

	std::cout << "ELEMENT ACCESS\n";
	std::cout << "at\n";
	std::cout << "operator[]\n";
	std::cout << "front\n";
	std::cout << "back\n";
	std::cout << "data\n";

	std::cout << "ITERATORS\n";
	std::cout << "begin\n";
	std::cout << "end\n";
	std::cout << "rbegin\n";
	std::cout << "rend\n";

	std::cout << "CAPACITY\n";
	std::cout << "empty\n";
	std::cout << "size\n";
	std::cout << "max_size\n";
	std::cout << "reserve\n";
	std::cout << "capacity\n";

	std::cout << "MODIFIERS\n";
	std::cout << "clear\n";
	std::cout << "insert\n";
	std::cout << "erase\n";
	std::cout << "push_back\n";
	std::cout << "pop_back\n";
	std::cout << "resize\n";
	std::cout << "swap\n";

	std::cout << "NON-MEMBER FUNCTIONS\n";
	std::cout << "operator==\n";
	std::cout << "operator!=\n";
	std::cout << "operator<\n";
	std::cout << "operator>\n";
	std::cout << "operator<=\n";
	std::cout << "operator>=\n";

	return (0);
}