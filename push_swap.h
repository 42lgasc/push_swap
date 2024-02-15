/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:06:10 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/15 19:57:49 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>

//# include "libft/libft.h"

//# include "ft_lis.h"
# include "stacks.h"

# ifdef TEST
#  include "ft_printf/ft_printf.h"
# endif

void			ft_swap_a(void);
void			ft_swap_b(void);
void			ft_shovel_swap(void);
void			ft_push_to_a(struct s_stacks *stacks);
void			ft_push_to_b(struct s_stacks *stacks);
void			ft_raise_a(const struct s_stacks *stacks);
void			ft_raise_b(void);
void			ft_rake_raise(void);
void			ft_refurb_a(struct s_stacks *stacks);
void			ft_refurb_b(struct s_stacks *stacks);
void			ft_rake_refurb(struct s_stacks *stacks);

//void		gnome_sort(int *destination, int *source) __attribute__ ((nonnull));

# ifndef __clang__
#  ifdef TEST

//typedef struct __attribute__ ((designated_init)) __attribute__ ((deprecated))
//{
//	enum e_result_type	type;
//	union
//	{
//		enum e_atoi_error	error;
//	};
//}	t_parse_result;
#   define PUSH_SWAP_H_ATTRIBUTES
#  endif
# endif
# ifndef PUSH_SWAP_H_ATTRIBUTES

//typedef struct
//{
//	enum e_result_type	type;
//	union
//	{
//		enum e_atoi_error	error;
//	};
//}	t_parse_result;
# endif
#endif
