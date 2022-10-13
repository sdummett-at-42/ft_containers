/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:12:03 by sdummett          #+#    #+#             */
/*   Updated: 2022/07/05 15:16:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

/* Checks whether T is an integral type. Provides the member constant
** value which is equal to true, if T is the type bool, char, short, int, long,
** long long, or any implementation-defined extended integer types, including
** any signed, unsigned, and cv-qualified variants. Otherwise, value is equal to false. 
*/

namespace ft {

	template<class T>
	struct is_integral {
		const static bool value = false;
	};

	template<>
	struct is_integral<bool> {
		const static bool value = true;
	};

	template<>
	struct is_integral<char> {
		const static bool value = true;
	};

	template<>
	struct is_integral<wchar_t> {
		const static bool value = true;
	};

	template<>
	struct is_integral<signed char> {
		const static bool value = true;
	};

	template<>
	struct is_integral<short int> {
		const static bool value = true;
	};

	template<>
	struct is_integral<int> {
		const static bool value = true;
	};

	template<>
	struct is_integral<long int> {
		const static bool value = true;
	};

	template<>
	struct is_integral<long long int> {
		const static bool value = true;
	};

	template<>
	struct is_integral<unsigned char> {
		const static bool value = true;
	};

	template<>
	struct is_integral<unsigned short int> {
		const static bool value = true;
	};

	template<>
	struct is_integral<unsigned int> {
		const static bool value = true;
	};

	template<>
	struct is_integral<unsigned long int> {
		const static bool value = true;
	};

	template<>
	struct is_integral<unsigned long long int> {
		const static bool value = true;
	};

}

#endif
