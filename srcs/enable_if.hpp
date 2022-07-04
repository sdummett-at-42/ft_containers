/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/04 17:56:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

// Yes, it is C++11 but you will be able to implement it in a C++98 manner.
// This is asked so you can discover SFINAE.

namespace ft {
	class enable_if {
		public:
			template <bool Cond, class T = void> struct enable_if;
	};
}

#endif