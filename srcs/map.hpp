/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/15 11:32:15 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
# define MAP_HPP

#include <functional>			// Required for std::less<Key>
#include <memory>				// Required for std::allocator<T>
#include "pair.hpp"				// Required for ft::pair<const key_type,mapped_type>
#include "rbtree_iterator.hpp"	// Required for iterator

namespace ft {

	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key, T> > > 
		class map {

		public:

			/* ------------- Typedefs ------------- */

			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const key_type,mapped_type> value_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			// typedef ft::bidirectional_iterator<value_type> iterator;
			// typedef ft::bidirectional_iterator<const value_type> const_iterator;
			// typedef ft::reverse_iterator<iterator> reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator; 


			/* ------------- Constructors ------------- */

			explicit map (	const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type());
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
			map (const map& x);


			/* ------------- operator= ------------- */

			map& operator= (const map& x);


			/* ------------- Allocator ------------- */

			allocator_type get_allocator() const;


			/* ------------- Destructor ------------- */

			~map();


			/* ------------- Iterators ------------- */

			// iterator begin();
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;


			/* ------------- Capacity ------------- */

			bool empty() const;
			size_type size() const;
			size_type max_size() const;


			/* ------------- Element access ------------- */

			mapped_type& at( const key_type& key );
			const mapped_type& at( const key_type& key ) const;
			// mapped_type& operator[] (const key_type& k);


			/* ------------- Modfiers ------------- */

			// ft::pair<iterator,bool> insert (const value_type& val);
			// iterator insert (iterator position, const value_type& val);
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last);

			// Notes : erase with iterator as parameter have
			// 			different return type on cplusplus.com
			//			and cppreference.com
			// void erase (iterator position);
			// void erase (iterator first, iterator last);
			// 			OR
			// iterator erase( iterator pos );
			// iterator erase( iterator first, iterator last );
			// size_type erase (const key_type& k);
			void swap (map& x);
			void clear();


			/* ------------- Observers ------------- */

			key_compare key_comp() const;
			// value_compare value_comp() const;


			/* ------------- Lookup ------------- */

			// iterator find (const key_type& k);
			// const_iterator find (const key_type& k) const;
			size_type count (const key_type& k) const;
			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;
			// iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;
			// ft::pair<iterator,iterator> equal_range (const key_type& k);
			// ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

	};


	/* ------------- Non-member function ------------- */

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs,
           ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs );

}

#endif
