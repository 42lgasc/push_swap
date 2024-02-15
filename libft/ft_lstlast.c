/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:52:21 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 13:15:12 by lgasc            ###   ########.fr       */
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

t_int_list	ft_lstlast_int(const t_int_list list)
{
	t_int_node	*node;

	if (list == NULL)
		return (NULL);
	node = list;
	while (node->next != NULL)
		node = node->next;
	return (node);
}
