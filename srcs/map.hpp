/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/05 17:04:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
# define MAP_HPP

#include "pair.hpp"

namespace ft {

	template < class Key,                                 // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
           >
	class map {
		public:
			/* Typedefs */
			typedef Key key_type;
			typedef T mapped_type;
			typedef ft::pair<const key_type,mapped_type> value_type;
			typedef Compare key_compare;
			// typdef ... value_compare;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef size_t size_type;

			/* Constructors */
			explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type());
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
			map (const map& x);

			/* Destructor */
			~map();
			/* operator= */
			map& operator= (const map& x);
			/* Iterators */
			// iterator begin();
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;
			/* Capacity */
			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			/* Element access */
			// mapped_type& operator[] (const key_type& k);
			/* Modfiers */
			// pair<iterator,bool> insert (const value_type& val);
			// // iterator insert (iterator position, const value_type& val);
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last);
			// void erase (iterator position);
			// size_type erase (const key_type& k);
			// // void erase (iterator first, iterator last);
			void swap (map& x);
			void clear();
			/* Observers */
			key_compare key_comp() const;
			// value_compare value_comp() const;
			/* Operations */
			// iterator find (const key_type& k);
			// const_iterator find (const key_type& k) const;
			size_type count (const key_type& k) const;
			// iterator lower_bound (const key_type& k);
			// const_iterator lower_bound (const key_type& k) const;
			// iterator upper_bound (const key_type& k);
			// const_iterator upper_bound (const key_type& k) const;
			// // pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			// // pair<iterator,iterator> equal_range (const key_type& k);
			/* Allocator */
			allocator_type get_allocator() const;
	};
}

#endif
