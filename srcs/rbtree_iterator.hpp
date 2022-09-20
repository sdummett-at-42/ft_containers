#ifndef RBTREE_ITERATOR
#define RBTREE_ITERATOR

#include "iterator_traits.hpp"

namespace ft {

	template< typename Iter >
	class rbtree_iterator {

	public:

	/* ------------- Typedefs ------------- */
	typedef Iter iterator_type;
	typedef typename std::iterator<std::bidirectional_iterator_tag, Iter>::iterator_category iterator_category;
	typedef typename  std::iterator<std::bidirectional_iterator_tag, Iter>::value_type value_type;
	typedef typename  std::iterator<std::bidirectional_iterator_tag, Iter>::difference_type	difference_type;
	typedef typename  std::iterator<std::bidirectional_iterator_tag, Iter>::pointer pointer;
	typedef typename  std::iterator<std::bidirectional_iterator_tag, Iter>::reference reference;
	
	/* ------------- Constructors ------------- */
	rbtree_iterator() :
		_p() {}

	template< typename T >
	rbtree_iterator(const ft::rbtree_iterator<T>& it) :
		_p(it.base()) {}

	rbtree_iterator(pointer p) :
		_p(p) {}

	/* ------------- operator= ------------- */
	rbtree_iterator& operator=(const rbtree_iterator& x) {
		_p = x._p;
		return *this;
	}

	~rbtree_iterator() {}

	iterator_type* base() const {
		return _p;
	}

	/* ------------- Operators ------------- */

	Iter& operator*() {
		return *_p;
	}

	Iter* operator->() {
		return &(*_p);
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

	protected:
		iterator_type* _p;
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