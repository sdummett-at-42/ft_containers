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

// template<
// 			typename Key,
// 			typename T,
// 			typename Compare = std::less<Key>,
// 			typename Alloc = std::allocator<ft::pair<const Key, T> > >
// 	class rbtree
int main() {

	ft::rbtree<int, int> rb;

	rb.insert(42);
	rb.insert(0);
	rb.insert(1);
	rb.insert(100);
	rb.insert(30);
	rb.insert(8);
	rb.insert(24);
	rb.pretty_print();
}