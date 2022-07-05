/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/05 17:12:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

// It's a function template

namespace ft {
	
	template <class T1, class T2>
  	pair<T1,T2>
	make_pair (T1 x, T2 y) {
		(void)x;
		(void)y;
	};
}

#endif
