/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:15:17 by lgasc             #+#    #+#             */
/*   Updated: 2023/12/21 14:15:07 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIS_H
# define FT_LIS_H
# include <assert.h>
# include <stddef.h>
# ifndef __clang__
#  ifdef TEST

struct __attribute__ ((designated_init)) s_end_predecessor
{
	enum
	{
		HasPredecessor,
		IsFirst
	}	e_is_first;
	size_t	offset;
};
#   define S_END_PREDECESSOR
#  endif
# endif
# ifndef S_END_PREDECESSOR

struct s_end_predecessor
{
	enum
	{
		HasPredecessor,
		IsFirst
	}	e_is_first;
	size_t	offset;
};
# endif

static void			ft_loop(
						const int super[const], const size_t super_length,
						size_t end_lengths[const],
						struct s_end_predecessor end_predecessors[const])
					__attribute__ ((nonnull));
					//__attribute__ ((warn_unused_result));
static const int	*ft_hydrate_lis(
						const int super[const], const size_t super_length,
						const size_t end_lengths[const],
						const struct s_end_predecessor end_predecessors[const])
					__attribute__ ((nonnull))
					__attribute__ ((warn_unused_result));
#endif
