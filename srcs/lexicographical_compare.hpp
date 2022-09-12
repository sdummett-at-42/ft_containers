/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/12 13:56:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

/* Checks if the first range [first1, last1) is lexicographically less than the 
** second range [first2, last2). 

** Lexicographical comparison is an operation with the following properties:
**
** Two ranges are compared element by element.
** The first mismatching element defines which range is lexicographically less 
** or greater than the other.
** If one range is a prefix of another, the shorter range is lexicographically 
** less than the other.
** If two ranges have equivalent elements and are of the same length, then the 
** ranges are lexicographically equal.
** An empty range is lexicographically less than any non-empty range.
** Two empty ranges are lexicographically equal. 
*/
namespace ft {

	/* Elements are compared using operator<.
	*/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}			

	/* Elements are compared using the given binary comparison function comp.
	*/
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
}

#endif
