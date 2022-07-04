/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/04 18:13:15 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {
	class reverse_iterator {
		public:
			reverse_iterator();
			explicit reverse_iterator (iterator_type it);
			template <class Iter>
				reverse_iterator (const reverse_iterator<Iter>& rev_it);
			iterator_type base() const;
			reference operator*() const;
			reverse_iterator operator+ (difference_type n) const;
			reverse_iterator& operator++();
			reverse_iterator  operator++(int);
			reverse_iterator& operator+= (difference_type n);
			reverse_iterator operator- (difference_type n) const;
			reverse_iterator& operator--();
			reverse_iterator  operator--(int);
			reverse_iterator& operator-= (difference_type n);
			pointer operator->() const;
			reference operator[] (difference_type n) const;
			template <class Iterator>
				bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
			template <class Iterator>
				bool oper const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
			template <class Iterator>
				bool oper const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
			template <class Iterator>
				bool oper const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
			template <class Iterator>
				bool oper const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
			template <class Iterator>
				bool oper const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
			template <class Iterator>
				reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);
			template <class Iterator>
				typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

	};
}

#endif
