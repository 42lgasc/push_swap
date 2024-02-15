/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:29:08 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/15 15:47:07 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"

# include "stacks.h"

#ifdef TEST
# include "ft_printf/ft_printf_conversion.h"
#endif

void	ft_push_to_a(struct s_stacks *const stacks)
{
	t_int_node *const	node = stacks->secondary;

	ft_putstr_fd("pa\n", 1);
	//while (!(stacks->masks[stacks->secondary_top] & Secondary))
	//	if (++stacks->secondary_top == stacks->size)
	//		stacks->secondary_top = 0;
	//while (stacks->masks[stacks->primary_top] & Primary)
	//	if (stacks->primary_top-- == 0)
	//		stacks->primary_top = stacks->size - 1;
	//stacks->primary[stacks->primary_top]
	//	= stacks->secondary[stacks->secondary_top];
	//stacks->masks[stacks->secondary_top] ^= Secondary;
	//stacks->masks[stacks->primary_top] |= Primary;
	stacks->secondary = node->next;
	node->next = stacks->primary;
	stacks->primary = node;
	ft_print_stacks(*stacks);
	//(void) stacks, exit(TODO + 10);
}

void	ft_push_to_b(struct s_stacks *const stacks)
{
	t_int_node *const	node = stacks->primary;

	ft_putstr_fd("pb\n", 1);
	//while (!(stacks->masks[stacks->primary_top] & Primary))
	//	if (++stacks->primary_top == stacks->size)
	//		stacks->primary_top = 0;
	//while (stacks->masks[stacks->secondary_top] & Secondary)
	//	if (stacks->secondary_top-- == 0)
	//		stacks->secondary_top = stacks->size - 1;
	//stacks->secondary[stacks->secondary_top]
	//	= stacks->primary[stacks->primary_top];
	//stacks->masks[stacks->primary_top] ^= Primary;
	//stacks->masks[stacks->secondary_top] |= Secondary;
	//node->datum += (int)ft_print_pointer(node) << 1 & 1;
	stacks->primary = node->next;
	node->next = stacks->secondary;
	//node->datum += (int)ft_print_pointer(node->next) << 1 & 1;
	stacks->secondary = node;
	//node->datum += (int)ft_print_pointer(stacks->secondary) << 1 & 1;
	ft_print_stacks(*stacks);
	//(void) stacks, exit(TODO + 11);
}
