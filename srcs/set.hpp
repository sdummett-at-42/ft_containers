#ifndef SET_HPP
#define SET_HPP

#include <functional>
#include <memory>
#include "rbtree_set.hpp"
#include "enable_if.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

/* std::set is an associative container that contains a sorted set
** of unique objects of type Key. Sorting is done using the key
** comparison function Compare. Search, removal, and insertion
** operations have logarithmic complexity. Sets are usually
** implemented as red-black trees.
*/
namespace ft {
	template<

    class Key,
    class Compare = std::less<Key>,
    class Alloc = std::allocator<Key> >
	class set {

	public:

	/* ------------- Typedefs ------------- */
	typedef Key														key_type;
	typedef Key														value_type;
	typedef std::size_t												size_type;
	typedef std::ptrdiff_t											difference_type;
	typedef Compare													key_compare;
	typedef Compare													value_compare;
	typedef Alloc													allocator_type;
	typedef value_type&												reference;
	typedef const value_type&										const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef ft::rbtree_set< key_type, key_compare, allocator_type > rbtree;
	typedef typename rbtree::iterator								iterator;
	typedef typename rbtree::const_iterator							const_iterator;
	typedef typename rbtree::reverse_iterator						reverse_iterator;
	typedef typename rbtree::const_reverse_iterator					const_reverse_iterator;
	
	protected:

	rbtree _rbtree;

	public:

	/* ------------- Constructors ------------- */

	/* Default constructor. Constructs empty container.
	*/
	explicit set (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) :
		_rbtree(comp, alloc) {}

	/* Range constructor. Constructs the container with the contents
	** of the range [first, last). If multiple elements in the range
	** have keys that compare equivalent, it is unspecified which element is inserted.
	*/
	template <class InputIterator>
		set (InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0):
		_rbtree(first, last, comp, alloc) {}

	/* Copy constructor. Constructs the container with the copy
	** of the contents of other.
	*/
	set( const set& other ) {
		_rbtree = other._rbtree;
	}


	/* ------------- operator= ------------- */

	/* Copy assignment operator.
	** Replaces the contents with a copy of the contents of other.
	*/
	set& operator= (const set& x) {
		_rbtree = x._rbtree;
		return *this;
	}


	/* ------------- Allocator ------------- */

	/* Returns the allocator associated with the container.
	*/
	allocator_type get_allocator() const {
		return _rbtree.get_allocator();
	}


	/* ------------- Destructor ------------- */

	/* Destructs the set. The destructors of the elements
	** are called and the used storage is deallocated.
	** Note, that if the elements are pointers,
	** the pointed-to objects are not destroyed.
	*/
	~set() {}
	

	/* ------------- Iterators ------------- */

	/* Returns an iterator to the first element of the vector.
	** If the vector is empty, the returned iterator will be equal to 
	** end(). 
	*/
	iterator begin() {
		return static_cast<iterator>(_rbtree.begin());
	}
	const_iterator begin() const {
		return static_cast<const_iterator>(_rbtree.begin());
	}

	/* Returns an iterator to the element following the last element
	** of the vector.
	** This element acts as a placeholder; attempting to access it 
	** results in undefined behavior. 
	*/
	iterator end() {
		return static_cast<iterator>(_rbtree.end());
	}
	const_iterator end() const {
		return static_cast<const_iterator>(_rbtree.end());
	}

	/* Returns a reverse iterator to the first element of the reversed
	** vector. It corresponds to the last element of the non-reversed 
	** vector. If the vector is empty, the returned iterator is equal 
	** to rend(). 
	*/
	reverse_iterator rbegin() {
		return static_cast<reverse_iterator>(_rbtree.rbegin());
	}
	const_reverse_iterator rbegin() const {
		return static_cast<const_reverse_iterator>(_rbtree.rbegin());
	}

	/* Returns a reverse iterator to the element following the last
	** element of the reversed map. It corresponds to the element
	** preceding the first element of the non-reversed map.
	** This element acts as a placeholder, attempting to access it
	** results in undefined behavior.
	*/
	reverse_iterator rend() {
		return static_cast<reverse_iterator>(_rbtree.rend());
	}
	const_reverse_iterator rend() const {
		return static_cast<const_reverse_iterator>(_rbtree.rend());
	}


	/* ------------- Capacity ------------- */

	/* Checks if the container has no elements, i.e. whether begin() == end().
	*/
	bool empty() const {
		return _rbtree.empty();
	}

	/* Returns the number of elements in the container.
	*/
	size_type size() const {
		return _rbtree.size();
	}

	/* Returns the maximum number of elements the container
	** is able to hold due to system or library implementation limitations.
	*/
	size_type max_size() const {
		return _rbtree.max_size();
	}


