/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:29:35 by lgasc             #+#    #+#             */
/*   Updated: 2023/07/27 17:44:55 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_conversion.h"

////////

ssize_t	ft_print_string(const char *const string)
{
	const char	placeholder[] = "(null)";

	if (string == NULL)
		return (write(1, placeholder, ft_strlen(placeholder)));
	return (write(1, string, ft_strlen(string)));
}

ssize_t	ft_print_integer(const int number)
{
	char	*string;
	ssize_t	code;

	string = ft_itoa(number);
	if (string == NULL)
		return (-1);
	code = write(1, string, ft_strlen(string));
	free(string);
	return (code);
}

/*ssize_t	ft_print_capital_hexadecimal(const unsigned int number)
{
	return (ft_print_hexadecimal(number, 0));
}

ssize_t	ft_print_small_hexadecimal(const unsigned int number)
{
	return (ft_print_hexadecimal(number, 1));
}*/

/*ssize_t	ft_print_percent_sign(void)
{
	return (ft_print_character('%'));
}*/

ssize_t	ft_print_character(const unsigned char character)
{
	return (write(1, &character, 1));
}

ssize_t			ft_handler(const ssize_t code, ssize_t *const length)
		__attribute__ ((warn_unused_result));
unsigned int	ft_power(const unsigned int base, const size_t exponent)
		__attribute__ ((warn_unused_result));

ssize_t	ft_print_unsigned_integer(const unsigned int number)
{
	size_t	length;
	size_t	i;

	length = 1;
	while (number / ft_power(10, length - 1) >= 10)
		length++;
	i = 0;
	while (i < length)
	{
		if (ft_handler(write(1, & "0123456789"[(number / ft_power(10, length - 1
								- i)) % 10], 1), (ssize_t * const) & i) != 0)
			return ((const ssize_t) i);
	}
	return ((const ssize_t) i);
}

ssize_t			ft_print_hexadecimal(const uintptr_t number,
			const unsigned char lowercase) __attribute__ ((warn_unused_result));

ssize_t	ft_print_pointer(const void *const pointer)
{
	const char	placeholder[] = "(nil)";
	const char	prefix[] = "0x";
	ssize_t		length;

	if (pointer == NULL)
		return (write(1, placeholder, ft_strlen(placeholder)));
	length = 0;
	if (pointer != 0)
	{
		length = write(1, prefix, ft_strlen(prefix));
		if (length < 0)
			return (length);
	}
	if (ft_handler(ft_print_hexadecimal((const uintptr_t) pointer, 1), & length)
		!= 0)
		return (length);
	return (length);
}
