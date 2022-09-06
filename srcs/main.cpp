/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:08:35 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/06 17:25:38 by sdummett         ###   ########.fr       */
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

	// int ft = 42;
	// std::vector<int> vec(42, ft);
	// int i = 24;
	// int j = 42;
	ft::vector<std::string> vectest(1, "Je suis groot");
	ft::vector<std::string>vec2;
	vec2 = vectest;
	ft::vector<std::string>vec3(vec2);

	std::cout << vec3[0] << " " << vec3.front() << " " << vec3.back() << "\n";
	// std::cout << ftvec[0] << ftvec[23] << "\n"; 	


	// std::allocator<int> allo;
	// std::allocator<int>::pointer p = allo.allocate(5);
	// for (int i = 0; i < 5; ++i) {
	// 	allo.construct(p + i, i * 100);
	// }
	// for (int i = 0; i < 5; ++i) {
	// 	std::cout << "arr[" << i << "] : " << *(p + i) << "\n";
	// }

	// std::cout << "Reallocating 5...\n";
	// std::allocator<int>::pointer p2 = allo.allocate(5);
	// // std::cout << "p : " << p << " p2 : " << p2 << "\n";
	// std::cout << "5 allocated\n";
	// for (int i = 0; i < 5; ++i) {
	// 	allo.construct(p2 + i, i * 10);
	// }
	// for (int i = 0; i < 5; ++i) {
	// 	std::cout << "arr[" << i << "] : " << *(p + i) << "\n";
	// }
	// for (int i = 0; i < 5; ++i) {
	// 	std::cout << "arr[" << i << "] : " << *(p2 + i) << "\n";
	// }

	return 0;
}
