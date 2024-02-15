/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:42:46 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 20:54:55 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TYPES_H
# define PUSH_SWAP_TYPES_H

#include "libft/bonus_types.h"
enum e_stack_mask
{
	Neither = 0,
	Primary = 1,
	Secondary = 2,
	Both = Primary | Secondary
};

# ifndef __clang__
#  ifdef TEST

// TODO: Fuse the `primary` and `secondary` arrays,
// 	as they are mutually exclusive.
struct __attribute__ ((designated_init)) s_stacks
{
	//size_t				size;
	//enum e_stack_mask	*masks;
	//size_t				primary_top;
	//int					*primary;
	t_int_list	primary;
	//size_t				secondary_top;
	//int					*secondary;
	t_int_list	secondary;
};

#   define PUSH_SWAP_TYPES_H_ATTRIBUTES
#  endif
# endif
# ifndef PUSH_SWAP_TYPES_H_ATTRIBUTES

struct s_stacks
{
	//size_t				size;
	//enum e_stack_mask	*masks;
	//size_t				primary_top;
	//int					*primary;
	t_int_list	primary;
	//size_t				secondary_top;
	//int					*secondary;
	t_int_list	secondary;
};
# endif

#endif
