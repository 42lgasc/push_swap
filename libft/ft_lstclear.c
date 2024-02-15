/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:28:07 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/13 10:19:03 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///> Delete and free the given node and every successor of
///>  that node, using the `deleter` function and `free``(3)`.
///> Finally, the head pointer of the `list` must be set to `NULL`.
///@param list The address of the head pointer of the list
///@param deleter The address of a function which frees the `node.datum`
///@remark External function: `free`
void	ft_lstclear(t_list *const list, void deleter(const void *const))
{
	t_node	*node;
	t_node	*next_node;

	node = *list;
	while (node != NULL)
	{
		deleter(node->datum);
		next_node = node->next;
		free(node);
		node = next_node;
	}
	*list = NULL;
}

void	ft_lstclear_int(t_int_list *const list)
{
	t_int_node	*node;
	t_int_node	*next_node;

	node = *list;
	while (node != NULL)
	{
		node->datum = 0xDEADBEEF;
		next_node = node->next;
		free(node);
		node = next_node;
	}
	*list = NULL;
}
