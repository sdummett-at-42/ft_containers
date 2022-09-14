/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:44:05 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/14 11:55:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <cstddef> // std::ptrdiff_t
#include "iterator_traits.hpp"

namespace ft {

	/* https://cplusplus.com/reference/iterator/RandomAccessIterator/
	*/
	template< class Iter > 
	class random_access_iterator {
		
		public:

		/* ------------- Typedefs ------------- */
		typedef Iter iterator_type;
		typedef typename std::iterator<std::random_access_iterator_tag, Iter>::iterator_category iterator_category;
		typedef typename  std::iterator<std::random_access_iterator_tag, Iter>::value_type value_type;
		typedef typename  std::iterator<std::random_access_iterator_tag, Iter>::difference_type	difference_type;
		typedef typename  std::iterator<std::random_access_iterator_tag, Iter>::pointer pointer;
		typedef typename  std::iterator<std::random_access_iterator_tag, Iter>::reference reference;

		
		/* ------------- Constructors ------------- */
		random_access_iterator() :
			_p(0) {}

		template <typename T>
		random_access_iterator (const ft::random_access_iterator<T>& it) :
			_p(it.base()) {}

		random_access_iterator(pointer p) :
			_p(p) {}
		
		
		/* ------------- operator= ------------- */
		random_access_iterator& operator=(const random_access_iterator& x) {
			_p = x._p;
			return *this;
		}


		/* ------------- Destructor ------------- */
		virtual ~random_access_iterator() {}


		/* Returns the underlying pointer
		*/
		iterator_type* base() const {
			return _p;
		}


		/* ------------- Operators ------------- */

		Iter& operator*(){
			return *_p;
		}

		Iter* operator->() {
			return &(*_p);
		}

		random_access_iterator& operator++() {
			_p++;
			return *this;
		}

		random_access_iterator operator++(int) {
			random_access_iterator tmp(*this);
			operator++();
			return tmp;
		}

		random_access_iterator& operator--(){
			_p--;
			return *this;

		}

		random_access_iterator operator--(int){
			random_access_iterator tmp(*this);
			operator--();
			return tmp;
		}

		random_access_iterator operator+(const difference_type &n) const {
			return random_access_iterator(_p + n);
		}

		random_access_iterator operator-(const difference_type &n) const {
			return random_access_iterator(_p - n);
		}

		difference_type operator-(const random_access_iterator &b) const {
			return _p - b._p;
		}

		bool operator <(const random_access_iterator &b) const {
			return (_p < b._p);
		}

		bool operator >(const random_access_iterator &b) const {
			return !(_p < b._p) && (_p != b._p);
		}

		bool operator <=(const random_access_iterator &b) const {
			return _p < b._p || _p == b._p;
		}

		bool operator >=(const random_access_iterator &b) const {
			return _p > b._p || _p == b._p;
		}

		random_access_iterator& operator +=(const difference_type& n) {
			*this = *this + n;
			return *this;
		}

		random_access_iterator& operator -=(const difference_type& n) {
			*this = *this - n;
			return *this;
		}

		value_type& operator[](difference_type n) {
			return *(_p + n);
		}

		protected:
			iterator_type* _p;
	};


	/* ------------- Non-member function ------------- */

	template <class Iterator1, class Iterator2>
	bool operator==(const random_access_iterator<Iterator1>& lhs,
					const random_access_iterator<Iterator2>& rhs) {
		return lhs.base() == rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const random_access_iterator<Iterator1>& lhs,
					const random_access_iterator<Iterator2>& rhs) {
		return !(lhs.base() == rhs.base());
	}

	template <class Iterator1, class Iterator2>
	bool operator<( const random_access_iterator<Iterator1>& lhs,
					const random_access_iterator<Iterator2>& rhs) {
		return lhs.base() < rhs.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const random_access_iterator<Iterator1>& lhs,
					const random_access_iterator<Iterator2>& rhs) {
		return (lhs < rhs) || (lhs == rhs);
	}

	template <class Iterator1, class Iterator2>
	bool operator> (const random_access_iterator<Iterator1>& lhs,
					const random_access_iterator<Iterator2>& rhs) {
		return !(lhs < rhs) && (lhs != rhs);
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const random_access_iterator<Iterator1>& lhs,
					const random_access_iterator<Iterator2>& rhs) {
		return (lhs > rhs) || (lhs == rhs);
	}

	template <class Iterator1>
	random_access_iterator<Iterator1> operator+ (typename random_access_iterator<Iterator1>::difference_type n, const random_access_iterator<Iterator1>& it) {
		return it + n;
	}

	template <class Iterator1, class Iterator2>
	typename random_access_iterator<Iterator1>::difference_type operator- (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs) {
		return lhs.base() - rhs.base();
	}
}


#endif