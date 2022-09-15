#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

#define BLACK	0
#define RED		1
#define	LEAF	NULL
namespace ft {

	template < class T >
	class node {
		public:
			/* ------------- Typedefs ------------- */

			/* ------------- Constructors ------------- */
			node() :
				parent(0),
				left(0),
				right(0),
				color(RED) {}

			node(const node& x);

			/* ------------- operator= ------------- */
			node& operator= (const node& x);

			/* ------------- Destructor ------------- */
			~node();

			/* ------------- Node genealogy ------------- */

			node*	grandparent() const {
				if (parent == NULL)
					return NULL;
				return parent->parent;
			}

			node*	sibling() const {
				if (parent == NULL)
					return NULL;
				if (*(parent->left) == *this)
					return *(parent->right);
				else
					return *(parent->left);
			}

			node*	uncle() const {
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

			node*	parent;
			node*	left;
			node*	right;
			bool	color;
			T		content;
		protected:
    };

	/* ------------- Node rotation ------------- */

	/* Return true if the rotation has been done
	** else false.
	*/
	template< class T >
	bool	left_rotation(node<T> *x) {
		node<T>	*y = x->right;
		x->right = y->left;
		if (y->left != LEAF)
			y->left->parent = x;

		y->parent = x->parent;
		if (x->parent == NULL) {
			// Notes : this is assignment is maybe wrong
			// -> to test.
			std::cout << "x->parent == NULL\n";
			// x = y;
		}
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->left = x;
		x->parent = y;

		// Notes: return not well implemented
		// maybe I will not add this
		return true;
	}

	template< class T >
	bool	right_rotation(node<T> *x) {
		node<T>	& y = x->left;
		x->left = y->right;
		if (y->right != LEAF) {
			// Notes : this is assignment is maybe wrong
			// -> to test.
			std::cout << "x->parent == NULL\n";
			// x = y;
		}
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;

		y->right = x;
		x->parent = y;

		return true;
	}

}

#endif