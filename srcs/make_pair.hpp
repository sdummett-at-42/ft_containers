/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/09/12 13:58:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

#include "pair.hpp"

/* Creates a ft::pair object, deducing the target type from the types of 
** arguments.
*/
namespace ft {
	
	template <class T1,class T2>
  	ft::pair<T1,T2> make_pair (T1 x, T2 y) {
    	return ( ft::pair<T1,T2>(x,y) );
 	}
}

#endif
