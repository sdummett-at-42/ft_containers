/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/05 11:59:16 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
template <class T1, class T2>
	struct pair {
		public:

		typedef T1 first_type;
		typedef T2 second_type;
		T1 first;
		T2 second;

		/* Constructors */
		pair() {};

		template<class U, class V>
		pair (const pair<U,V>& src) {
			*this = src;
		};

		pair(const first_type& u, const second_type& v) :
			first(u),
			second(v) {};

		/* operator= */
		pair& operator= (const pair& src) {
			this->first = src.first;
			this->second = src.second;
			return *this;
		}
		void swap (pair& src) { 
			T1 tmpFirst;
			T2 tmpSecond;
			tmpFirst = this->first;
			tmpSecond = this->second;
			this->first = src.first;
			this->second = src.second;
			src.first = tmpFirst;
			src.second = tmpSecond;
		};
	};

	/* Non-member function overloads */
	// std::relational operators (pair)
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	template <class T1, class T2>
	void swap (pair<T1,T2>& x, pair<T1,T2>& y) {
		T1 tmpFirst;
		T2 tmpSecond;
		tmpFirst = x.first;
		tmpSecond = x.second;
		x.first = y.first;
		x.second = y.second;
		y.first = tmpFirst;
		y.second = tmpSecond;
	}
}


#endif
