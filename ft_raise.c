/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:29:37 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/22 20:41:08 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include "stacks.h"

__attribute__ ((nonnull))
void	ft_raise_a(struct s_stacks *const stacks)
{
	ft_putendl_fd("ra", 1);
	ft_lstrot_int(&stacks->primary);
}

__attribute__ ((nonnull))
void	ft_raise_b(struct s_stacks *const stacks)
{
	ft_putendl_fd("rb", 1);
	ft_lstrot_int(&stacks->secondary);
}

__attribute__ ((nonnull))
void	ft_rake_raise(struct s_stacks *const stacks)
{
	ft_putendl_fd("rr", 1);
	ft_lstrot_int(&stacks->primary);
	ft_lstrot_int(&stacks->secondary);
}
