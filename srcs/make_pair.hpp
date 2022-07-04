/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/04 18:06:56 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

namespace ft {
	class make_pair {
		public:
			template <class T1, class T2>
  				pair<T1,T2> make_pair (T1 x, T2 y);
	};
}

#endif
