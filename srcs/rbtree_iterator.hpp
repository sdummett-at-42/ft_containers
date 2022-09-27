#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "rbtree.hpp"

namespace ft {

	template< typename T >
	class rbtree_iterator {

	public:
	typedef T																					iterator_type;
	typedef typename std::iterator<std::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
	typedef typename std::iterator<std::bidirectional_iterator_tag, T>::value_type				value_type;
	typedef typename std::iterator<std::bidirectional_iterator_tag, T>::difference_type			difference_type;
	typedef typename std::iterator<std::bidirectional_iterator_tag, T>::pointer					pointer;
	typedef typename std::iterator<std::bidirectional_iterator_tag, T>::reference				reference;
	typedef typename ft::rbnode<T>																node_type;

	protected:
	node_type* current_node;
	node_type* root;
	node_type* tnull;

	public:
	/* ------------- Constructors ------------- */
	rbtree_iterator() :
		current_node(),
		root(),
		tnull() {}

	explicit rbtree_iterator(const node_type* node, const node_type* root, const node_type* tnull) :
		current_node(static_cast<node_type*>(const_cast<node_type*>(node))),
		root(static_cast<node_type*>(const_cast<node_type*>(root))),
		tnull(static_cast<node_type*>(const_cast<node_type*>(tnull))) {}

	template <typename Type>
	rbtree_iterator(const ft::rbtree_iterator<Type>& x) :
		current_node(x.current_node),
		root(x.root),
		tnull(x.tnull) {}

	/* ------------- Destructor ? ------------- */

	/* ------------- Base ------------- */
	node_type* base() const {
		return current_node;
	}

	node_type* get_root() const {
		return root;
	}

	node_type* get_tnull() const {
		return tnull;
	}

	/* ------------- operator= ------------- */

	template< typename Type >
	rbtree_iterator& operator=(const rbtree_iterator<Type>& x) {
		current_node = x.current_node;
		root = x.root;
		tnull = x.tnull;
		return *this;
	}


	/* ------------- Operators ------------- */
	reference operator*() const {
		return *(current_node->content);
	}

	pointer operator->() const {
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
		if (current_node == tnull)
			current_node = greatest(root);
		else
			current_node = previous(current_node);
		return *this;
	}

	rbtree_iterator operator--(int) {
		rbtree_iterator tmp(*this);
		operator--();
		return tmp;
	}

	/* ------------- rbtree_iterator utils ------------- */
	private:
	/* Find the next node in sorted order
	** Returns tnull if nothing was found.
	*/
	node_type *next(node_type *curr) const {
		node_type *tmp = curr;
		if (curr == tnull)
			return curr;
		else if (curr->right != tnull) {
			curr = curr->right;
			while (curr->left != tnull)
				curr = curr->left;
			return curr;
		}
		curr = curr->parent;
		while (curr != tnull && curr->right == tmp) {
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

		if (curr == tnull)
			return curr;
		else if (curr->left != tnull) {
			curr = curr->left;
			while (curr->right != tnull)
				curr = curr->right;
			return curr;
		}
		curr = curr->parent;
		while (curr != tnull && curr->left == tmp) {
			tmp = curr;
			curr = curr->parent;
		}
		return curr;
	}
	/* Find the greatest element
	** Returns tnull if nothing was found.
	*/
	node_type* greatest(node_type *curr) const {
		for (; curr->right != tnull; curr = curr->right)
			;
		return curr;
	}
	};

	/* ------------- Non-member function ------------- */

	template< typename T >
	bool operator==(const rbtree_iterator<T>& lhs,
					const rbtree_iterator<T>& rhs) {
		return lhs.base() == rhs.base();
	}

	template< typename T >
	bool operator!=(const rbtree_iterator<T>& lhs,
					const rbtree_iterator<T>& rhs) {
		return !(lhs.base() == rhs.base());
	}

	template< typename T >
	class rbtree_const_iterator {

	public:
	typedef T																					iterator_type;
	typedef rbtree_iterator<const T>															iterator;
	typedef typename std::iterator<std::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
	typedef typename std::iterator<std::bidirectional_iterator_tag, T>::value_type				value_type;
	typedef typename std::iterator<std::bidirectional_iterator_tag, T>::difference_type			difference_type;
	typedef typename std::iterator<std::bidirectional_iterator_tag, T>::pointer					pointer;
	typedef typename std::iterator<std::bidirectional_iterator_tag, T>::reference				reference;
	typedef typename ft::rbnode<T>																node_type;

