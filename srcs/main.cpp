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

	// std::map<int, int> mp;
	// mp.insert(std::pair<int,int>(42,43));
	// mp.insert(std::pair<int,int>(0,1));
	// mp.insert(std::pair<int,int>(1,2));
	// mp.insert(std::pair<int,int>(100,101));
	// mp.insert(std::pair<int,int>(30,31));
	// mp.insert(std::pair<int,int>(8,9));
	// mp.insert(std::pair<int,int>(24,25));

	// std::map<int,int>::iterator it = mp.begin();
	// std::pair<int,int> pr = *it;
	// std::cout << pr.first << " " << pr.second << "\n";
	// std::cout << it->first << " " << it->second << "\n";


	// std::map<int,int>::iterator it = mp.begin();
	// for (; it != mp.end(); it++) {
	// 	std::cout << it->first << " <=> " << it->second << "\n";
	// }

	// ------------------------------ //

	ft::map<int, int> mp;
	mp.insert(ft::pair<int,int>(42,43));
	mp.insert(ft::pair<int,int>(0,1));
	mp.insert(ft::pair<int,int>(1,2));
	mp.insert(ft::pair<int,int>(100,101));
	mp.insert(ft::pair<int,int>(30,31));
	mp.insert(ft::pair<int,int>(8,9));
	mp.insert(ft::pair<int,int>(24,25));

	ft::map<int,int>::iterator it = mp.begin();
	ft::pair<int,int> pr = *it;
	std::cout << pr.first << " " << pr.second << "\n";
	std::cout << it->first << " " << it->second << "\n";

	// for (; it != mp.end(); it++) {
	// 	std::cout << it->first << " <=> " << it->second << "\n";
	// }
}