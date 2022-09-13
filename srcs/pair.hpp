/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/12 14:03:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PAIR_HPP
# define PAIR_HPP

/* ft::pair is a class template that provides a way to store two heterogeneous 
** objects as a single unit.
**
** If neither T1 nor T2 is a possibly cv-qualified class type with non-trivial 
** destructor, or array thereof, the destructor of pair is trivial. 
*/
namespace ft {

	template <class T1, class T2>
	struct pair {
		public:

		typedef T1 first_type;
		typedef T2 second_type;
		T1 first;
		T2 second;

		pair() {};

		template<class U, class V>
		pair (const pair<U,V>& src) {
			*this = src;
		};

		pair(const first_type& u, const second_type& v) :
			first(u),
			second(v) {};

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

	/* ------------- Non-member functinos ------------- */
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return rhs < lhs;
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs < rhs);
	}
}

#endif
