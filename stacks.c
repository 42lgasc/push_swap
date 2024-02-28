/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:25:10 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/28 18:31:58 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/libft.h"
#include "libft/types.h"
#include "libft/bonus.h"

//#include "stacks.h"
#include "push_swap_types.h"

#ifndef TEST
# include "ft_printf/ft_printf.h"

void	ft_print_stacks(const struct s_stacks stacks)
{
	const t_inode	*node;

	ft_putstr_fd("stacks: { primary: [", 2);
	node = stacks.primary;
	while (node != NULL)
	{
		ft_putnbr_fd(node->datum, 2);
		if (node->next != NULL)
			ft_putstr_fd(", ", 2);
		node = node->next;
	}
	ft_putstr_fd("], secondary: [", 2);
	node = stacks.secondary;
	while (node != NULL)
	{
		ft_putnbr_fd(node->datum, 2);
		if (node->next != NULL)
			ft_putstr_fd(", ", 2);
		node = node->next;
	}
	ft_putendl_fd("] }", 2);
}
#else

void	ft_print_stacks(const struct s_stacks stacks)
{
	(void) stacks;
}
#endif

/*t_int_option	ft_primary_top(const struct s_stacks stacks)
{
	if (stacks.primary == NULL)
		return ((t_int_option){.type = None});
	return ((t_int_option){.type = Some, .value = stacks.primary->datum});
}

//\*t_int_option	ft_primary_next(const struct s_stacks stacks)
{
	size_t	i;

	i = 0;
	while (i < stacks.size)
		if (stacks.masks[(stacks.primary_top + i++) % stacks.size] & Primary)
			while (1)
				if (stacks.masks
					[(stacks.primary_top + i++) % stacks.size] & Primary)
					return ((struct s_int_option){.type = Some, .value = stacks
						.primary[(stacks.primary_top + --i) % stacks.size]});
	return ((struct s_int_option){.type = None});
	(void) stacks;
	exit(TODO + 3);
}*\/

t_int_option	ft_primary_bottom(const struct s_stacks stacks)
{
	if (stacks.primary == NULL)
		return ((t_int_option){.type = None});
	return ((t_int_option)
		{.type = Some, .value = ft_ilstlast(stacks.primary)->datum});
}

t_int_option	ft_secondary_top(const struct s_stacks stacks)
{
	if (stacks.secondary == NULL)
		return ((t_int_option){.type = None});
	return ((t_int_option){.type = Some, .value = stacks.secondary->datum});
}

t_int_option	ft_secondary_bottom(const struct s_stacks stacks)
{
	if (ft_ilstplast(stacks.secondary) == NULL)
		return ((t_int_option){.type = None});
	return ((t_int_option)
		{.type = Some, .value = ft_ilstplast(stacks.secondary)->datum});
}*/
