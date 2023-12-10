/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:34:57 by lgasc             #+#    #+#             */
/*   Updated: 2023/06/29 19:12:55 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	power(const unsigned int base, const size_t exponent);

/** Outputs the integer `integer` to the given `file_descriptor`.
 * @param[in] integer The integer to output.
 * @param[in] file_descriptor The file descriptor on which to write.
 * @remarks External function: `write`
 */
void	ft_putnbr_fd(int integer, int file_descriptor)
{
	size_t			length;
	unsigned int	i;
	signed char		sign;

	sign = 1;
	if (integer < 0)
	{
		sign = -1;
		write(file_descriptor, "-", 1);
	}
	length = 1;
	while (integer / (const signed int) power(10, length - 1) <= -10
		|| integer / (const signed int) power(10, length - 1) >= 10)
		length++;
	i = 0;
	while (i < length)
	{
		write(file_descriptor, & "0123456789"[(integer / (const signed int)
				power(10, length - 1 - i)) % 10 * sign], 1);
		i++;
	}
}

static unsigned int	power(const unsigned int base, const size_t exponent)
{
	if (exponent == 0)
		return (1);
	return (base * power(base, exponent - 1));
}
