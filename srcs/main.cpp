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
#include "rbnode.hpp"

int main() {

	ft::rbtree<int> *rbtree = new ft::rbtree<int>;

	rbtree->root = new ft::rbnode<int>(42);
	rbtree->root->debug();

	recursive_insertion(rbtree->root, new ft::rbnode<int>(0));

	rbtree->root->debug();
	rbtree->root->left->debug();

	recursive_insertion(rbtree->root, new ft::rbnode<int>(1337));
	rbtree->root->right->debug();

	/** Left Rotation **/

	// ft::left_rotation(rbtree->root, rbtree);
	// std::cout << "Left rotatation: \n";

	// rbtree->root->debug();
	// rbtree->root->right->debug();
	// rbtree->root->left->debug();
	// rbtree->root->left->right->debug();
	// rbtree->root->left->left->debug();

}