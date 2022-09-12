/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/12 17:30:11 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

/* The std::stack class is a container adaptor that gives the programmer the 
** functionality of a stack - specifically, a LIFO (last-in, first-out) data 
** structure.
**
** The class template acts as a wrapper to the underlying container - only a 
** specific set of functions is provided. The stack pushes and pops the element 
** from the back of the underlying container, known as the top of the stack. 
*/
namespace ft {

	template < class T, class Container = ft::vector<T> >
	class stack {
		public:

			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;


			/* ------------- Allocator ------------- */

			explicit stack( const container_type& cont = container_type() ) :
				_cont(cont),
				_size(0) {}


			/* ------------- operator= ------------- */

			stack& operator=( const stack& other ) {
				_cont = other._cont;
				_size = other._size;
				return *this;
			}


			/* ------------- Destructor ------------- */

			~stack() {}


			/* ------------- Element access ------------- */

			/* Returns reference to the top element in the stack. This is the
			** most recently pushed element. This element will be removed on a 
			** call to pop(). Effectively calls c.back(). 
			*/
			value_type& top() {
				return _cont.back();
			}


			/* ------------- Capacity ------------- */

			/* Checks if the underlying container has no elements, i.e. whether 
			** c.empty(). 
			*/
			bool empty() const {
				return (_size == 0);
			}

			/* Returns the number of elements in the underlying container, that 
			** is, c.size(). 
			*/
			size_type size() const {
				return _size;
			}


			/* ------------- Modifiers ------------- */

			/* Pushes the given element value to the top of the stack. 
			** Effectively calls c.push_back(value)
			*/
			void push (const value_type& val) {
				_cont.push_back(val);
				++_size;
			}

			/* Removes the top element from the stack. 
			** Effectively calls c.pop_back()
			*/
			void pop() {
				_cont.pop_back();
				--_size;
			}

		protected:
			/* _cont : the underlying container
			** _size : the actual number of elements stored.
			*/
			container_type	_cont;
			size_type		_size;

			template <class Type, class Cont>
			friend bool operator== (const stack<Type,Cont>&, const stack<Type,Cont>&);
			template <class Type, class Cont>
			friend bool operator!= (const stack<Type,Cont>&, const stack<Type,Cont>&);
			template <class Type, class Cont>
			friend bool operator< (const stack<Type,Cont>&, const stack<Type,Cont>&);
			template <class Type, class Cont>
			friend bool operator<= (const stack<Type,Cont>&, const stack<Type,Cont>&);
			template <class Type, class Cont>
			friend bool operator> (const stack<Type,Cont>&, const stack<Type,Cont>&);
			template <class Type, class Cont>
			friend bool operator>= (const stack<Type,Cont>&, const stack<Type,Cont>&);

	};

	/* ------------- Non-member functions ------------- */
	/* Compares the contents of the underlying containers of two container 	
	** adaptors. The comparison is done by applying the corresponding operator 
	** to the underlying containers. 
	*/

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont == rhs._cont);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return !(lhs._cont == rhs._cont);
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._cont < rhs._cont;
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont < rhs._cont) || (lhs._cont == rhs._cont);
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._cont > rhs._cont;
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._cont > rhs._cont) || (lhs._cont == rhs._cont);
	}

}

#endif
