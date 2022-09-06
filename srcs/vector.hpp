/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/06 17:27:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <cstddef>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			/* --- Typedefs --- */
			typedef Alloc allocator_type;
			typedef size_t size_type;
			typedef T value_type;
			typedef std::ptrdiff_t difference_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			/* Still need to add typedefs from documentations (iterators 
			   for example) */
			
			/* --- Constructors --- */
			// Constructs an empty container, with no elements.
			explicit vector (const allocator_type& alloc = allocator_type()) : 
				_alloc(alloc),
	       		_size(0),
				_capacity(0) { std::cout << "Default constructor called\n";}

			// Constructs a container with n elements. Each element is a copy 
			// of val.
			 explicit vector (const size_type& n, const value_type& val = value_type(), 
            	const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_size(0),
				_capacity(0) {
				// Notes: Maybe reserving a bit more so we dont have to allocate
				// memory frequently
				std::cout << "This constructor is called\n";
				reserve(n);
				for (size_type i = 0; i < n; ++i) {
					_alloc.construct(_p + i, val);
				}
				_size = n;
				std::cout << "Elements contained\n";
				for (int i = 0; i < _size; i++) {
					std::cout << " - " << *(_p + i) << "\n";
				}
			}

			// Constructs a container with as many elements as the range [first,
			// last), with each element constructed from its corresponding 
			// element in that range, in the same order.
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, \
				const allocator_type& alloc = allocator_type());

			// Constructs a container with a copy of each of the elements in x, in the same order.
			vector (const vector& x);

			/* --- operator= --- */
			vector& operator= (const vector& x);

			/* --- Destructor --- */
			~vector() {
				empty();
				_alloc.deallocate(_p, _capacity);
			}

			// /* Iterators */
			// iterator begin();
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			/* --- Capacity --- */
			// Returns the number of elements in the container
			size_type size() const {
				return _size;
			}
			
			// Returns the maximum number of elements the container is able to
			// hold due to system or library implementation limitations
			size_type max_size() const {
				return _alloc.max_size();
			}
			
			// Resizes the container to contain count elements. 
			void resize (size_type n, value_type val = value_type()) {
				// Notes: check what is the default value
				// Is the one given at construction
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

			// Returns the number of elements that the container has currently
			// allocated space for. 
			size_type capacity() const {
				return _capacity;
			}
			
			// Checks if the container has no elements
			bool empty() const {
				if (_size == 0)
					return true;
				return false;
			}

			void reserve (size_type new_cap) {
				// if less or equal than the actual
				// capacity, no need to reallocate memory
				if (new_cap <= _capacity)  
					return ;
				if (new_cap > _alloc.max_size()) {
					// throw an error :
					// std::length_error if new_cap > max_size(). 
					return ;
				}
				pointer tmp_p = _p;
				_p = _alloc.allocate(new_cap);
				_capacity = new_cap;
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(_p + i, *(tmp_p + i));
					_alloc.destroy(tmp_p + i);
				}
				_alloc.deallocate(tmp_p);
			}

			/* --- Element access --- */
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			reference at (size_type n);
			const_reference at (size_type n) const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
			
			/* --- Modfiers --- */
			// template <class InputIterator>
			// // void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val);
			void push_back (const value_type& val);
			void pop_back();
			// iterator insert (iterator position, const value_type& val);
			// void insert (iterator position, size_type n, const value_type& val);
			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last);
			// iterator erase (iterator position);
			// iterator erase (iterator first, iterator last);
			void swap (vector& x);
			
			// Erases all elements from the container. After this call, size()
			// returns zero. 
			void clear() {
				for (size_type i = 0; i < _size; i++) {
					_alloc.destroy(_p + i);
				}
				_size = 0;
			}

			/* --- Allocator --- */
			allocator_type get_allocator() const;

		private:
			allocator_type	_alloc;
			pointer			_p;
			size_type		_size; // the number of elements
			size_type		_capacity; // the number of elements that can be held in currently allocated storage

	};

	/* Non-member function overloads */
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		(void)x;
		(void)y;
	}
}

#endif
