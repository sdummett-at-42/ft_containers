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
			rbnode() :
				parent(0),
				left(0),
				right(0),
				color(RED) {}

			rbnode(const rbnode& x);

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
				std::cout << "content : " << content << "\n\n";
			}

			rbnode*	parent;
			rbnode*	left;
			rbnode*	right;
			bool	color;
			T		content;
		protected:
    };

	/* ------------- Node rotation ------------- */

	/* Return true if the rotation has been done
	** else false.
	*/
	template< class T >
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

	template< class T >
	bool	right_rotation(rbnode<T> *x, ft::rbtree<T> *rbtree) {
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

}

#endif