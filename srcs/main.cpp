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

	rbtree->root = new ft::rbnode<int>;
	
	rbtree->root->left = new ft::rbnode<int>;
	rbtree->root->right = new ft::rbnode<int>;
	rbtree->root->right->left = new ft::rbnode<int>;
	rbtree->root->right->right = new ft::rbnode<int>;

	rbtree->root->content = 1;
	rbtree->root->left->content = 0;
	rbtree->root->right->content = 42;
	rbtree->root->right->left->content = 24;
	rbtree->root->right->right->content = 100;

	rbtree->root->debug();
	rbtree->root->left->debug();
	rbtree->root->right->debug();
	rbtree->root->right->left->debug();
	rbtree->root->right->right->debug();

	// ft::node<int> *parent = new ft::node<int>;
	// parent->left = rbtree->root;
	// rbtree->root->parent = parent;

	// std::cout << "parent->left->content : " << parent->left->content << "\n";
	ft::left_rotation(rbtree->root, rbtree);
	std::cout << "Left rotatation: \n";
	// std::cout << "parent->left->content : " << parent->left->content << "\n\n";

	rbtree->root->debug();
	rbtree->root->right->debug();
	rbtree->root->left->debug();
	rbtree->root->left->right->debug();
	rbtree->root->left->left->debug();

}