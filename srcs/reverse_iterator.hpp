/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/07 15:23:22 by sdummett         ###   ########.fr       */
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
			typedef typename iterator_traits<Iter>::value_type value_type;
			typedef typename iterator_traits<Iter>::difference_type difference_type;
			typedef typename iterator_traits<Iter>::pointer pointer;
			typedef typename iterator_traits<Iter>::reference reference;


			/* ------------- Constructor ------------- */

			reverse_iterator() :
				current(0) {}
			
			explicit reverse_iterator (iterator_type it);
			
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) :
				current(rev_it) {}

			/* ------------- //////\\\\\\ ------------- */
			iterator_type base() const {
				return current;
			}

			reference operator*() const;
			reverse_iterator operator+ (difference_type n) const;
			reverse_iterator& operator++();
			reverse_iterator  operator++(int);
			reverse_iterator& operator+= (difference_type n);
			reverse_iterator operator- (difference_type n) const;
			reverse_iterator& operator--();
			reverse_iterator  operator--(int);
			reverse_iterator& operator-= (difference_type n);
			pointer operator->() const;
			reference operator[] (difference_type n) const;

		protected:
			iterator_type current;
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
