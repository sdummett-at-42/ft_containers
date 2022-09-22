#ifndef RBTREE_ITERATOR
#define RBTREE_ITERATOR

#include "rbtree.hpp"
#include "iterator_traits.hpp"

namespace ft {

	template< typename Iter >
	class rbtree_iterator {

	public:

	/* ------------- Typedefs ------------- */
	typedef Iter iterator_type;
	typedef typename std::iterator<std::bidirectional_iterator_tag, Iter>::iterator_category iterator_category;
	typedef typename std::iterator<std::bidirectional_iterator_tag, Iter>::value_type value_type;
	typedef typename std::iterator<std::bidirectional_iterator_tag, Iter>::difference_type	difference_type;
	typedef typename std::iterator<std::bidirectional_iterator_tag, Iter>::pointer pointer;
	typedef typename std::iterator<std::bidirectional_iterator_tag, Iter>::reference reference;
	typedef typename ft::rbnode<typename Iter::value_type> node_type;
	typedef typename ft::rbnode<typename Iter::value_type>::value_type node_value_type;

	protected:
	node_type* current_node;
	node_type* tnull;

	public:
	
	/* ------------- Constructors ------------- */
	rbtree_iterator() :
		current_node(),
		tnull() {}

	template< typename T >
	rbtree_iterator(const ft::rbtree_iterator<T>& it) :
		current_node(it.current_node),
		tnull(it.tnull) {}

	rbtree_iterator(pointer p) :
		current_node(p->get_root()),
		tnull(p->get_tnull()) {}


	/* ------------- operator= ------------- */

	rbtree_iterator& operator=(const rbtree_iterator& x) {
		current_node = x.current_node;
		tnull = x.tnull;
		return *this;
	}

	~rbtree_iterator() {}


	/* ------------- Operators ------------- */

	node_value_type& operator*() {
		return *(current_node->content);
	}

	node_value_type* operator->() {
		return &(operator*());
	}

	rbtree_iterator& operator++() {
		// Note: to implement
		return *this;
	}

	rbtree_iterator operator++(int) {
		rbtree_iterator tmp(*this);
		operator++();
		return tmp;
	}

	rbtree_iterator& operator--() {
		// Note: to implement
		return *this;
	}

	rbtree_iterator operator--(int) {
		rbtree_iterator tmp(*this);
		operator--();
		return tmp;
	}

	// protected:
	// 	rbnode<typename Iter::value_type>* root;
	// 	rbnode<typename Iter::value_type>* tnull;
	};


	/* ------------- Non-member function ------------- */

	template< typename Iterator1, typename Iterator2 >
	bool operator==(const rbtree_iterator<Iterator1>& lhs,
					const rbtree_iterator<Iterator2>& rhs) {
		return lhs.base() == rhs.base();
	}

	template< typename Iterator1, typename Iterator2 >
	bool operator!=(const rbtree_iterator<Iterator1>& lhs,
					const rbtree_iterator<Iterator2>& rhs) {
		return !(lhs.base() == rhs.base());
	}
}

#endif