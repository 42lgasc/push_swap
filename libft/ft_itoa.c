/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:59:52 by lgasc             #+#    #+#             */
/*   Updated: 2023/06/29 19:47:21 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	power(unsigned int base, size_t exponent);

static void			hydrate_string(const int integer, const signed char sign,
						const size_t length, char *const string);

/** Allocates (with malloc(3)) and returns a string representing the
 * `integer` received as an argument. Negative numbers must be handled.
 * 
 * @param[in] integer The integer to convert.
 * 
 * @returns The string representing the integer. NULL if the allocation fails.
 * 
 * @remarks External funtion: `malloc`
 */
char	*ft_itoa(int integer)
{
	signed char		sign;
	size_t			length;
	char			*string;

	sign = 1;
	if (integer < (const signed) 0)
		sign = -1;
	length = 1;
	while (integer / (const signed int) power(10, length - 1) <= -10
		|| integer / (const signed int) power(10, length - 1) >= 10)
		length++;
	string = ft_calloc
		(length + 1 + (const unsigned int)((sign - 1) / -2), sizeof * string);
	if (! string)
		return (NULL);
	hydrate_string(integer, sign, length, string);
	return (string);
}

static unsigned int	power(const unsigned int base, const size_t exponent)
{
	if (exponent == 0)
		return (1);
	return (base * power(base, exponent - 1));
}

/**
 * @param[in] integer
 * @param[in] sign
 * @param[in] length
 * @param[out] string
 */
static void	hydrate_string(const int integer, const signed char sign,
				const size_t length, char *const string)
{
	unsigned int	i;

	i = 0;
	if (sign < (const signed) 0)
		string[0] = '-';
	while (i < length)
	{
		string[i + (const unsigned int)((sign - 1) / -2)] = (char)('0' + (
					(integer / (const signed int) power(10, length - 1 - i))
					% 10 * sign));
		i++;
	}
	string[length + (const unsigned int)((sign - 1) / -2)] = '\0';
}
