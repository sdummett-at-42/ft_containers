/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/13 14:12:38 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

#include <sstream>						// Required for std::stringstream
#include <memory>						// Required for std::allocator<T>
#include <cstddef>						// Required for std::ptrdiff_t
#include <iostream>						// Required for std::cout
#include "random_access_iterator.hpp"	// Required for iterators
#include "reverse_iterator.hpp"			// Required for iterators
#include "lexicographical_compare.hpp"	// Required for non-member functions
#include "enable_if.hpp"				// Required for ft::enable_if
#include "is_integral.hpp"				// Required for ft::is_integral

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public:

			/* ------------- Typedefs ------------- */

			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef ft::random_access_iterator<value_type> iterator;
			typedef ft::random_access_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator; 
			

			/* ------------- Constructors ------------- */

			/* Constructs an empty container, with no elements.
			*/
			explicit vector (const allocator_type& alloc = allocator_type()) : 
				_alloc(alloc),
				_p(0),
				_size(0),
				_capacity(0) {}

			/* Constructs a container with n elements. Each element is a copy 
			** of val.
			*/
			explicit vector (const size_type& n, const value_type& val = value_type(), 
				const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_p(0),
				_size(0),
				_capacity(0) {
				reserve(n);
				for (size_type i = 0; i < n; i++) {
					_alloc.construct(_p + i, val);
				}
				_size = n;
			}

			/* Constructs a container with as many elements as the range [first,
			** last), with each element constructed from its corresponding 
			** element in that range, in the same order.
			*/
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type* = NULL) :
				_alloc(alloc),
				_p(0),
				_size(0),
				_capacity(0) {
				size_type n = get_iterators_diff(first, last);
				reserve(n);
				_size = n;
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_p + i, *first);
					++first;
				}
			}

			/* Constructs a container with a copy of each of the elements in x, ** in the same order.
			*/
			vector (const vector& x) :
				_alloc(allocator_type()),
				_p(0),
				_size(0),
				_capacity(0) {
				*this = x;
			}


			/* ------------- operator= ------------- */

			/* Copy assignment operator. Replaces the contents with a copy of   ** the contents of other. 
			*/
			vector& operator= (const vector& x) {
				for (size_type i = 0; i < _size; i++) {
					_alloc.destroy(_p + i);
				}
				reserve(x._size);
				_size = x._size;
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_p + i, *(x._p + i));
				}
				return *this;
			}

			/* ------------- Destructor ------------- */

			/* Destructs the vector. The destructors of
			** the elements are called and the used storage
			** is deallocated.
			*/
			~vector() {
				clear();
				_alloc.deallocate(_p, _capacity);
			}


			/* ------------- Iterators ------------- */

			/* Returns an iterator to the first element of the vector.
			** If the vector is empty, the returned iterator will be equal to 
			** end(). 
			*/
			iterator begin() {
				return static_cast<iterator>(_p);
			}
			const_iterator begin() const {
				return static_cast<const_iterator>(_p);
			}

			/* Returns an iterator to the element following the last element //
			** of the vector.
			** This element acts as a placeholder; attempting to access it 
			** results in undefined behavior. 
			*/
			iterator end() {
				return static_cast<iterator>(_p + _size);
			}
			const_iterator end() const {
				return static_cast<const_iterator>(_p + _size);
			}

			/* Returns a reverse iterator to the first element of the reversed
			** vector. It corresponds to the last element of the non-reversed 
			** vector. If the vector is empty, the returned iterator is equal 
			** to rend(). 
			*/
			reverse_iterator rbegin() {
				return static_cast<reverse_iterator>(end());
			}
			const_reverse_iterator rbegin() const {
				return static_cast<const_reverse_iterator>(end());
			}
			reverse_iterator rend() {
				return static_cast<reverse_iterator>(begin());
			}
			const_reverse_iterator rend() const {
				return static_cast<const_reverse_iterator>(begin());
			}


			/* ------------- Capacity ------------- */

			/* Returns the number of elements in the container
			*/
			size_type size() const {
				return _size;
			}

			/* Returns the maximum number of elements the container is able to
			** hold due to system or library implementation limitations
			*/
			size_type max_size() const {
				return _alloc.max_size();
			}

			/* Resizes the container to contain count elements. 
			*/
			void resize (size_type n, value_type val = value_type()) {
				if (n > _capacity)
					reserve(n);
				if (n < _size) {
					for (size_type i = n; i < _size; i++) {
						_alloc.destroy(_p + i);
					}
					_size = n;
				}
				else if (n > _size) {
					for (size_type i = _size; i < n; i++) {
						_alloc.construct(_p + i, val);
					}
					_size = n;
				}
			}

			/* Returns the number of elements that the container has currently
			** allocated space for. 
			*/
			size_type capacity() const {
				return _capacity;
			}

			/* Checks if the container has no elements
			*/
			bool empty() const {
				if (_size == 0)
					return true;
				return false;
			}

			/* Increase the capacity of the vector (the total number
			** of elements that the vector can hold without requiring
			** reallocation) to a value that's greater or equal to new_cap.
			** If new_cap is greater than the current capacity(), new storage
			** is allocated, otherwise the function does nothing. 
			*/
			void reserve (size_type new_cap) {
				if (new_cap <= _capacity)
					return ;
				if (new_cap > _alloc.max_size())
					throw std::length_error("vector::reserve");
				size_type max = max = _alloc.max_size();
				for (size_type opti = 16; opti < max; opti *= 2) {
					if ((new_cap > opti / 2) && (new_cap <= opti)) {
						if (_capacity < opti && new_cap < opti)
							new_cap = opti;
						break;
					}
				}
				pointer tmp_p = _p;
				size_type tmp_capacity = _capacity;
				_p = _alloc.allocate(new_cap);
				_capacity = new_cap;
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_p + i, *(tmp_p + i));
					_alloc.destroy(tmp_p + i);
				}
				_alloc.deallocate(tmp_p, tmp_capacity);
			}


			/* ------------- Element access ------------- */

			/* Returns a reference to the element at specified
			** location pos. No bounds checking is performed. 
			*/
			reference operator[] (size_type n) {
				return *(_p + n);
			}
			const_reference operator[] (size_type n) const  {
				return *(_p + n);
			}

			/* Returns a reference to the element at specified location pos, 
			** with bounds checking.
			** If pos is not within the range of the container, an exception of 
			** type std::out_of_range is thrown. 
			*/
			reference at (size_type n) {
				if (!(n < size())) {
					std::string what;
					what = "vector:_M_range_check: __n (which is " + 
						to_string(n) + ") >= this->size() (which is " + 
						to_string(_size) + ")";
					std::cout << what; 
					throw std::out_of_range("");
				}
				return *(_p + n);
			}
			const_reference at (size_type n) const {
				if (!(n < size())) {
					std::string what;
					what = "vector:_M_range_check: __n (which is " + 
						to_string(n) + ") >= this->size() (which is " + 
						to_string(_size) + ")";
					std::cout << what; 
					throw std::out_of_range("");
				}
				return *(_p + n);
			}

			/* Returns a reference to the first element in the container.
			** Calling front on an empty container is undefined. 
			*/
			reference front() {
				return *_p;
			}
			const_reference front() const {
				return *_p;
			}

			/* Returns a reference to the last element in the container.
			** Calling back on an empty container causes undefined behavior. 
			*/
			reference back() {
				return *(_p + _size - 1);
			}
			const_reference back() const {
				return *(_p + _size - 1);
			}

			/* Returns pointer to the underlying array serving as element 
			** storage. The pointer is such that range [data(); data()+size()) 
			** is always a valid range, even if the container is empty (data() 
			** is not dereferenceable in that case).
			*/
			T* data() {
				return _p;
			}
			const T* data() const {
				return _p;
			}
			

			/* ------------- Modfiers ------------- */

			/* Replaces the contents with copies of those in the range [first, 
			** last). The behavior is undefined if either argument is an 
			** iterator into *this.
			*/
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type* = NULL) {
				size_type n = get_iterators_diff(first, last);
				clear();
				reserve(n);
				_size = n;
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_p + i, *first);
					++first;
				}
			}

			/* Replaces the contents of the container with count copies of 
			** value value
			*/
			void assign (size_type n, const value_type& val) {
				size_type old_size = _size;
				reserve(n);
				for (size_type i = 0; i < n; i++) {
					if (i < old_size)
						_alloc.destroy(_p + i);
					_alloc.construct(_p + i, val);
				}
				_size = n;
			}

			/* Appends the given element value to the end of the container.
			** 1) The new element is initialized as a copy of value.
			** 2) value is moved into the new element.
			** If the new size() is greater than capacity() then all iterators
			** and references (including the past-the-end iterator) are 
			** invalidated. Otherwise only the past-the-end iterator is 
			** invalidated. 
			*/
			void push_back (const value_type& val) {
				if (_size + 1 > _capacity)
					reserve(_capacity + 1);
				_alloc.construct(_p + _size, val);
				++_size;
			}

			/* Removes the last element of the container.
			** Calling pop_back on an empty container results in undefined 
			** behavior.
			** Iterators and references to the last element, as well as the 
			** end() iterator, are invalidated. 
			*/
			void pop_back() {
				_alloc.destroy(_p + _size - 1);
				--_size;
			}

			/* Inserts elements at the specified location in the container
			** Inserts value before pos.
			*/
			iterator insert (iterator position, const value_type& val) {
				iterator	it;
				value_type	tmp_val;
				value_type	to_move;
				size_type	i = 0;

				for (it = begin(); it != end() && it != position; it++)
					++i;
				if (_size + 1 > _capacity)
					reserve(_capacity + 1);
				++_size;
				tmp_val = *(_p + i);
				_alloc.destroy(_p + i);
				_alloc.construct(_p + i, val);
				it = begin() + i;
				++i;
				while (i != _size) {
					to_move = tmp_val;
					tmp_val = *(_p + i);
					_alloc.destroy(_p + i);
					_alloc.construct(_p + i, to_move);
					++i;
				}
				return it;
			}

			/* Inserts elements at the specified location in the container
			** Inserts count copies of the value before pos.
			*/
			void insert (iterator position, size_type n, const value_type& val) {
				size_type i = 0;
				for (iterator it = begin(); it != end() && it != position; it++)
					++i;
				if (_size + n > _capacity)
					reserve(_capacity + n);
				_size += n;
				for (size_type j = _size; j - n > i; j--) {
					_alloc.construct(_p + j - 1, *(_p + j - n - 1));
					_alloc.destroy(_p + j - n -1);
				}
				while (n != 0) {
					_alloc.construct(_p + i, val);
					++i;
					--n;
				}
			}

			/* Inserts elements from range [first, last) before pos. 
			*/
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator >::type* = NULL) {
				size_type n = get_iterators_diff(first, last);
				size_type i = static_cast<size_type>(position - begin());
				if (_size + n > _capacity)
					reserve(_capacity + n);
				_size += n;
				for (size_type j = _size; j - n > i; j--) {
					_alloc.construct(_p + j - 1, *(_p + j - n - 1));
					_alloc.destroy(_p + j - n -1);
				}
				while (n != 0) {
					_alloc.construct(_p + i, *first);
					++first;
					++i;
					--n;
				}
			}

			/* Removes the element at pos.
			*/
			iterator erase (iterator position){
				size_type pos = position - begin();
				pointer p = position.base();
				_alloc.destroy(_p + pos);
				for (; pos + 1 < _size; pos++) {
					_alloc.construct(_p + pos, *(_p + pos + 1));
					_alloc.destroy(_p + pos + 1);
				}
				--_size;
				return iterator(p);
			}

			/* Removes the elements in the range [first, last).
			*/
			iterator erase (iterator first, iterator last) {
				if (first == last)
					return last;
				size_type pos = first - begin();
				size_type diff = last - first;
				for (; first != last; first++)
					_alloc.destroy(first.base());

				for (size_type i = pos; i + diff < _size; i++) {
					_alloc.construct(_p + i, *(_p + i + diff));
					_alloc.destroy(_p + i + diff);
				}
				_size -= diff;
				return iterator(_p + pos);
			}

			/* Exchanges the contents of the container with those of other. 
			** Does not invoke any move, copy, or swap operations on individual 
			** elements.
			** All iterators and references remain valid. The past-the-end 
			** iterator is invalidated. 
			*/
			void swap (vector& x) {
				allocator_type	tmp_alloc = _alloc;
				pointer			tmp_p = _p;
				size_type		tmp_size = _size;
				size_type		tmp_capacity = _capacity;

				_alloc = x._alloc;
				_p = x._p;
				_size = x._size;
				_capacity = x._capacity;

				x._alloc = tmp_alloc;
				x._p = tmp_p;
				x._size = tmp_size;
				x._capacity = tmp_capacity;
			}
			
			/* Erases all elements from the container. After this call, size()
			** returns zero. 
			*/
			void clear() {
				for (size_type i = 0; i < _size; i++) {
					_alloc.destroy(_p + i);
				}
				_size = 0;
			}


			/* ------------- Allocator ------------- */

			/* Returns the allocator associated with the container. 
			*/
			allocator_type get_allocator() const {
				return _alloc;
			}

		private:
			/* _alloc    : for memory management, by default it is
			** std::allocator<T> .
			** _p        : the pointer holding the data
			** _size     : the actual number of elements stored.
			** _capacity : the number of elements that can be stored.
			*/
			allocator_type	_alloc;
			pointer			_p;
			size_type		_size;
			size_type		_capacity;
			/* Converts a numeric value to std::string.
			*/
			std::string	to_string(const size_type &i) const {
				std::stringstream ss;
				ss << i;
				return ss.str();
			}
			/* Get the difference between two iterators.
			*/
			template <class InputIterator>
			size_type get_iterators_diff(InputIterator first, InputIterator last) {
				size_type n = 0;
				while (first != last) {
					++first;
					++n;
				}
				return n;
			}
	};


	/* ------------- Non-member function ------------- */

	/* operator==(), operator=!()
	** Checks if the contents of lhs and rhs are equal, that is, they have the
	** same number of elements and each element in lhs compares equal with the 
	** element in rhs at the same position.
	*/
	template <class T, class Alloc>
	bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		const T* pointer_lhs = lhs.data();
		const T* pointer_rhs = rhs.data();
		for (size_t i = 0; i != lhs.size(); i++) {
			if (*(pointer_lhs + i) != *(pointer_rhs + i))
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}

	/* operator<, operator<=, operator>, operator>=, oper
	** Compares the contents of lhs and rhs lexicographically. The comparison 
	** is performed by a function equivalent to std::lexicographical_compare.
	*/
	template <class T, class Alloc>
	bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
		const T* pointer_lhs_begin = lhs.data();
		const T* pointer_lhs_end = lhs.data() + lhs.size();
		const T* pointer_rhs_begin = rhs.data();
		const T* pointer_rhs_end = rhs.data() + rhs.size();
		if (ft::lexicographical_compare(pointer_lhs_begin, pointer_lhs_end, pointer_rhs_begin, pointer_rhs_end))
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
		return !(lhs < rhs) && !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
		return (lhs > rhs || lhs == rhs);
	}

	/* Exchanges the contents of the container with those of other. Does not 
	** invoke any move, copy, or swap operations on individual elements. 
	*/
	template <class T, class Alloc>
	void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {
		x.swap(y);
	}
}

#endif
