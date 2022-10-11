#include "set.hpp"
#include <set>
#include <iostream>

#ifdef FT
using namespace ft;
#else
using namespace std;
#endif

void	print_set(set<int> mp) {
	for (set<int>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

int main() {
	#ifdef FT
	std::cout << "FT\n";
	#else
	std::cout << "STD\n";
	#endif
	std::cout << "Launching set tests\n\n";

	set<int> mp4;
	mp4.insert(2);
	mp4.insert(3);
	mp4.insert(4);
	mp4.insert(5);
	mp4.insert(6);
	mp4.insert(7);
	mp4.insert(8);
	mp4.insert(9);
	mp4.insert(10);
	mp4.insert(11);
	mp4.insert(12);
	mp4.insert(13);

	set<int>::iterator			it;
	set<int>::iterator			ite;
	set<int>::reverse_iterator	rit;
	set<int>::reverse_iterator	rite;

	/* ------------- Constructor ------------- */
	std::cout << "Constructor\n";
	set<int> mp1;
	set<int> mp2(mp4.begin(), mp4.end());
	set<int> mp3(mp2);
	std::cout << "\n";

	/* ------------- Destructor ------------- */
	/* All the containers will be destroyed at the end.
	** If something wrong happen, we will now at compilation
	** or at runtime.
	*/

	/* ------------- operator= ------------- */
	std::cout << "operator=\n";
	print_set(mp1);
	print_set(mp3);
	mp1 = mp3;
	print_set(mp1);
	print_set(mp3);
	std::cout << "\n";

	/* ------------- get_allocator ------------- */
	std::cout << "get_allocator\n";
	set<int>::allocator_type alloc = mp3.get_allocator();
	std::cout << "\n";

	std::cout << "ITERATORS\n";
	/* ------------- begin ------------- */
	std::cout << "begin\n";
	it = mp1.begin();
	std::cout << *it << "\n";
	std::cout << *(it++) << "\n\n";

	/* ------------- end ------------- */
	std::cout << "end\n";
	ite = mp1.end();
	std::cout << *(it--) << "\n";
	for (; it != ite; it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	/* ------------- rbegin ------------- */
	std::cout << "rbegin\n";
	rit = mp1.rbegin();
	std::cout << *rit << "\n";
	std::cout << *(rit++) << "\n\n";

	/* ------------- rend ------------- */
	std::cout << "rend\n";
	rite = mp1.rend();
	std::cout << *(rit--) << "\n";
	for (; rit != rite; rit++)
		std::cout << *rit << " ";
	std::cout << "\n\n";

	std::cout << "rend\n";

	std::cout << "CAPACITY\n";
	/* ------------- empty ------------- */
	std::cout << "empty\n";
	mp3.clear();
	std::cout << mp1.empty() << "\n";
	std::cout << mp2.empty() << "\n";
	std::cout << mp3.empty() << "\n";
	std::cout << mp4.empty() << "\n";
	std::cout << "\n";

	/* ------------- size ------------- */
	std::cout << "size\n";
	std::cout << mp1.size() << "\n";
	std::cout << mp2.size() << "\n";
	std::cout << mp3.size() << "\n";
	std::cout << mp4.size() << "\n";
	std::cout << "\n";

	/* ------------- max_size ------------- */
	std::cout << "max_size\n";
	std::cout << mp1.max_size() << "\n\n";

	std::cout << "MODIFIERS\n";
/* ------------- clear ------------- */
	std::cout << "clear\n";
	std::cout << mp2.size() << "\n";
	mp2.clear();
	std::cout << mp2.size() << "\n\n";	

	/* ------------- insert ------------- */
	std::cout << "insert\n";
	pair<set<int>::iterator, bool> pr;
	pr = mp1.insert(24646);
	std::cout << *(pr.first) << " " <<
	*(pr.first) << " " <<
	pr.second << "\n";

	print_set(mp4);
	mp1.insert(mp4.begin(), mp4.end());
	print_set(mp4);
	std::cout << "\n";

	/* ------------- erase ------------- */
	std::cout << "erase\n";
	it = mp4.begin();
	print_set(mp4);
	mp4.erase(it);
	print_set(mp4);
	it = mp4.begin();
	ite = it;
	ite++; ite++; ite++; ite++;
	mp4.erase(it, ite);
	print_set(mp4);
	std::cout << "\n";

	/* ------------- swap ------------- */
	std::cout << "swap\n";
	print_set(mp1);
	print_set(mp4);
	mp1.swap(mp4);
	print_set(mp1);
	print_set(mp4);
	std::cout << "\n";

	std::cout << "LOOKUP\n";
	/* ------------- count ------------- */
	std::cout << "count\n";
	mp4.insert(243);
	std::cout << mp4.count(243) << "\n";
	std::cout << mp4.count(245) << "\n\n";

	/* ------------- find ------------- */
	std::cout << "find\n";
	it = mp4.find(243);
	if (it != mp4.end())
		std::cout << "iterator to the pair returned (key found)\n";
	else
		std::cout << "iterator to end() returned (key not found)\n";
	it = mp4.find(245);
	if (it != mp4.end())
		std::cout << "iterator to the pair returned (key found)\n";
	else
		std::cout << "iterator to end() returned (key not found)\n";
	std::cout << "\n";

	/* ------------- equal_range ------------- */
	std::cout << "equal_range\n";
	pair<set<int>::iterator,set<int>::iterator> prit;
	prit = mp4.equal_range(12);
	it = prit.first;
	ite = prit.second;
	for (; it != ite; it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	/* ------------- lower_bound ------------- */
	std::cout << "lower_bound\n";
	it = mp4.lower_bound(12);
	for (; it != mp4.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	/* ------------- upper_bound ------------- */
	std::cout << "upper_bound\n";
	it = mp4.lower_bound(78);
	for (; it != mp4.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n\n";

	std::cout << "OBSERVERS\n";
	/* ------------- key_comp ------------- */
	std::cout << "key_comp\n";
	set<int>::key_compare kc = mp4.key_comp();
	std::cout << "\n";

	/* ------------- value_comp ------------- */
	std::cout << "value_comp\n";
	set<int>::value_compare vc = mp4.value_comp();
	std::cout << "\n";

	std::cout << "NON-MEMBER FUNCTIONS\n";
	/* ------------- swap ------------- */
	std::cout << "swap\n";
	print_set(mp1);
	print_set(mp3);
	swap(mp4, mp1);
	print_set(mp1);
	print_set(mp3);
	std::cout << "\n";

	/* ------------- operator== ------------- */
	std::cout << "operator==\n";
	if (mp4 == mp1)
		std::cout << "mp4 == mp1\n";
	else
		std::cout << "mp4 != mp1\n";
	if (mp2 == mp3)
		std::cout << "mp2 == mp3\n";
	else
		std::cout << "mp2 != mp3\n";
	std::cout << "\n";

	/* ------------- operator!= ------------- */
	std::cout << "operator!=\n";
	if (mp4 == mp1)
		std::cout << "mp4 == mp1\n";
	else
		std::cout << "mp4 == mp1\n";
	if (mp2 == mp3)
		std::cout << "mp2 == mp3\n";
	else
		std::cout << "mp2 == mp3\n";
	std::cout << "\n";

	/* ------------- operator< ------------- */
	std::cout << "operator<\n";
	if (mp4 < mp1)
		std::cout << "mp4 < mp1\n";
	if (mp2 < mp3)
		std::cout << "mp2 < mp3\n";
	std::cout << "\n";

	/* ------------- operator> ------------- */
	std::cout << "operator>\n";
	if (mp4 > mp1)
		std::cout << "mp4 > mp1\n";
	if (mp2 > mp3)
		std::cout << "mp2 > mp3\n";
	std::cout << "\n";

	/* ------------- operator<= ------------- */
	std::cout << "operator<=\n";
	if (mp4 <= mp1)
		std::cout << "mp4 <= mp1\n";
	if (mp2 <= mp3)
		std::cout << "mp2 <= mp3\n";
	std::cout << "\n";

	/* ------------- operator>= ------------- */
	std::cout << "operator>=\n";
	if (mp4 >= mp1)
		std::cout << "mp4 >= mp1\n";
	if (mp2 >= mp3)
		std::cout << "mp2 >= mp3\n";
	std::cout << "\n";

	return 0;
}