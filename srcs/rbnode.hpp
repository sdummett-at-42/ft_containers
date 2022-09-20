#ifndef NODE_HPP
#define NODE_HPP

namespace ft {

	template < typename T >
	class rbnode {

		public:

		/* ------------- Constructors ------------- */
		rbnode() {}

		rbnode(const rbnode& x) {
			*this = x;
		}

		/* ------------- operator= ------------- */
		rbnode& operator= (const rbnode& x) {
			key = x.key;
			parent = x.parent;
			left = x.left;
			right = x.right;
			color = x.color;
			return *this;
		}

		/* ------------- Destructor ------------- */
		~rbnode() {}

		/* ------------- Node genealogy ------------- */
		rbnode*	grandparent() const {
			return parent->parent;
		}

		rbnode*	sibling() const {
			if (parent->left == this)
				return parent->right;
			else
				return parent->left;
		}

		rbnode*	uncle() const {
			return parent->sibling();
		}

		T		key;
		rbnode*	parent;
		rbnode*	left;
		rbnode*	right;
		bool	color;
    };
}

#endif