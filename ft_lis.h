/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:15:17 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/30 18:28:50 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIS_H
# define FT_LIS_H

# include <assert.h>
# include <stddef.h>
# include <stdlib.h>

# include "libft/libft.h"

# ifdef TEST
#  include "ft_printf/ft_printf.h"
# endif

//enum e_firstness
//{
//	HasPrecedent,
//	IsFirst
//};

# ifdef TEST
#  ifndef __clang__

// TODO: Rename to "Khipu" or some related word.
struct __attribute__ ((designated_init)) s_predecessions
{
	size_t	amount;
	size_t	*ranks;
	size_t	*predecessors;
};
#   define FT_LIS_H_ATTRIBUTES
#  endif
# endif
# ifndef FT_LIS_H_ATTRIBUTES

//struct s_end_predecessor
//{
//	enum
//	{
//		HasPredecessor,
//		IsFirst
//	}	e_is_first;
//	size_t	previous;
//};
struct s_predecessions
{
	size_t	amount;
	size_t	*ranks;
	size_t	*predecessors;
};
# endif

static unsigned char	ft_loop(const int super[], size_t super_length,
							struct s_predecessions precedents)
						__attribute__ ((warn_unused_result));
static t_int_array		ft_hydrate_lis(const int super[], size_t super_length,
							struct s_predecessions precedents)
						__attribute__ ((warn_unused_result));
#endif
