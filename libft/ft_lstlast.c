/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:52:21 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 11:17:28 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///@return A pointer to the last node of a list, if any

///@param list The beginning of the list.
t_node	*ft_lstlast(const t_list list)
{
	t_node	*node;

	if (list == NULL)
		return (NULL);
	node = list;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

t_ilist	ft_ilstlast(const t_ilist list)
{
	t_inode	*node;

	if (list == NULL)
		return (NULL);
	node = list;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

t_zlist	ft_zlstlast(const t_zlist list)
{
	t_znode	*node;

	if (list == NULL)
		return (NULL);
	node = list;
	while (node->next != NULL)
		node = node->next;
	return (node);
}
