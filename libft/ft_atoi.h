/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:44 by lgasc             #+#    #+#             */
/*   Updated: 2023/12/19 22:57:04 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOI_H
# define FT_ATOI_H

static struct s_skip	ft_skip_prefix(const char *const string)
						__attribute__ ((warn_unused_result));

# ifndef __clang__
#  ifdef TEST

const struct __attribute__ ((designated_init)) s_skip
{
	const size_t		index;
	const signed char	sign;
};
#   define S_SKIP
#  endif
# endif
# ifndef S_SKIP

struct s_skip
{
	const size_t		index;
	const signed char	sign;
};
# endif

#endif
