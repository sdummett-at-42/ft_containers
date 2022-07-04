/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/04 17:56:58 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

// Yes, it is C++11 but you will be able to implement it in a C++98 manner.
// This is asked so you can discover SFINAE.

namespace ft {
	class is_integral {
		public:
			template <class T> struct is_integral;
	};
}

#endif
