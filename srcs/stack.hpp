/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/04 17:42:37 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STACK_HPP
# define STACK_HPP

namespace ft {
	class stack {
		public:
			explicit stack (const container_type& ctnr = container_type());
			bool empty() const;
			size_type size() const;
			value_type& top();
			const value_type& top() const;
			void push (const value_type& val);
			void pop();

			// Non-member function overload
			// std::relational operators (stack)
			template <class T, class Container>
				bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			template <class T, class Container>
				bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			template <class T, class Container>
				bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			template <class T, class Container>
				bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			template <class T, class Container>
				bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
			template <class T, class Container>
				bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
	};
}

#endif
