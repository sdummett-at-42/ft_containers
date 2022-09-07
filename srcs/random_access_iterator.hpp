/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:44:05 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/07 16:50:27 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <cstddef> // std::ptrdiff_t
#include "iterator_traits.hpp"

namespace ft {

	// -------> https://cplusplus.com/reference/iterator/RandomAccessIterator/
	template< class Iter > 
	class random_access_iterator {
		
		public:

		/* ------------- Typedefs ------------- */
		typedef Iter															iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference			reference;
		//

		
		/* ------------- Constructors ------------- */
		random_access_iterator();
		random_access_iterator(const random_access_iterator& x);
		
		
		/* ------------- operator= ------------- */
		random_access_iterator& operator=(const random_access_iterator& x);


		/* ------------- Destructor ------------- */
		virtual ~random_access_iterator() {}

		/* ------------- Operators ------------- */
		// Notes:
		//        - to implement
		//        - operators are missing
/*
		bool operator ==(const T &a, const T2 &b);
		bool operator !=(const T &a, const T2 &b);
		R& T::operator*();
		R* T::operator->();
		// (???) *a = t
		T& T::operator++();
		T T::operator++(int);
		T& T::operator--();
		T T::operator--(int); 
		T T::operator+(const T2 &b) const;
		T T::operator-(const T2 &b) const;
		bool T::operator <(const T2 &b) const;
		bool T::operator >(const T2 &b) const;
		bool T::operator <=(const T2 &b) const;
		bool T::operator >=(const T2 &b) const;
		T& T::operator +=(const T2& b);
		T& T::operator -=(const T2& b);
		R& T::operator[](S b);
*/
		protected:
			pointer _p;
	};
}

#endif