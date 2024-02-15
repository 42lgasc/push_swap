/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:28:25 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 17:49:33 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include "ft_atoi.h"

//\// Indeed, `clang` seems to support no attribute...
//# ifndef __clang__
//#  ifdef TEST
//
//const struct __attribute__ ((designated_init)) s_skip
//{
//	const size_t		index;
//	const signed char	sign;
//};
//#   define S_SKIP
//#  endif
//# endif
//# ifndef S_SKIP

//struct s_skip
//{
//	const size_t		index;
//	const signed char	sign;
//};
//#endif

static struct s_skip	ft_skip_prefix(const char *const string)
						__attribute__ ((warn_unused_result))
						__attribute__ ((nonnull));

///@remark This function aims to replicate the `libc` function `atoi`.
int	ft_atoi(const char *string)
{
	const struct s_skip	skip = ft_skip_prefix(string);
	size_t				i;
	signed char			sign;
	int					number;

	i = skip.index;
	sign = skip.sign;
	number = 0;
	while (1)
		if (! ft_isdigit(string[i]))
			return (number);
	else
		number = number * 10 + sign * (string[i++] - '0');
}
//#define S sign
//#define I integer
//#define C string

t_atoi_result	ft_try_atoi(const char string[const])
{
	const struct s_skip	skip = ft_skip_prefix(string);
	size_t				i;
	signed char			sign;
	int					integer;

	if (string == NULL)
		return ((t_atoi_result){.code = NullString});
	i = skip.index;
	sign = skip.sign;
	if (! ft_isdigit(string[i]))
		return ((t_atoi_result){.code = NonNumeric});
	integer = 0;
	while (1)
	{
		integer = integer * 10 + sign * (string[i++] - '0');
		if (! ft_isdigit(string[i]))
			return ((t_atoi_result){.code = Atoi_Ok, .ok = integer});
		if ((sign > 0 && integer > (INT_MAX - string[i] + '0') / 10)
			|| (sign < 0 && integer > (INT_MIN + string[i] - '0') / 10))
			return ((t_atoi_result){.code = BeyondLimits});
	}
}

// Statics

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