	/* ------------- Modfiers ------------- */

	/*  Inserts value.
	*/
	ft::pair<iterator, bool> insert (const value_type& val) {
		return _rbtree.insert(val);
	}

	/* Inserts value in the position as close as possible
	*/
	iterator insert (iterator position, const value_type& val) {
		(void)position;
		return _rbtree.insert(val).first;
	}

	/* Inserts elements from range [first, last).
	** If multiple elements in the range have keys
	** that compare equivalent, it is unspecified which element is inserted.
	*/
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

	/* Removes the element at pos.
	*/
	void erase( iterator pos ) {
		_rbtree.erase(pos);
	}

	/* Removes the elements in the range [first; last),
	** which must be a valid range in *this.
	*/
	void erase( iterator first, iterator last ) {
		_rbtree.erase(first, last);
	}

	/* Removes the element (if one exists)
	** with the key equivalent to key.
	*/
	size_type erase( const Key& key ) {
		return _rbtree.erase(key);
	}

	/* Exchanges the contents of the container with those of other.
	** Does not invoke any move, copy, or swap operations on individual elements.
	** All iterators and references remain valid.
	** The past-the-end iterator is invalidated.
	** The Compare objects must be Swappable,
	** and they are exchanged using unqualified call to non-member swap. 
	*/
	void swap (set& x) {
		_rbtree.swap(x._rbtree);
	}

	/* Erases all elements from the container.
	** After this call, size() returns zero.
	** Invalidates any references, pointers,
	** or iterators referring to contained elements.
	** Any past-the-end iterator remains valid.
	*/
	void clear() {
		_rbtree.clear();
	}


	/* ------------- Lookup ------------- */

	/* Finds an element with key equivalent to key. 
	*/
	iterator find (const key_type& k) {
		return _rbtree.find(k);
	}
	const_iterator find (const key_type& k) const {
		return _rbtree.find(k);
	}

	/* Returns the number of elements with key that compares
	** equivalent to the specified argument, which is
	** either 1 or 0 since this container does not allow duplicates.
	*/
	size_type count (const key_type& k) const {
		return _rbtree.count(k);
	}

	/* Returns an iterator pointing to the first element
	** that is not less than (i.e. greater or equal to) key.
	*/
	iterator lower_bound (const key_type& k) {
		return _rbtree.lower_bound(k);
	}
	const_iterator lower_bound (const key_type& k) const {
		return _rbtree.lower_bound(k);
	}

	/* Returns an iterator pointing to the first element
	** that is greater than key.
	*/
	iterator upper_bound (const key_type& k) {
		return _rbtree.upper_bound(k);
	}
	const_iterator upper_bound (const key_type& k) const {
		return _rbtree.upper_bound(k);
	}

	/* Returns a range containing all elements with the given key in the container.
	** The range is defined by two iterators, one pointing to the first element
	** that is not less than key and another pointing to the first element greater
	** than key. Alternatively, the first iterator may be obtained with lower_bound(),
	** and the second with upper_bound().
	*/
	ft::pair<iterator,iterator> equal_range (const key_type& k) {
		return _rbtree.equal_range(k);
	}
	ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		return _rbtree.equal_range(k);
	}


	/* ------------- Observers ------------- */

	/* Returns the function object that compares the keys,
	** which is a copy of this container's constructor argument comp.
	** It is the same as value_comp. 
	*/
	key_compare key_comp() const {
		return _rbtree.key_comp();
	}

	/* Returns the function object that compares the values.
	** It is the same as key_comp.
	*/
	value_compare value_comp() const {
		return value_compare();
	}

	};


	/* ------------- Non-member function ------------- */

	/* Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
	*/
	template< class Key, class Compare, class Alloc >
	void swap( ft::set<Key,Compare,Alloc>& lhs,
           ft::set<Key,Compare,Alloc>& rhs ) {
		lhs.swap(rhs);
	}

	/* operator== and operator!=
	** Checks if the contents of lhs and rhs are equal,
	** that is, they have the same number of elements and
	* each element in lhs compares equal with the element
	**in rhs at the same position.
	*/
	template< class Key, class Compare, class Alloc >
	bool operator==( const ft::set<Key,Compare,Alloc>& lhs,
                 const ft::set<Key,Compare,Alloc>& rhs ) {
		return (lhs.size() == rhs.size()) && (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	/* operator<, operator<=, operator> and operator>=
	** Compares the contents of lhs and rhs lexicographically.
	** The comparison is performed by a function equivalent
	** to std::lexicographical_compare.
	** This comparison ignores the map's ordering Compare.
	*/
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