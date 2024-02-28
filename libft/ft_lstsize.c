/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:28:09 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 21:29:19 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Count the number of nodes in a list

///@param list The beginning of the list.

///@return The length of the list.
__attribute__ ((warn_unused_result))
size_t	ft_lstsize(const t_list list)
{
	t_node	*node;
	size_t	size;

	node = list;
	size = 0;
	while (node != NULL)
	{
		size++;
		node = node->next;
	}
	return (size);
}

__attribute__ ((warn_unused_result))
size_t	ft_ilstsize(const t_ilist list)
{
	size_t	size;
	t_inode	*node;

	node = list;
	size = 0;
	while (node != NULL)
		node = (++size, node->next);
	return (size);
}

__attribute__ ((warn_unused_result))
size_t	ft_zlstsize(const t_zlist list)
{
	size_t	size;
	t_znode	*node;

	node = list;
	size = 0;
	while (node != NULL)
		node = (++size, node->next);
	return (size);
}
