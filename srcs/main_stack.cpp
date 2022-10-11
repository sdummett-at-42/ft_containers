#include "stack.hpp"
#include <stack>
#include <iostream>
#include <list>

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

	std::list<int> li;
	li.push_back(1);
	li.push_back(2);
	li.push_back(3);

	std::cout << "Launching stack tests\n\n";

	/* ------------- Constructor ------------- */
	std::cout << "Constructor\n";
	stack<int> sta1;
	sta1.push(42);
	sta1.push(41);
	sta1.push(40);
	sta1.push(39);
	stack<int> sta2(sta1); 
	stack<int, std::list<int>> sta3(li);
	stack<int> sta4;
	std::cout << "\n";

	/* ------------- Destructor ------------- */
	/* All the containers will be destroyed at the end.
	** If something wrong happen, we will now at compilation
	** or at runtime.
	*/

	/* ------------- operator= ------------- */
	std::cout << "operator=\n";
	sta4 = sta1;
	while (sta4.size()) {
		std::cout << sta4.top() << " ";
		sta4.pop();
	}
	std::cout << "\n\n";

	std::cout << "ELEMENT ACCESS\n";
	/* ------------- top ------------- */
	std::cout << "top\n";
	while (sta1.size()) {
		std::cout << sta1.top() << " ";
		sta1.pop();
	}
	std::cout << "\n\n";

	std::cout << "CAPACITY\n";
	/* ------------- empty ------------- */
	std::cout << "empty\n";
	std::cout << sta1.empty() << "\n";
	std::cout << sta2.empty() << "\n";
	std::cout << sta3.empty() << "\n";
	std::cout << sta4.empty() << "\n";
	std::cout << "\n";

	/* ------------- size ------------- */
	std::cout << "size\n";
	std::cout << sta1.size() << "\n";
	std::cout << sta2.size() << "\n";
	std::cout << sta3.size() << "\n";
	std::cout << sta4.size() << "\n";
	std::cout << "\n";

	std::cout << "MODIFIERS\n";
	/* ------------- push ------------- */
	std::cout << "push\n";
	sta1.push(1337);
	sta1.push(1338);
	sta1.push(1339);
	sta1.push(1340);
	sta1.push(1341);
	while (sta1.size()) {
		std::cout << sta1.top() << " ";
		sta1.pop();
	}

	/* ------------- pop ------------- */
	std::cout << "pop\n";
	while (sta1.size()) {
		std::cout << sta1.top() << " ";
		sta1.pop();
	}
	std::cout << "\n";

	std::cout << "NON-MEMBER FUNCTIONS\n";
	sta4 = sta2;
	/* ------------- operator== ------------- */
	std::cout << "operator==\n";
	if (sta4 == sta2)
		std::cout << "sta4 == sta2\n";
	if (sta1 == sta2)
		std::cout << "sta1 == sta2\n";
	std::cout << "\n";

	/* ------------- operator!= ------------- */
	std::cout << "operator!=\n";
	if (sta4 != sta2)
		std::cout << "sta4 != sta2\n";
	if (sta1 != sta2)
		std::cout << "sta1 != sta2\n";
	std::cout << "\n";

	/* ------------- operator< ------------- */
	std::cout << "operator<\n";
	if (sta4 < sta2)
		std::cout << "sta4 < sta2\n";
	if (sta1 < sta2)
		std::cout << "sta1 < sta2\n";
	std::cout << "\n";

	/* ------------- operator> ------------- */
	std::cout << "operator>\n";
	if (sta4 > sta2)
		std::cout << "sta4 > sta2\n";
	if (sta1 > sta2)
		std::cout << "sta1 > sta2\n";
	std::cout << "\n";

	/* ------------- operator<= ------------- */
	std::cout << "operator<=\n";
	if (sta4 <= sta2)
		std::cout << "sta4 <= sta2\n";
	if (sta1 <= sta2)
		std::cout << "sta1 <= sta2\n";
	std::cout << "\n";

	/* ------------- operator>= ------------- */
	std::cout << "operator>=\n";
	if (sta4 >= sta2)
		std::cout << "sta4 >= sta2\n";
	if (sta1 >= sta2)
		std::cout << "sta1 >= sta2\n";
	std::cout << "\n";

	return 0;
}