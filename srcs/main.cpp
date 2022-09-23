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


	// ------------------------------ //
	std::cout << "\nFTTTT\n";

	ft::map<int, int> ftmp;
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
}