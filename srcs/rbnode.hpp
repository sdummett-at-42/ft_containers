#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "rbtree.hpp"

#define BLACK	0
#define RED		1

template< typename T >
struct rbtree;

namespace ft {

	template < typename T >
	class rbnode {
		public:
			/* ------------- Typedefs ------------- */

			/* ------------- Constructors ------------- */
			rbnode() {}

			rbnode(const rbnode& x);

			// Note: maybe to remove later
			// For implementation purpose
			// rbnode(const T key) :
			// key(key),
			// parent(),
			// left(),
			// right(),
			// color(RED) {}

			/* ------------- operator= ------------- */
			rbnode& operator= (const rbnode& x);

			/* ------------- Destructor ------------- */
			~rbnode() {}

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
}

#endif