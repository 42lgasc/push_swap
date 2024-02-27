/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:29:08 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 11:13:19 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include "stacks.h"

#ifdef TEST
# include "ft_printf/ft_printf_conversion.h"
#endif

__attribute__ ((nonnull))
void	ft_swap_a(struct s_stacks *const stacks)
{
	ft_putendl_fd("sa", 1);
	ft_ilstswap(&stacks->primary, &stacks->primary->next);
}

void	ft_push_to_a(struct s_stacks *const stacks)
{
	t_inode *const	node = stacks->secondary;

	ft_putstr_fd("pa\n", 1);
	stacks->secondary = node->next;
	node->next = stacks->primary;
	stacks->primary = node;
}

void	ft_push_to_b(struct s_stacks *const stacks)
{
	t_inode *const	node = stacks->primary;

	ft_putstr_fd("pb\n", 1);
	stacks->primary = node->next;
	node->next = stacks->secondary;
	stacks->secondary = node;
}
