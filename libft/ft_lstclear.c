/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:28:07 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 11:17:46 by lgasc            ###   ########.fr       */
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

void	ft_ilstclear(t_ilist *const list)
{
	t_inode	*node;
	t_inode	*next_node;

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

__attribute__ ((nonnull))
void	ft_zlstclear(t_zlist *const list)
{
	t_znode	*node;
	t_znode	*next_node;

	node = *list;
	while (node != NULL)
	{
		node->inner = 0xDEADBEEF;
		next_node = node->next;
		free(node);
		node = next_node;
	}
	*list = NULL;
}
