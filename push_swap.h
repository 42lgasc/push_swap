/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:06:10 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/25 16:15:26 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>

# include "libft/libft.h"

//# include "ft_lis.h"

# ifdef TEST
#  include "ft_printf/ft_printf.h"
# endif

t_int_array	ft_lis(const int circular_buffer[], size_t length)
					__attribute__ ((nonnull))
					__attribute__ ((warn_unused_result));

struct s_stacks
{
	size_t	size;
	int		*primary;
	int		*secondary;
};

//void		gnome_sort(int *destination, int *source) __attribute__ ((nonnull));

# ifndef __clang__
#  ifdef TEST

//typedef struct __attribute__ ((designated_init)) //s_int_array
//{
//	size_t	length;
//	int		ints[];
//} *const	t_int_array;
//typedef t_int_array t_iarr;
#   define PUSH_SWAP_H_ATTRIBUTES
#  endif
# endif
# ifndef PUSH_SWAP_H_ATTRIBUTES

//typedef struct //s_int_array
//{
//	size_t	length;
//	int		ints[];
//} *const	t_int_array;
//typedef t_int_array	t_iarr;
# endif
#endif
