#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "rbtree.hpp"

#define BLACK	0
#define RED		1
#define	LEAF	NULL

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
				if (*(parent->left) == *this)
					return *(parent->right);
				else
					return *(parent->left);
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
				// std::cout << "color   : " << color   << "\n";
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

	/* Return true if the rotation has been done
	** else false.
	*/
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
			rbtree->root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;

		y->right = x;
		x->parent = y;
	}


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

}

#endif