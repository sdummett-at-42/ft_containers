/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:08:35 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/10 11:50:05 by sdummett         ###   ########.fr       */
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

#define FT

int main() {
	#ifdef FT
		std::cout << "------ FT DEFINED ------\n";
		ft::vector<int> ftvec;
		ft::vector<int>::reverse_iterator itbegin;
		ft::vector<int>::reverse_iterator itend;
	#endif
	#ifdef STL
		std::cout << "------ STL DEFINED ------\n";
		std::vector<int> ftvec;
		std::vector<int>::reverse_iterator itbegin;
		std::vector<int>::reverse_iterator itend;
	#endif

	ftvec.push_back(10);
	ftvec.push_back(20);
	ftvec.push_back(30);
	ftvec.push_back(40);
	ftvec.push_back(50);

	itbegin = ftvec.rbegin();
	itend = ftvec.rend();
	// Be careful reading itend will cause invalid read
	std::cout << "itbegin     : " << *itbegin << "\n";// " | itend : " << *itend << "\n" ; 

	std::cout << "itbegin + 1 : " << *(itbegin + 1) << "\n";
	std::cout << "itend   - 2 : " << *(itend - 2) << "\n";
	std::cout << "++itbegin   : " << *(++itbegin) << "\n";
	std::cout << "--itbegin   : " << *(--itbegin) << "\n";
	std::cout << "itbegin++   : " << *(itbegin++) << "\n";
	std::cout << "itbegin aft : " << *itbegin << "\n";
	std::cout << "itbegin--   : " << *(itbegin--) << "\n";
	std::cout << "itbegin aft : " << *itbegin << "\n";
	itbegin += 3;
	std::cout << "itbegin += 3: " << *itbegin << "\n";
	itbegin -= 1;
	std::cout << "itbegin -= 1: " << *itbegin << "\n";
	std::cout << "itbegin[0]  : " << itbegin[0] << "\n";
	std::cout << "itbegin[1]  : " << itbegin[1] << "\n";
	std::cout << "itbegin[2]  : " << itbegin[2] << "\n";
	int *p = ftvec.data();

	for (size_t i = 0; i < ftvec.size(); i++) {
		std::cout << "p : " << *(p + i) << "\n";
	}

	ft::vector<int>::iterator it = itbegin.base();
	std::cout << "base it dereferenced : " << *it << "\n";

	// ------------------------------- //
	// ftvec.pop_back();
	// ftvec.pop_back();
	// int first = 4;
	// int last = 5;

	// it = ftvec.begin();
	// std::cout << "to erase : " << *(it + first) << " -- " << *(it + last) << "\n";
	// it = ftvec.erase(it + first, it + last);
	//  std::cout << "it returned by erase : " << *it << "\n";
	// if (it == ftvec.end())
	// 	std::cout << "it == ftvec.end()\n";

	// int i = 0;
	// for (it = ftvec.begin(); it != ftvec.end(); it++ ){
	// 	std::cout << ftvec.at(i) << "\n";
	// 	++i;
	// }

	// --------------------------------------------------- //
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