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

	std::map<int,int>::reverse_iterator it = mp.rbegin();
	for (; it != mp.rend(); it++) {
		std::cout << it->first << " ";
	}
	std::cout << "\n";
	it--;
	for (; it != mp.rbegin(); --it) {
		std::cout << it->first << " ";
	}
	std::cout << "\nFTTTT\n";

	// ------------------------------ //

	ft::map<int, int> mpft;
	mpft.insert(ft::pair<int,int>(42,43));
	mpft.insert(ft::pair<int,int>(0,1));
	mpft.insert(ft::pair<int,int>(1,2));
	mpft.insert(ft::pair<int,int>(100,101));
	mpft.insert(ft::pair<int,int>(30,31));
	mpft.insert(ft::pair<int,int>(8,9));
	mpft.insert(ft::pair<int,int>(24,25));


	ft::map<int,int>::reverse_iterator itft = mpft.rbegin();
	// std::cout << itft->first << "\n";
	// itft++;
	// std::cout << itft->first << "\n";
	// itft++;
	// std::cout << itft->first << "\n";
	// itft++;
	// std::cout << itft->first << "\n";
	// itft++;
	// std::cout << itft->first << "\n";
	// itft++;
	// std::cout << itft->first << "\n";
	// itft++;
	// std::cout << itft->first << "\n";
	// itft++;
	// if (itft == mpft.rend())
	// 	std::cout << "YOUPIII\n";

	for (; itft != mpft.rend(); itft++) {
		std::cout << itft->first << " ";
	}

	std::cout << "\n";
	itft--;
	for (; itft != mpft.rbegin(); --itft) {
		std::cout << itft->first << " ";
	}
	std::cout << "\n";



	// ft::map<int,int>::iterator it = mp.begin();
	// (void)it;

	// ft::pair<int,int> pr = *it;
	// (void)pr;
	// for (int i = 0; i < 6; i++) {
	// 	std::cout << it->first << " " << it->second << "\n";
	// 	it.next();
	// }
	// std::cout << pr.first << " " << pr.second << "\n";

	// for (; it != mp.end(); it++) {
	// 	std::cout << it->first << " <=> " << it->second << "\n";
	// }
}