/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:08:35 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/11 21:41:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

# include "vector.hpp"
# include "map.hpp"
# include "stack.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"
# include "pair.hpp"
# include "make_pair.hpp"

using namespace ft;

int main() {
	std::cout << "Hello world" << std::endl;
	ft::pair <int,int> object(0, 1);
	std::cout << object.first << ' ' << object.second << '\n';
	return 0;
}
