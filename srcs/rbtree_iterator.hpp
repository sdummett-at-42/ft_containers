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
	pointer rbtree;

	public:
	
	/* ------------- Constructors ------------- */

	rbtree_iterator() :
		current_node(),
		rbtree() {}

	template< typename T >
	rbtree_iterator(const ft::rbtree_iterator<T>& it) :
		current_node(it.current_node),
		rbtree(it.rbtree) {}

	rbtree_iterator(node_type* current_node, pointer rbtree) :
		current_node(current_node),
		rbtree(rbtree) {}

	node_type* base() const {
		return current_node;
	}

	/* ------------- operator= ------------- */

	rbtree_iterator& operator=(const rbtree_iterator& x) {
		current_node = x.current_node;
		rbtree = x.rbtree;
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
		current_node = next(current_node);
		return *this;
	}

	rbtree_iterator operator++(int) {
		rbtree_iterator tmp(*this);
		operator++();
		return tmp;
	}

	rbtree_iterator& operator--() {
		if (current_node == rbtree->get_tnull())
			current_node = rbtree->greatest();
		else
			current_node = previous(current_node);
		return *this;
	}

	rbtree_iterator operator--(int) {
		rbtree_iterator tmp(*this);
		operator--();
		return tmp;
	}

	/* Find the next node in sorted order
	** Returns tnull if nothing was found.
	*/
	node_type *next(node_type *curr) const {
		node_type *tmp = curr;
		if (curr == rbtree->get_tnull())
			return curr;
		else if (curr->right != rbtree->get_tnull()) {
			curr = curr->right;
			while (curr->left != rbtree->get_tnull())
				curr = curr->left;
			return curr;
		}
		curr = curr->parent;
		while (curr != rbtree->get_tnull() && curr->right == tmp) {
			tmp = curr;
			curr = curr->parent;
		}
		return curr;
	}
	/* Find the previous node in sorted order
	** Returns tnull if nothing was found.
	*/
	node_type *previous(node_type *curr) const {
		node_type *tmp = curr;

		if (curr == rbtree->get_tnull())
			return curr;
		else if (curr->left != rbtree->get_tnull()) {
			curr = curr->left;
			while (curr->right != rbtree->get_tnull())
				curr = curr->right;
			return curr;
		}
		curr = curr->parent;
		while (curr != rbtree->get_tnull() && curr->left == tmp) {
			tmp = curr;
			curr = curr->parent;
		}
		return curr;
	}
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