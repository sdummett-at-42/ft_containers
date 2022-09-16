#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "rbtree.hpp"

#define BLACK	0
#define RED		1
#define	LEAF	NULL

template< typename T >
struct rbtree;

namespace ft {

	template < typename T >
	class rbnode {
		public:
			/* ------------- Typedefs ------------- */

			/* ------------- Constructors ------------- */
			rbnode();

			rbnode(const rbnode& x);

			// Note: maybe to remove later
			// For implementation purpose
			rbnode(const T key) :
			key(key),
			parent(),
			left(),
			right(),
			color(RED) {}

			/* ------------- operator= ------------- */
			rbnode& operator= (const rbnode& x);

			/* ------------- Destructor ------------- */
			~rbnode();

			/* ------------- Node genealogy ------------- */

			rbnode*	grandparent() const {
				if (parent == NULL)
					return NULL;
				return parent->parent;
			}

			rbnode*	sibling() const {
				if (parent == NULL)
					return NULL;
				if (parent->left == this)
					return parent->right;
				else
					return parent->left;
			}

			rbnode*	uncle() const {
				if (grandparent() == NULL)
					return NULL;
				return parent->sibling();
			}

			// Notes: to delete (for implementation purpose)
			void	debug() {
				std::cout << "parent  : " << parent  << "\n";
				std::cout << "left    : " << left    << "\n";
				std::cout << "right   : " << right   << "\n";
				std::cout << "color   : " << color   << "\n";
				std::cout << "key     : " << key << "\n\n";
			}

			T		key;
			rbnode*	parent;
			rbnode*	left;
			rbnode*	right;
			bool	color;
		protected:
    };

	/* ------------- Node rotation ------------- */


	template< typename T >
	void	left_rotation(rbnode<T> *x, ft::rbtree<T> *rbtree) {
		rbnode<T>	*y = x->right;
		x->right = y->left;
		if (y->left != LEAF)
			y->left->parent = x;

		y->parent = x->parent;
		if (x->parent == NULL)
			rbtree->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	template< typename T >
	void	right_rotation(rbnode<T> *x, ft::rbtree<T> *rbtree) {
		rbnode<T>	*y = x->left;
		x->left = y->right;
		if (y->right != LEAF)
			y->right->parent = x;

		y->parent = x->parent;
		if (x->parent == NULL)
			rbtree->root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;

		y->right = x;
		x->parent = y;
	}


	/* ------------- Node insertion ------------- */

	template < typename T >
	void	insert(rbnode<T> *new_node, ft::rbtree<T> *rbtree) {
		if (rbtree->root == NULL) {
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
	template< typename T >
	void recursive_insertion(rbnode<T> *root, rbnode<T> *new_node) {
		if (root != NULL && new_node->key < root->key) {
			if (root->left != LEAF) {
				recursive_insertion(root->left, new_node);
				return ;
			}
			else {
				std::cout << "Node inserted to the left.\n";
				root->left = new_node;
			}
		}
		else if (root != NULL) {
			if (root->right != LEAF) {
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

	template< typename T >
	void repair_tree(rbnode<T> *new_node, ft::rbtree<T> *rbtree) {
		if (new_node->parent == NULL)
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


}

#endif