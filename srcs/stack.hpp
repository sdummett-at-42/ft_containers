/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/05 17:10:26 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

// value_type	The first template parameter (T)	Type of the elements
// container_type	The second template parameter (Container)	Type of the underlying container
// size_type	an unsigned integral type	usually the same as size_t

namespace ft {

	template < class T, class Container = ft::vector<T> >
	class stack {
		public:

			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;

			explicit stack (const container_type& ctnr = container_type());
			bool empty() const;
			size_type size() const;
			value_type& top();
			const value_type& top() const;
			void push (const value_type& val);
			void pop();

	};
	// Non-member function overload
	// std::relational operators (stack)
	template <class T, class Container>
		bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			(void)lhs;
			(void)rhs;
		}

	template <class T, class Container>
		bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			(void)lhs;
			(void)rhs;
		}

	template <class T, class Container>
		bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			(void)lhs;
			(void)rhs;
		}

	template <class T, class Container>
		bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			(void)lhs;
			(void)rhs;
		}

	template <class T, class Container>
		bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			(void)lhs;
			(void)rhs;
		}

	template <class T, class Container>
		bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			(void)lhs;
			(void)rhs;
		}

}

#endif
