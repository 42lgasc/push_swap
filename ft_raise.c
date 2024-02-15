/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:29:37 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/13 12:03:21 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include "stacks.h"

void	ft_raise_a(struct s_stacks *const stacks)
{
	ft_putstr_fd("ra\n", 1);
	//while (!(stacks->masks[stacks->primary_top] & Primary))
	//{
	//	++stacks->primary_top;
	//	stacks->primary_top %= stacks->size;
	//}
	//++stacks->primary_top;
	//stacks->primary_top %= stacks->size;
	ft_lstrot_int(&stacks->primary);
}
