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
#include "rbtree.hpp"			// Required for Red-Black tree data structure

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
			typedef typename ft::rbtree< key_type, mapped_type, key_compare, allocator_type>::iterator iterator;
			typedef typename ft::rbtree< key_type, mapped_type, key_compare, allocator_type>::const_iterator const_iterator;
			typedef typename ft::rbtree< key_type, mapped_type, key_compare, allocator_type>::reverse_iterator reverse_iterator;
			typedef typename ft::rbtree< key_type, mapped_type, key_compare, allocator_type>::const_reverse_iterator const_reverse_iterator;


			/* ------------- Constructors ------------- */

			explicit map (	const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()) :
				_rbtree(comp, alloc) {}

			// template <class InputIterator>
			// 	map (InputIterator first, InputIterator last,
			// 	const key_compare& comp = key_compare(),
			// 	const allocator_type& alloc = allocator_type());

			map (const map& x) :
				_rbtree(x._rbtree) {
			}


			/* ------------- operator= ------------- */

			map& operator= (const map& x) {
				_rbtree = x._rbtree;
			}


			/* ------------- Allocator ------------- */

			allocator_type get_allocator() const {
				return _rbtree.get_allocator();
			}


			/* ------------- Destructor ------------- */

			~map() {}


			/* ------------- Iterators ------------- */

			iterator begin() {
				return static_cast<iterator>(_rbtree.begin());
			}
			const_iterator begin() const {
				return static_cast<const_iterator>(_rbtree.begin());
			}
			iterator end() {
				return static_cast<iterator>(_rbtree.end());
			}
			const_iterator end() const {
				return static_cast<const_iterator>(_rbtree.end());
			}
			reverse_iterator rbegin() {
				return static_cast<reverse_iterator>(_rbtree.rbegin());
			}
			const_reverse_iterator rbegin() const {
				return static_cast<const_reverse_iterator>(_rbtree.rbegin());
			}
			reverse_iterator rend() {
				return static_cast<reverse_iterator>(_rbtree.rend());
			}
			const_reverse_iterator rend() const {
				return static_cast<const_reverse_iterator>(_rbtree.rend());
			}


			/* ------------- Capacity ------------- */

			bool empty() const {
				return _rbtree.empty();
			}
			size_type size() const {
				return _rbtree.size();
			}
			size_type max_size() const {
				return _rbtree.max_size();
			}


			/* ------------- Element access ------------- */

			mapped_type& at( const key_type& key ) {
				return static_cast<mapped_type&>(_rbtree.at(key));
			}
			const mapped_type& at( const key_type& key ) const {
				return static_cast<const mapped_type&>(_rbtree.at(key));
			}
			mapped_type& operator[] (const key_type& k) {
				return _rbtree[k];
			}


			/* ------------- Modfiers ------------- */

			//  Returns a pair consisting of an iterator to the inserted element
			// (or to the element that prevented the insertion) and a bool
			// denoting whether the insertion took place.

			// Note: temporary insert -> to delete and use the one below
			ft::pair<iterator, bool> insert (const value_type& val) {
				return _rbtree.insert(val);
			}

			iterator insert (iterator position, const value_type& val) {
				return _rbtree.insert(position, val);
			}

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

			void clear() {
				_rbtree.clear();
			}


			/* ------------- Observers ------------- */

			key_compare key_comp() const {
				return _rbtree.key_comp();
			}

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

			protected:
			ft::rbtree< key_type, mapped_type, key_compare, allocator_type> _rbtree;
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
