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
// #include "iterator_tags.hpp"

namespace ft {

	// -------> https://cplusplus.com/reference/iterator/RandomAccessIterator/
	template< class Category, class T, 
	class Distance = std::ptrdiff_t, 
	class Pointer = T*, class Reference = T& > 
	struct iterator {
		
		public:

		/* ------------- Typedefs ------------- */
		
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;

		/* ------------- Constructors ------------- */
		iterator() :
			_base(0) {}
		iterator(const iterator& x) {


		/* ------------- operator= ------------- */
		}
		iterator& operator=(const iterator& x) {

		}

		/* ------------- Destructor ------------- */
		~iterator() {}

		/* ------------- Operators ------------- */
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
		private:
			value_type _base;
	};
}

#endif