	protected:
	node_type* current_node;
	node_type* root;
	node_type* tnull;

	public:
	/* ------------- Constructors ------------- */
	rbtree_const_iterator() :
		current_node(),
		root(),
		tnull() {}

	explicit rbtree_const_iterator(const node_type* node, const node_type* root, const node_type* tnull) :
		current_node(static_cast<node_type*>(const_cast<node_type*>(node))),
		root(static_cast<node_type*>(const_cast<node_type*>(root))),
		tnull(static_cast<node_type*>(const_cast<node_type*>(tnull))) {}

	template <typename Type>
	rbtree_const_iterator(const ft::rbtree_const_iterator<Type>& x) :
		current_node(x.current_node),
		root(x.root),
		tnull(x.tnull) {}

	template <typename Type>
	rbtree_const_iterator(const ft::rbtree_iterator<Type>& x) :
		current_node(x.base()),
		root(x.get_root()),
		tnull(x.get_tnull()) {}

	/* ------------- Destructor ? ------------- */


	/* ------------- Base ------------- */
	node_type* base() const {
		return current_node;
	}

	node_type* get_root() const {
		return root;
	}

	node_type* get_tnull() const {
		return tnull;
	}

	/* ------------- operator= ------------- */
	template< typename Type >
	rbtree_const_iterator& operator=(const rbtree_const_iterator<Type>& x) {
		current_node = x.current_node;
		root = x.root;
		tnull = x.tnull;
		return *this;
	}

	/* ------------- Operators ------------- */
	reference operator*() const {
		return *(current_node->content);
	}

	pointer operator->() const {
		return &(operator*());
	}

	rbtree_const_iterator& operator++() {
		current_node = next(current_node);
		return *this;
	}

	rbtree_const_iterator operator++(int) {
		rbtree_const_iterator tmp(*this);
		operator++();
		return tmp;
	}

	rbtree_const_iterator& operator--() {
		if (current_node == tnull)
			current_node = greatest(root);
		else
			current_node = previous(current_node);
		return *this;
	}

	rbtree_const_iterator operator--(int) {
		rbtree_const_iterator tmp(*this);
		operator--();
		return tmp;
	}


	/* ------------- rbtree_iterator utils ------------- */
	private:
	/* Find the next node in sorted order
	** Returns tnull if nothing was found.
	*/
	node_type *next(node_type *curr) const {
		node_type *tmp = curr;
		if (curr == tnull)
			return curr;
		else if (curr->right != tnull) {
			curr = curr->right;
			while (curr->left != tnull)
				curr = curr->left;
			return curr;
		}
		curr = curr->parent;
		while (curr != tnull && curr->right == tmp) {
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

		if (curr == tnull)
			return curr;
		else if (curr->left != tnull) {
			curr = curr->left;
			while (curr->right != tnull)
				curr = curr->right;
			return curr;
		}
		curr = curr->parent;
		while (curr != tnull && curr->left == tmp) {
			tmp = curr;
			curr = curr->parent;
		}
		return curr;
	}
	/* Find the greatest element
	** Returns tnull if nothing was found.
	*/
	node_type* greatest(node_type *curr) const {
		for (; curr->right != tnull; curr = curr->right)
			;
		return curr;
	}
	};

	/* ------------- Non-member function ------------- */
	template <typename T>
	bool	operator==(const ft::rbtree_const_iterator<T>& lhs,
		const ft::rbtree_const_iterator<T>& rhs) {
		return lhs.base() == rhs.base();
	}

	template <typename T>
	bool	operator==(const ft::rbtree_iterator<T>& lhs,
		const ft::rbtree_const_iterator<T>& rhs) {
		return lhs.base() == rhs.base();
	}

	template <typename T>
	bool	operator==(const ft::rbtree_const_iterator<T>& lhs,
		const ft::rbtree_iterator<T>& rhs) {
		return lhs.base() == rhs.base();
	}

	template <typename T>
	bool	operator!=(const ft::rbtree_const_iterator<T>& lhs,
		const ft::rbtree_const_iterator<T>& rhs) {
		return lhs.base() != rhs.base();
	}

	template <typename T>
	bool	operator!=(const ft::rbtree_iterator<T>& lhs,
		const ft::rbtree_const_iterator<T>& rhs) {
		return lhs.base() != rhs.base();
	}

	template <typename T>
	bool	operator!=(const ft::rbtree_const_iterator<T>& lhs,
		const ft::rbtree_iterator<T>& rhs) {
		return lhs.base() != rhs.base();
	}
}

#endif