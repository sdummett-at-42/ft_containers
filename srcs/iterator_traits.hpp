/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/04 17:53:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {
	class iterator_traits {
		public:
			template <class Iterator> class iterator_traits;
			template <class T> class iterator_traits<T*>;
			template <class T> class iterator_traits<const T*>;
	};
}

#endif
