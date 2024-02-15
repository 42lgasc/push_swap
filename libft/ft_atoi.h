/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:44 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 17:58:55 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOI_H
# define FT_ATOI_H

# include "types.h"

enum e_atoi_code
{
	Atoi_Ok,
	NullString,
	NonNumeric,
	BeyondLimits
};
//# define E_ATOI_ERROR_LAST BeyondLimits

// Indeed, `clang` seems to support no attribute...
# ifndef __clang__
#  ifdef TEST

typedef struct __attribute__ ((designated_init)) s_atoi_result
{
	enum e_atoi_code	code;
	union
	{
		int	ok;
		//void	null_string;
		//void	non_numeric;
		//void	beyond_limits;
	};
}	t_atoi_result;

struct __attribute__ ((designated_init))	s_skip
{
	const size_t		index;
	const signed char	sign;
};
#   define FT_ATOI_H_ATTRIBUTES
#  endif
# endif
# ifndef FT_ATOI_H_ATTRIBUTES

typedef struct s_atoi_result
{
	enum e_atoi_code	code;
	union
	{
		int	ok;
		//void	null_string;
		//void	non_numeric;
		//void	beyond_limits;
	};
}	t_atoi_result;

struct s_skip
{
	const size_t		index;
	const signed char	sign;
};
# endif
#endif
