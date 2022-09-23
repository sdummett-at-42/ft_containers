/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:08:35 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/15 10:43:22 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# include "vector.hpp"
# include "map.hpp"
# include "stack.hpp"
// # include "iterator_traits.hpp"
// # include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
// # include "equal.hpp"
# include "lexicographical_compare.hpp"
// # include "pair.hpp"
// # include "make_pair.hpp"

#include <vector>
#include <string>
#include <stack>
#include "rbtree.hpp"
#include <map>

// Note: ft::pair not working with std::map

int main() {

	std::map<int, int> mp;
	mp.insert(std::pair<int,int>(42,43));
	mp.insert(std::pair<int,int>(42,43));
	mp.insert(std::pair<int,int>(0,1));
	mp.insert(std::pair<int,int>(1,2));
	mp.insert(std::pair<int,int>(100,101));
	mp.insert(std::pair<int,int>(30,31));
	mp.insert(std::pair<int,int>(8,9));
	mp.insert(std::pair<int,int>(24,25));

	std::cout << "STD OPERATOR[]\n";
	for (int i = 0; i < 6; i++)
		std::cout << mp[i] << " ";
	mp[42] = 133333337;
	std::map<int,int>::reverse_iterator it = mp.rbegin();
	for (; it != mp.rend(); it++) {
		std::cout << it->first << " ";
	}
	std::cout << "\n";
	it--;
	for (; it != mp.rbegin(); --it) {
		std::cout << "[" << it->first << ", " << it->second << "]" <<" ";
	}
	std::cout << "\n";

	try {
		int mt = mp.at(24);
		std::cout << "mapped_type: " << mt << "\n";
	} catch (std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

	std::pair<std::map<int,int>::iterator, bool> pr = mp.insert(std::pair<int,int>(24,25));
	std::cout << "pr.first: " << pr.first->first << "| pr.second: " << pr.second << "\n";
	pr = mp.insert(std::pair<int,int>(1337,25));
	std::cout << "pr.first: " << pr.first->first << "| pr.second: " << pr.second << "\n";

	std::cout << "Before erase\n";
	for (it = mp.rbegin(); it != mp.rend(); it++)
		std::cout << it->first << " ";
	std::cout << "\n";
	mp.erase(pr.first);
	std::cout << "After erase\n";
	for (it = mp.rbegin(); it != mp.rend(); it++)
		std::cout << it->first << " ";
	std::cout << "\n";

	std::cout << "\nBefore erase with first,last\n";
	std::map<int,int>::iterator itfirst = mp.begin();
	std::map<int,int>::iterator itlast = mp.begin();
	for (itfirst = mp.begin(); itfirst != mp.end(); itfirst++)
		std::cout << itfirst->first << " ";
	std::cout << "\n";
	itfirst = mp.begin();
	itlast = mp.begin();
	itlast++;
	itlast++;
	itlast++;
	mp.erase(itfirst, itlast);
	std::cout << "After erase with first,last\n";
	for (itfirst = mp.begin(); itfirst != mp.end(); itfirst++)
		std::cout << itfirst->first << " ";
	std::cout << "\n";

	std :: cout << mp.erase(100) << "\n";
	std :: cout << mp.erase(50) << "\n";
	std::cout << "After erase with key\n";
	for (itfirst = mp.begin(); itfirst != mp.end(); itfirst++)
		std::cout << itfirst->first << " ";
	std::cout << "\n";
	std::cout << "Final size : " << mp.size() << "\n";

	// ------------------------------ //
	std::cout << "\nFTTTT\n";

	ft::map<int, int> ftmp;
	ftmp.insert(ft::pair<int,int>(42,43));
	ftmp.insert(ft::pair<int,int>(42,43));
	ftmp.insert(ft::pair<int,int>(0,1));
	ftmp.insert(ft::pair<int,int>(1,2));
	ftmp.insert(ft::pair<int,int>(100,101));
	ftmp.insert(ft::pair<int,int>(30,31));
	ftmp.insert(ft::pair<int,int>(8,9));
	ftmp.insert(ft::pair<int,int>(24,25));

	std::cout << "FT OPERATOR[]\n";
	for (int i = 0; i < 6; i++)
		std::cout << ftmp[i] << " ";
	ftmp[42] = 133333337;
	ft::map<int,int>::reverse_iterator ftit = ftmp.rbegin();
	for (; ftit != ftmp.rend(); ftit++) {
		std::cout << ftit->first << " ";
	}
	std::cout << "\n";
	ftit--;
	for (; ftit != ftmp.rbegin(); --ftit) {
		std::cout << "[" << ftit->first << ", " << ftit->second << "]" <<" ";
	}
	std::cout << "\n";

	try {
		int mt = ftmp.at(24);
		std::cout << "mapped_type: " << mt << "\n";
	} catch (std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

	ft::pair<ft::map<int,int>::iterator, bool> ftpr = ftmp.insert(ft::pair<int,int>(24,25));
	std::cout << "pr.first: " << ftpr.first->first << "| pr.second: " << ftpr.second << "\n";
	ftpr = ftmp.insert(ft::pair<int,int>(1337,25));
	std::cout << "pr.first: " << ftpr.first->first << "| pr.second: " << ftpr.second << "\n";

	std::cout << "Before erase\n";
	for (ftit = ftmp.rbegin(); ftit != ftmp.rend(); ftit++)
		std::cout << ftit->first << " ";
	std::cout << "\n";
	ftmp.erase(ftpr.first);
	std::cout << "After erase\n";
	for (ftit = ftmp.rbegin(); ftit != ftmp.rend(); ftit++)
		std::cout << ftit->first << " ";
	std::cout << "\n";

	std::cout << "\nBefore erase with first,last\n";
	ft::map<int,int>::iterator ftitfirst = ftmp.begin();
	ft::map<int,int>::iterator ftitlast = ftmp.begin();
	for (ftitfirst = ftmp.begin(); ftitfirst != ftmp.end(); ftitfirst++)
		std::cout << ftitfirst->first << " ";
	std::cout << "\n";
	ftitfirst = ftmp.begin();
	ftitlast = ftmp.begin();
	ftitlast++;
	ftitlast++;
	ftitlast++;
	ftmp.erase(ftitfirst, ftitlast);
	std::cout << "After erase with first,last\n";
	for (ftitfirst = ftmp.begin(); ftitfirst != ftmp.end(); ftitfirst++)
		std::cout << ftitfirst->first << " ";
	std::cout << "\n";

	std :: cout << ftmp.erase(100) << "\n";
	std :: cout << ftmp.erase(50) << "\n";
	std::cout << "After erase with key\n";
	for (ftitfirst = ftmp.begin(); ftitfirst != ftmp.end(); ftitfirst++)
		std::cout << ftitfirst->first << " ";
	std::cout << "\n";
	std::cout << "Final size : " << ftmp.size() << "\n";
}