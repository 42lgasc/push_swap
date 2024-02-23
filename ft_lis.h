/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:15:17 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/16 18:15:31 by lgasc            ###   ########.fr       */
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

t_int_array		ft_lis_circular(t_int_list list)
				__attribute__ ((nonnull))
				__attribute__ ((warn_unused_result));
//t_int_array		ft_lis(t_int_list list)
//				__attribute__ ((nonnull))
//				__attribute__ ((warn_unused_result));

//enum e_firstness
//{
//	HasPrecedent,
//	IsFirst
//};

# ifdef TEST
#  ifndef __clang__

// TODO: Rename to "Khipu" or some related word.
///`.ranks`: array of the rank of each element
///	(0 is base, 1 is after 0, 2 is after 1, etc etc)
///`.knots`: array of the position of the precedent
///	defined for each element of nonzero rank
typedef struct __attribute__ ((designated_init)) s_khipu
{
	size_t	amount;
	size_t	*ranks;
	size_t	*knots;
}	t_khipu;
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
typedef struct s_khipu
{
	size_t	amount;
	size_t	*ranks;
	size_t	*knots;
}	t_khipu;
# endif
#endif
