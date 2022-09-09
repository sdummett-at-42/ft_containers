/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:08:35 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/09 17:41:15 by sdummett         ###   ########.fr       */
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

	ft::vector<int> ftvec(2, 42);
	ft::vector<int>::iterator it = ftvec.begin();
	ft::vector<int>::iterator itend = ftvec.end();

	// std::vector<int> ftvec(2, 42);
	// std::vector<int>::iterator it    = ftvec.begin();
	// std::vector<int>::iterator itend = ftvec.end();
	(void)itend;
	(void)it;

	if (it == itend )
		std::cout << "it == itend\n";
	else
		std::cout << "it != itend\n";


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