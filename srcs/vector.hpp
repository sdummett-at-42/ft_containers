/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/06/16 15:06:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VECTOR_HPP
# define VECTOR_HPP

// #include <memory>
// #include <stdexcept>
// #include <algorithm>
// #include <cassert>

namespace ft {

class vector {
	public:
		/* Constructors */
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
		template <class InputIterator>
        vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type());
		vector (const vector& x);

		/* Destructor */
		~vector();

		/* operator= */
		vector& operator= (const vector& x);

		/* Iterators */
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/* Capacity */
		size_type size() const;
		size_type max_size() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		bool empty() const;
		void reserve (size_type n);

		/* Element access */
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		reference at (size_type n);
		const_reference at (size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		
		/* Modfiers */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
		void push_back (const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (vector& x);
		void clear();

		/* Allocator */
		allocator_type get_allocator() const;
		
		/* Non-member function overloads */
		template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
  		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
  		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
	
	private:
		
}

}

#endif
