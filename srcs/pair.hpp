/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/05 17:04:09 by sdummett         ###   ########.fr       */
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
		/* Constructors */
		pair();
		template<class U, class V> pair (const pair<U,V>& pr);
		pair (const first_type& a, const second_type& b);
		/* operator= */
		pair& operator= (const pair& pr);

			
	};

	/* Non-member function overloads */
	// std::relational operators (pair)
	template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			(void)lhs;
			(void)rhs;
		}

	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			(void)lhs;
			(void)rhs;
		}

	template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			(void)lhs;
			(void)rhs;
		}

	template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			(void)lhs;
			(void)rhs;
		}

	template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			(void)lhs;
			(void)rhs;
		}

	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
			(void)lhs;
			(void)rhs;
		}

}

#endif
