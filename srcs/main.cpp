/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:08:35 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/05 12:28:09 by sdummett         ###   ########.fr       */
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

	std::pair<int, char> pr = std::make_pair<int, char>(42, 'S');
	std::cout << "pr " << pr.first << " " << pr.second << "\n";

	ft::pair<int, char> ftpr = ft::make_pair<int, char>(42, 'S');
	std::cout << "ftpr " << ftpr.first << " " << ftpr.second << "\n";
	return 0;
}
