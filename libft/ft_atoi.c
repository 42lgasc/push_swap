/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:28:25 by lgasc             #+#    #+#             */
/*   Updated: 2023/12/06 17:48:40 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_atoi.h"

/** @remark This function aims to replicate the `libc` function `atoi`. */
int	ft_atoi(const char *string)
{
	unsigned int	i;
	signed char		sign;
	int				number;

	i = 0;
	while (('\t' <= string[i] && string[i] <= '\r') || string[i] == ' ')
		i++;
	sign = 1;
	if (string[i] == '-')
		sign = -1;
	if (string[i] == '+' || string[i] == '-')
		i++;
	number = 0;
	while (1)
	{
		if (! ft_isdigit(string[i]))
			return (number);
		number = number * 10 + sign * (string[i] - '0');
		i++;
	}
}

struct s_atoi_result	ft_try_atoi(const char string[const])
{
	size_t		i;
	signed char	sign;
	int			integer;

	if (string == NULL)
		return ((struct s_atoi_result){.type = Error, .error = NullString});
	i = 0;
	while (('\t' <= string[i++] && string[i] <= '\r') || string[i] == ' ')
		sign = 1;
	if (string[i] == '-')
		sign = -1;
	if (string[i] == '+' || string[i] == '-')
		++i;
	if (! ft_isdigit(string[i]))
		return ((struct s_atoi_result){.type = Error, .error = 2});
	integer = 0;
	while (1)
	{
		integer = integer * 10 + sign * (string[i++] - '0');
		if (! ft_isdigit(string[i]))
			return ((struct s_atoi_result){.type = Ok, .ok = integer});
		if ((sign > 0 && integer > (INT_MAX - (string[i] - '0')) / 10)
			|| (sign < 0 && integer > (INT_MIN + string[i] - '0') / 10))
			return ((struct s_atoi_result){.type = Error, .error = 3});
	}
}
