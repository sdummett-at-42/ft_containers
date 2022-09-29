#ifndef SET_HPP
#define SET_HPP

#include <functional>
#include <memory>
#include "rbtree_set.hpp"
#include "enable_if.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

namespace ft {
	template<

    class Key,
    class Compare = std::less<Key>,
    class Alloc = std::allocator<Key> >
	class set {

	public:
	/* ------------- Typedefs ------------- */
	typedef Key																							key_type;
	typedef Key																							value_type;
	typedef std::size_t																					size_type;
	typedef std::ptrdiff_t																				difference_type;
	typedef Compare																						key_compare;
	typedef Compare																						value_compare;
	typedef Alloc																						allocator_type;
	typedef value_type&																					reference;
	typedef const value_type&																			const_reference;
	typedef typename allocator_type::pointer															pointer;
	typedef typename allocator_type::const_pointer														const_pointer;
	typedef typename ft::rbtree_set< key_type, key_compare, allocator_type >::iterator					iterator;
	typedef typename ft::rbtree_set< key_type, key_compare, allocator_type >::const_iterator			const_iterator;
	typedef typename ft::rbtree_set< key_type, key_compare, allocator_type >::reverse_iterator			reverse_iterator;
	typedef typename ft::rbtree_set< key_type, key_compare, allocator_type >::const_reverse_iterator	const_reverse_iterator;
	
	protected:
	ft::rbtree_set< key_type, key_compare, allocator_type> _rbtree;

	public:
	/* ------------- Constructors ------------- */	
	explicit set (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) :
		_rbtree(comp, alloc) {}

	template <class InputIterator>
		set (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0):
		_rbtree(first, last, comp, alloc) {}

	set( const set& other );

	// class value_compare {
	// public:
	// bool operator()(const value_type &a, const value_type &b) const {
	// 	return (key_compare()(a.first, b.first));
	// }
	// };

	/* ------------- operator= ------------- */

	set& operator= (const set& x) {
		_rbtree = x._rbtree;
		return *this;
	}

	/* ------------- Allocator ------------- */

	allocator_type get_allocator() const {
		return _rbtree.get_allocator();
	}


	/* ------------- Destructor ------------- */
	~set() {}
	

	/* ------------- Iterators ------------- */

	iterator begin() {
		return static_cast<iterator>(_rbtree.begin());
	}
	const_iterator begin() const {
		return static_cast<const_iterator>(_rbtree.begin());
	}
	iterator end() {
		return static_cast<iterator>(_rbtree.end());
	}
	const_iterator end() const {
		return static_cast<const_iterator>(_rbtree.end());
	}
	reverse_iterator rbegin() {
		return static_cast<reverse_iterator>(_rbtree.rbegin());
	}
	const_reverse_iterator rbegin() const {
		return static_cast<const_reverse_iterator>(_rbtree.rbegin());
	}
	reverse_iterator rend() {
		return static_cast<reverse_iterator>(_rbtree.rend());
	}
	const_reverse_iterator rend() const {
		return static_cast<const_reverse_iterator>(_rbtree.rend());
	}


	/* ------------- Capacity ------------- */

	bool empty() const {
		return _rbtree.empty();
	}

	size_type size() const {
		return _rbtree.size();
	}

	size_type max_size() const {
		return _rbtree.max_size();
	}


	/* ------------- Modfiers ------------- */

	ft::pair<iterator, bool> insert (const value_type& val) {
		return _rbtree.insert(val);
	}

	iterator insert (iterator position, const value_type& val) {
		(void)position;
		return _rbtree.insert(val).first;
	}

	template <class InputIterator>
	void insert (InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {
		if (first == last)
			return;
		while (first != last) {
			_rbtree.insert(*first);
			++first;
		}
	}

	void erase( iterator pos ) {
		_rbtree.erase(pos);
	}

	void erase( iterator first, iterator last ) {
		_rbtree.erase(first, last);
	}
	size_type erase( const Key& key ) {
		return _rbtree.erase(key);
	}

	void swap (set& x) {
		_rbtree.swap(x._rbtree);
	}

	void clear() {
		_rbtree.clear();
	}


	/* ------------- Lookup ------------- */

	iterator find (const key_type& k) {
		return _rbtree.find(k);
	}
	const_iterator find (const key_type& k) const {
		return _rbtree.find(k);
	}
	size_type count (const key_type& k) const {
		return _rbtree.count(k);
	}
	iterator lower_bound (const key_type& k) {
		return _rbtree.lower_bound(k);
	}
	const_iterator lower_bound (const key_type& k) const {
		return _rbtree.lower_bound(k);
	}
	iterator upper_bound (const key_type& k) {
		return _rbtree.upper_bound(k);
	}
	const_iterator upper_bound (const key_type& k) const {
		return _rbtree.upper_bound(k);
	}
	ft::pair<iterator,iterator> equal_range (const key_type& k) {
		return _rbtree.equal_range(k);
	}
	ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		return _rbtree.equal_range(k);
	}


	/* ------------- Observers ------------- */

	key_compare key_comp() const {
		return _rbtree.key_comp();
	}

	value_compare value_comp() const {
		return value_compare();
	}

	};

	/* ------------- Non-member function ------------- */

	template< class Key, class Compare, class Alloc >
	void swap( ft::set<Key,Compare,Alloc>& lhs,
           ft::set<Key,Compare,Alloc>& rhs ) {
		lhs.swap(rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator==( const ft::set<Key,Compare,Alloc>& lhs,
                 const ft::set<Key,Compare,Alloc>& rhs ) {
		return (lhs.size() == rhs.size()) && (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class Key, class Compare, class Alloc >
	bool operator!=( const ft::set<Key,Compare,Alloc>& lhs,
					const ft::set<Key,Compare,Alloc>& rhs ) {
		return !(lhs == rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator<( const ft::set<Key,Compare,Alloc>& lhs,
					const ft::set<Key,Compare,Alloc>& rhs ) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template< class Key, class Compare, class Alloc >
	bool operator<=( const ft::set<Key,Compare,Alloc>& lhs,
					const ft::set<Key,Compare,Alloc>& rhs ) {
		return (lhs < rhs) || (lhs == rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator>( const ft::set<Key,Compare,Alloc>& lhs,
					const ft::set<Key,Compare,Alloc>& rhs ) {
		return !(lhs < rhs) && (lhs != rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator>=( const ft::set<Key,Compare,Alloc>& lhs,
					const ft::set<Key,Compare,Alloc>& rhs ) {
		return (lhs > rhs) || (lhs == rhs);
	}
}
#endif