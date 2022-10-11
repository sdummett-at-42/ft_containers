#include "vector.hpp"
#include <vector>
#include <iostream>
#include <list>
#include <string>

#ifdef FT
using namespace ft;
#else
using namespace std;
#endif

void	print_int_vector(vector<int> vec) {
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) 
		std::cout << *it << " ";
	std::cout << "\n";
}

int main()
{

	#ifdef FT
	std::cout << "FT\n";
	#else
	std::cout << "STD\n";
	#endif
	std::cout << "Launching vector tests\n\n";

	std::list<std::string> listr;
	listr.push_back("Hello");
	listr.push_back("world");
	listr.push_back("from");
	listr.push_back("42");

	std::list<int> liint;
	liint.push_back(50);
	liint.push_back(51);
	liint.push_back(52);
	liint.push_back(53);
	liint.push_back(54);
	liint.push_back(55);
	liint.push_back(56);
	liint.push_back(57);
	liint.push_back(58);
	liint.push_back(59);
	liint.push_back(59);
	liint.push_back(60);

	vector<int>::size_type i;
	vector<int>::iterator it;
	vector<int>::iterator ite;
	vector<int>::reverse_iterator rit;
	vector<int>::reverse_iterator rite;

	/* ------------- Constructor ------------- */
	std::cout << "Constructor\n";
		vector<int> vec1;
		vector<int> vec2(42, 42);
		vector<std::string> vec3(listr.begin(), listr.end());
		vector<int> vec4(vec1);

	/* ------------- Destructor ------------- */
	/* All the containers will be destroyed at the end.
	** If something wrong happen, we will now at compilation
	** or at runtime.
	*/

	/* ------------- operator= ------------- */
	std::cout << "operator=\n";
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(4);
	vec4 = vec1;
	for (vector<int>::iterator it = vec4.begin(); it != vec4.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	/* ------------- assign ------------- */
	std::cout << "assign\n";
	vec4.assign(12, 1337);
	for (vector<int>::iterator it = vec4.begin(); it != vec4.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	vec4.assign(liint.begin(), liint.end());
	for (vector<int>::iterator it = vec4.begin(); it != vec4.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	std::cout << "get_allocator\n";

	std::cout << "ELEMENT ACCESS\n";
	std::cout << "at\n";
	i = 0;
	while (i < vec4.size()) {
		std::cout << vec4.at(i) << " ";
		i++;
	}
	std::cout << "\n\n";

	std::cout << "operator[]\n";
	i = 0;
	while (i < vec4.size()) {
		std::cout << vec4[i] << " ";
		i++;
	}
	std::cout << "\n\n";

	std::cout << "front\n";
	std::cout << vec4.front() << "\n\n";

	std::cout << "back\n";
	while (vec4.size()) {
		std::cout << vec4.back() << " ";
		vec4.pop_back();
	}

	std::cout << "data\n";
	vec4.assign(liint.begin(), liint.end());
	vector<int>::pointer ptr = vec4.data();
	for (vector<int>::size_type i = 0; i < vec4.size(); i++) {
		std::cout << *(ptr + i) << " ";
	}
	std::cout << "\n\n";

	std::cout << "ITERATORS\n";
	std::cout << "begin\n";
	it = vec4.begin();
	std::cout << *it << "\n";
	std::cout << *(it + 1) << "\n\n";

	std::cout << "end\n";
	ite = vec4.end();
	std::cout << *(ite - 1) << "\n";
	for (; it != ite; it++) 
		std::cout << *it << " ";
	std::cout << "\n\n";

	std::cout << "rbegin\n";
	rit = vec4.rbegin();
	std::cout << *rit << "\n";
	std::cout << *(rit + 1) << "\n\n";

	std::cout << "rend\n";
	rite = vec4.rend();
	std::cout << *(rite - 1) << "\n";
	for (; rit != rite; rit++) 
		std::cout << *rit << " ";
	std::cout << "\n\n";

	std::cout << "CAPACITY\n";
	std::cout << "empty\n";
	std::cout << vec4.empty() << "\n";
	vec4.clear();
	std::cout << vec4.empty() << "\n\n";

	std::cout << "size\n";
	std::cout << vec4.size() << "\n";
	vec4.assign(liint.begin(), liint.end());
	std::cout << vec4.size() << "\n\n";

	std::cout << "max_size\n";
	std::cout << vec4.max_size() << "\n\n";

	std::cout << "reserve\n";
	vec4.reserve(42);

	std::cout << "capacity\n";
	std::cout << vec4.capacity() << "\n\n";

	std::cout << "MODIFIERS\n";
	std::cout << "clear\n";
	vec4.clear();
	std::cout << vec4.empty() << "\n";

	std::cout << "insert\n";
	vec4.assign(liint.begin(), liint.end());
	print_int_vector(vec4);
	it = vec4.begin();
	vec4.insert(it + 5, 234234);
	print_int_vector(vec4);
	vec4.insert(it + 2, 7, 1337);
	print_int_vector(vec4);
	std::cout << "\n";

	std::cout << ";erase\n";
	it = vec4.erase(it);
	print_int_vector(vec4);
	vec4.erase(it, it + 5);
	print_int_vector(vec4);
	std::cout << "\n";

	std::cout << "push_back\n";
	vec4.push_back(42);
	vec4.push_back(21);
	vec4.push_back(63);
	print_int_vector(vec4);
	std::cout << "\n";

	std::cout << "pop_back\n";
	vec4.pop_back();
	vec4.pop_back();
	print_int_vector(vec4);
	std::cout << "\n";

	std::cout << "resize\n";
	vec4.resize(2);
	print_int_vector(vec4);
	vec4.resize(11, 42);
	print_int_vector(vec4);
	std::cout << "\n";

	std::cout << "swap\n";
	print_int_vector(vec1);
	print_int_vector(vec4);
	vec4.swap(vec1);
	print_int_vector(vec1);
	print_int_vector(vec4);
	std::cout << "\n";

	std::cout << "NON-MEMBER FUNCTIONS\n";
	std::cout << "operator==\n";
	vec2 = vec4;
	if (vec4 == vec2)
		std::cout << "vec4 == vec2\n\n";
	std::cout << "operator!=\n";
	if (vec4 != vec2)
		std::cout << "vec4 != vec2\n\n";
	if (vec1 != vec4)
		std::cout << "vec1 != vec4\n\n";
	std::cout << "operator<\n";
	if (vec1 < vec4)
		std::cout << "vec1 < vec4\n\n";
	std::cout << "operator>\n";
	if (vec1 > vec4)
		std::cout << "vec1 > vec4\n\n";
	std::cout << "operator<=\n";
	if (vec1 <= vec4)
		std::cout << "vec1 <= vec4\n\n";
	std::cout << "operator>=\n";
	if (vec1 >= vec4)
		std::cout << "vec1 >= vec4\n\n";

	return (0);
}