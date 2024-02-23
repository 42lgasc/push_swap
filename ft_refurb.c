/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refurb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:29:49 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/16 18:10:17 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

__attribute__ ((nonnull))
void	ft_refurb_a(struct s_stacks *const stacks)
{
	ft_putendl_fd("rra", 1);
	ft_lstrrot_int(&stacks->primary);
}

__attribute__ ((nonnull))
void	ft_refurb_b(struct s_stacks *const stacks)
{
	ft_putendl_fd("rrb", 1);
	ft_lstrrot_int(&stacks->secondary);
}

__attribute__ ((nonnull))
void	ft_rake_refurb(struct s_stacks *const stacks)
{
	ft_putstr_fd("rrr\n", 1);
	(ft_lstrrot_int(&stacks->primary), ft_lstrrot_int(&stacks->secondary));
}
