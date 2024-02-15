/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:41:57 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 18:01:49 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

#include "ft_printf_utils.h"

/// @param[in] code
/// @param[out] length
ssize_t	ft_handler(const ssize_t code, ssize_t *const length)
{
	if (code < 0)
	{
		*length = code;
		return (code);
	}
	*length += code;
	return (0);
}

////////

ssize_t	ft_print_hexadecimal(
			const uintptr_t number, const unsigned char lowercase)
{
	uintptr_t	power;
	const char	hexadigit[2][16] = {"0123456789ABCDEF", "0123456789abcdef"};
	size_t		remaining_length;
	ssize_t		length;

	power = 1;
	remaining_length = 1;
	while (number / power >= 0x10)
	{
		power *= 0x10;
		remaining_length++;
	}
	length = 0;
	while (remaining_length > 0)
	{
		if (ft_handler(write(1, & hexadigit[lowercase][number / power % 0x10],
				1), & length) != 0)
			return (length);
		power /= 0x10;
		remaining_length--;
	}
	return (length);
}

unsigned int	ft_power(const unsigned int base, const size_t exponent)
{
	if (exponent == 0)
		return (1);
	return (base * ft_power(base, exponent - 1));
}
