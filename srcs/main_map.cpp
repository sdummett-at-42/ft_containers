#include "map.hpp"
#include <map>
#include <iostream>
#include <utility>
#include "pair.hpp"

#ifdef FT
using namespace ft;
#else
using namespace std;
#endif

void	print_map(map<int,int> mp) {
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++)
		std::cout << it->first << "," << it->second << " ";
	std::cout << "\n";
}

int main() {
	#ifdef FT
	std::cout << "FT\n";
	#else
	std::cout << "STD\n";
	#endif


	std::cout << "Launching map tests\n\n";

	map<int,int> mp4;
	mp4.insert(pair<int,int>(1,2));
	mp4.insert(pair<int,int>(2,3));
	mp4.insert(pair<int,int>(3,4));
	mp4.insert(pair<int,int>(4,5));
	mp4.insert(pair<int,int>(5,6));
	mp4.insert(pair<int,int>(6,7));
	mp4.insert(pair<int,int>(7,8));
	mp4.insert(pair<int,int>(8,9));
	mp4.insert(pair<int,int>(9,10));
	mp4.insert(pair<int,int>(10,11));
	mp4.insert(pair<int,int>(11,12));
	mp4.insert(pair<int,int>(12,13));

	map<int,int>::iterator			it;
	map<int,int>::iterator			ite;
	map<int,int>::reverse_iterator	rit;
	map<int,int>::reverse_iterator	rite;

	/* ------------- Constructor ------------- */
	std::cout << "Constructor\n";
	map<int,int> mp1;
	map<int,int> mp2(mp4.begin(), mp4.end());
	map<int,int> mp3(mp2);
	std::cout << "\n";

	/* ------------- Destructor ------------- */
	/* All the containers will be destroyed at the end.
	** If something wrong happen, we will now at compilation
	** or at runtime.
	*/

	/* ------------- operator= ------------- */
	std::cout << "operator=\n";
	print_map(mp1);
	print_map(mp3);
	mp1 = mp3;
	print_map(mp1);
	print_map(mp3);
	std::cout << "\n";

	/* ------------- get_allocator ------------- */
	std::cout << "get_allocator\n";
	map<int,int>::allocator_type alloc = mp3.get_allocator();
	std::cout << "\n";

	std::cout << "ELEMENT ACCESS\n";
	/* ------------- at ------------- */
	mp1.insert(pair<int,int>(45, 42));
	mp1.insert(pair<int,int>(56, 43));
	mp1.insert(pair<int,int>(67, 44));
	mp1.insert(pair<int,int>(78, 45));
	
	std::cout << "at\n";
	std::cout << mp3.at(1) << " ";
	std::cout << mp3.at(5) << " ";
	std::cout << mp3.at(8) << " ";
	std::cout << mp3.at(12) << " ";
	std::cout << "\n";
	std::cout << mp1.at(1) << " ";
	std::cout << mp1.at(5) << " ";
	std::cout << mp1.at(7) << " ";
	std::cout << mp1.at(45) << " ";
	std::cout << mp1.at(78) << " ";
	std::cout << "\n\n";

	/* ------------- operator[] ------------- */
	std::cout << "operator[]\n";
	std::cout << mp3[1] << " ";
	std::cout << mp3[5] << " ";
	std::cout << mp3[8] << " ";
	std::cout << mp3[12] << " ";
	std::cout << "\n";
	std::cout << mp1[1] << " ";
	std::cout << mp1[5] << " ";
	std::cout << mp1[7] << " ";
	std::cout << mp1[45] << " ";
	std::cout << mp1[78] << " ";
	std::cout << "\n\n";

	std::cout << "ITERATORS\n";
	/* ------------- begin ------------- */
	std::cout << "begin\n";
	it = mp1.begin();
	std::cout << it->first << "," << it->second << "\n";
	std::cout << (it++)->first << "," << (it++)->second << "\n\n";

	/* ------------- end ------------- */
	std::cout << "end\n";
	ite = mp1.end();
	std::cout << (it--)->first << "," << (it--)->second << "\n";
	for (; it != ite; it++)
		std::cout << it->first << "," << it->second << " ";
	std::cout << "\n\n";

	/* ------------- rbegin ------------- */
	std::cout << "rbegin\n";
	rit = mp1.rbegin();
	std::cout << rit->first << "," << rit->second << "\n";
	std::cout << (rit++)->first << "," << (rit++)->second << "\n\n";

	/* ------------- rend ------------- */
	std::cout << "rend\n";
	rite = mp1.rend();
	std::cout << (rit--)->first << "," << (rit--)->second << "\n";
	for (; rit != rite; rit++)
		std::cout << rit->first << "," << rit->second << " ";
	std::cout << "\n\n";

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
	pair<map<int,int>::iterator, bool> pr;
	pr = mp1.insert(pair<int,int>(243,24646));
	std::cout << pr.first->first << " " <<
	pr.first->second << " " <<
	pr.second << "\n";

	print_map(mp4);
	mp1.insert(mp4.begin(), mp4.end());
	print_map(mp4);
	std::cout << "\n";

	/* ------------- erase ------------- */
	std::cout << "erase\n";
	it = mp4.begin();
	print_map(mp4);
	mp4.erase(it);
	print_map(mp4);
	it = mp4.begin();
	ite = it;
	ite++; ite++; ite++; ite++;
	mp4.erase(it, ite);
	print_map(mp4);
	std::cout << "\n";

	/* ------------- swap ------------- */
	std::cout << "swap\n";
	print_map(mp1);
	print_map(mp4);
	mp1.swap(mp4);
	print_map(mp1);
	print_map(mp4);
	std::cout << "\n";

	std::cout << "LOOKUP\n";
	/* ------------- count ------------- */
	std::cout << "count\n";
	mp4.insert(pair<int,int>(243,24646));
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
	pair<map<int,int>::iterator,map<int,int>::iterator> prit;
	prit = mp4.equal_range(12);
	it = prit.first;
	ite = prit.second;
	for (; it != ite; it++)
		std::cout << it->first << "," << it->second << " ";
	std::cout << "\n\n";

	/* ------------- lower_bound ------------- */
	std::cout << "lower_bound\n";
	it = mp4.lower_bound(12);
	for (; it != mp4.end(); it++)
		std::cout << it->first << "," << it->second << " ";
	std::cout << "\n\n";

	/* ------------- upper_bound ------------- */
	std::cout << "upper_bound\n";
	it = mp4.lower_bound(78);
	for (; it != mp4.end(); it++)
		std::cout << it->first << "," << it->second << " ";
	std::cout << "\n\n";

	std::cout << "OBSERVERS\n";
	/* ------------- key_comp ------------- */
	std::cout << "key_comp\n";
	map<int,int>::key_compare kc = mp4.key_comp();
	std::cout << "\n";

	/* ------------- value_comp ------------- */
	std::cout << "value_comp\n";
	map<int,int>::value_compare vc = mp4.value_comp();
	std::cout << "\n";

	std::cout << "NON-MEMBER FUNCTIONS\n";
	/* ------------- swap ------------- */
	std::cout << "swap\n";
	print_map(mp1);
	print_map(mp3);
	swap(mp4, mp1);
	print_map(mp1);
	print_map(mp3);
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