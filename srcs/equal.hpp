/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/05 17:11:34 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft {
	
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2) {
			(void)first1;
			(void)last1;
			(void)first2;
		}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, BinaryPredicate pred) {
			(void)first1;
			(void)last1;
			(void)first2;
			(void)pred;
		}
}

#endif
