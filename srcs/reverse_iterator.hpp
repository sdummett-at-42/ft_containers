/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/10 12:00:05 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {

	template <class Iter>
	class reverse_iterator {

		public:

			/* ------------- Typedefs ------------- */

			typedef Iter iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer pointer;
			typedef typename ft::iterator_traits<Iter>::reference reference;


			/* ------------- Constructor ------------- */

			reverse_iterator() :
				_current() {}

			explicit reverse_iterator (iterator_type it) :
				_current(it) {}

			// template <class Iter>
			// reverse_iterator (const reverse_iterator<Iter>& iter) :
			// 	_current(iter) {}

			template< class U >
			reverse_iterator& operator=( const reverse_iterator<U>& other );

			iterator_type base() const {
				return _current;
			}


			/* ------------- Operators ------------- */

			reference operator*() const {
				iterator_type tmp = _current;
				return *--tmp;
			}

			reverse_iterator operator+ (difference_type n) const {
				return reverse_iterator(_current - n);
			}

			reverse_iterator& operator++() {
				--_current;
				return *this;
			}

			reverse_iterator  operator++(int) {
				reverse_iterator tmp(*this);
				operator++();
				return  tmp;
			}

			reverse_iterator& operator+= (difference_type n) {
				*this = *this + n;
				return *this;
			}

			reverse_iterator operator- (difference_type n) const {
				return reverse_iterator(_current + n);
			}

			reverse_iterator& operator--() {
				++_current;
				return *this;
			}

			reverse_iterator  operator--(int) {
				reverse_iterator tmp(*this);
				operator--();
				return  tmp;
			}

			reverse_iterator& operator-= (difference_type n) {
				*this = *this - n;
				return *this;
			}

			pointer operator->() const;
			reference operator[] (difference_type n) const {
				return *(_current - n - 1);
			}

		protected:
			iterator_type _current;
	};

	template <class Iter>
	bool operator== (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class Iter>
	bool operator!= (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class Iter>
	bool operator< (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class Iter>
	bool operator<= (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class Iter>
	bool operator> (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class Iter>
	bool operator>= (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
		(void)lhs;
		(void)rhs;
	}

	template <class Iter>
		reverse_iterator<Iter> operator+ (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& rev_it) {
			(void)n;
			(void)rev_it;
		}

	template <class Iter>
		typename reverse_iterator<Iter>::difference_type operator- (const reverse_iterator<Iter>& lhs, const reverse_iterator<Iter>& rhs) {
			(void)lhs;
			(void)rhs;
		}
}

#endif
