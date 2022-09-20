#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "rbnode.hpp"

#define BLACK	0
#define RED		1

namespace ft {

	template < typename T >
	class rbnode;

	template< typename T >
	class rbtree {
		public:
			ft::rbnode<T> *root;
			ft::rbnode<T> *tnull;

		rbtree() {
			tnull = init_new_node(0);
			tnull->color = BLACK;
			tnull->left = NULL;
			tnull->right = NULL;
			root = tnull;
		}

/* ------------- Node rotation ------------- */
	rbnode<T>	*init_new_node(T key) {
		rbnode<T> *new_node = new rbnode<T>;
		new_node->key = key;
		new_node->parent = tnull;
		new_node->left = tnull;
		new_node->right = tnull;
		new_node->color = RED;
		return new_node;
	}

/* ------------- Node rotation ------------- */


	void	left_rotation(rbnode<T> *x, ft::rbtree<T> *rbtree) {
		rbnode<T>	*y = x->right;
		x->right = y->left;
		if (y->left != tnull)
			y->left->parent = x;

		y->parent = x->parent;
		if (x->parent == tnull	)
			rbtree->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	void	right_rotation(rbnode<T> *x, ft::rbtree<T> *rbtree) {
		rbnode<T>	*y = x->left;
		x->left = y->right;
		if (y->right != tnull)
			y->right->parent = x;

		y->parent = x->parent;
		if (x->parent == tnull)
			rbtree->root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;

		y->right = x;
		x->parent = y;
	}


	/* ------------- Node insertion ------------- */

	// template < typename T >
	void	insert(T key, ft::rbtree<T> *rbtree) {
		rbnode<T> *new_node = init_new_node(key);

		if (rbtree->root == tnull) {
			rbtree->root = new_node;
			new_node->color = BLACK;
		}
		else {
			recursive_insertion(rbtree->root, new_node);
			repair_tree(new_node, rbtree);
		}
	}

	/* Go deep down to tree until a leaf is found
	*/
	void recursive_insertion(rbnode<T> *root, rbnode<T> *new_node) {
		if (root != tnull && new_node->key < root->key) {
			if (root->left != tnull) {
				recursive_insertion(root->left, new_node);
				return ;
			}
			else {
				std::cout << "Node inserted to the left.\n";
				root->left = new_node;
			}
		}
		else if (root != tnull) {
			if (root->right != tnull) {
				recursive_insertion(root->right, new_node);
				return ;
			}
			else {
				std::cout << "Node inserted to the right.\n";
				root->right = new_node;
			}
		}
		new_node->parent = root;
	}

	void repair_tree(rbnode<T> *new_node, ft::rbtree<T> *rbtree) {
		if (new_node->parent == tnull)
			new_node->color = BLACK;
		else if (new_node->parent->color == BLACK)
			return ;
		else if (new_node->uncle() && new_node->uncle()->color == RED) {
			new_node->parent->color = BLACK;
			new_node->uncle()->color = BLACK;
			new_node->grandparent()->color = RED;
			repair_tree(new_node->grandparent(), rbtree);
		}
		else {
			if (new_node == new_node->grandparent()->left->right) {
				left_rotation(new_node->parent, rbtree);
				new_node = new_node->left;
			}
			else if (new_node == new_node->grandparent()->right->left) {
				right_rotation(new_node->parent, rbtree);
				new_node = new_node->right;
			}
			if (new_node == new_node->parent->left)
				right_rotation(new_node->grandparent(), rbtree);
			else
				left_rotation(new_node->grandparent(), rbtree);

			new_node->parent->color = BLACK;
			new_node->sibling()->color = RED;
		}
	}
	};


}

#endif