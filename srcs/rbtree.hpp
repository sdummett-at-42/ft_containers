#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "rbnode.hpp"


namespace ft {

	template < typename T >
	class rbnode;

	template< typename T >
	struct rbtree {
		ft::rbnode<T> *root;
	};

}

#endif