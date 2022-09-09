/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:08:35 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/09 20:36:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# include "vector.hpp"
// # include "map.hpp"
// # include "stack.hpp"
// # include "iterator_traits.hpp"
// # include "reverse_iterator.hpp"
// # include "enable_if.hpp"
// # include "is_integral.hpp"
// # include "equal.hpp"
// # include "lexicographical_compare.hpp"
// # include "pair.hpp"
// # include "make_pair.hpp"

#include <vector>
#include <string>

int main() {
	ft::vector<int> ftvec(1, 10);
	ft::vector<int>::iterator it;
	// std::vector<int> ftvec(1, 10);
	// std::vector<int>::iterator it;

	ftvec.push_back(20);
	ftvec.push_back(30);
	ftvec.push_back(40);
	ftvec.push_back(50);
	// ftvec.pop_back();
	// ftvec.pop_back();
	int first = 4;
	int last = 5;

	it = ftvec.begin();
	std::cout << "to erase : " << *(it + first) << " -- " << *(it + last) << "\n";
	it = ftvec.erase(it + first, it + last);
	 std::cout << "it returned by erase : " << *it << "\n";
	if (it == ftvec.end())
		std::cout << "it == ftvec.end()\n";

	int i = 0;
	for (it = ftvec.begin(); it != ftvec.end(); it++ ){
		std::cout << ftvec.at(i) << "\n";
		++i;
	}
	// for (it = ftvec.begin(); it != ftvec.end(); it++ ) {
	// 	std::cout << *it << "\n";
	// }


	// std::vector<int> ftvec(2, 42);
	// std::vector<int>::iterator it    = ftvec.begin();
	// std::vector<int>::iterator itend = ftvec.end();



	// if (it == itend )
	// 	std::cout << "it == itend\n";
	// else
	// 	std::cout << "it != itend\n";


	// std::cout << it[0] << " " << it[1] << " " << it[2] << "\n";

	// it += 1;
	// std::cout << *it << "\n";


	// it = it + 1;
	// if (it < itend)
	// 	std::cout << "it < itend\n";
	// else
	// 	std::cout << "!(it < itend)\n";

	// if (it == itend)
	// 	std::cout << "it == itend\n";
	// else
	// 	std::cout << "!(it == itend)\n";





// --------------------------------------------- //



	// std::cout << *it << "\n";
	// it++;
	// std::cout << *it << "\n";
	// it++;
	// std::cout << *it << "\n";
	// it--;
	// std::cout << *it << "\n";
	// --it;
	// std::cout << *it << "\n";
	// --it;
	// std::cout << *it << "\n";
	// ++it;
	// std::cout << *it++ << "\n";
	// std::cout << *it << "\n";

	return 0;
}