/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:28:25 by lgasc             #+#    #+#             */
/*   Updated: 2023/12/19 22:38:51 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_atoi.h"

///@remark This function aims to replicate the `libc` function `atoi`.
int	ft_atoi(const char *string)
{
	const struct s_skip	skip = ft_skip_prefix(string);
	unsigned int		i;
	signed char			sign;
	int					number;

	i = skip.index;
	sign = skip.sign;
	number = 0;
	while (1)
	{
		if (! ft_isdigit(string[i]))
			return (number);
		number = number * 10 + sign * (string[i] - '0');
		i++;
	}
}
#define S sign
#define I integer
#define C string

struct s_atoi_result	ft_try_atoi(const char string[const])
{
	const struct s_skip	skip = ft_skip_prefix(string);
	size_t				i;
	signed char			sign;
	int					integer;

	if (string == NULL)
		return ((struct s_atoi_result){.type = Error, .error = NullString});
	i = skip.index;
	sign = skip.sign;
	if (! ft_isdigit(string[i]))
		return ((struct s_atoi_result){.type = Error, .error = NonNumeric});
	integer = 0;
	while (1)
	{
		integer = integer * 10 + sign * (string[i++] - '0');
		if (! ft_isdigit(string[i]))
			return ((struct s_atoi_result){.type = Ok, .ok = integer});
		if (
			(S > 0 && I > (INT_MAX - C[i] + '0') / 10)
			|| (S < 0 && I > (INT_MIN + C[i] - '0') / 10))
			return (
				(struct s_atoi_result){.type = Error, .error = BeyondLimits});
	}
}

static struct s_skip	ft_skip_prefix(const char *const string)
{
	size_t		index;
	signed char	sign;

	index = 0;
	while (ft_isspace(string[index]))
		++index;
	sign = 1;
	if (string[index] == '-')
		sign = -1;
	if (string[index] == '+' || string[index] == '-')
		++index;
	return ((struct s_skip){.index = index, .sign = sign});
}
