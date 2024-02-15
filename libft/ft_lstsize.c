/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:28:09 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/12 15:53:18 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Count the number of nodes in a list

///@param list The beginning of the list.

///@return The length of the list.
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

size_t	ft_lstsize_int(const t_int_list list)
{
	size_t		size;
	t_int_node	*node;

	node = list;
	size = 0;
	while (node != NULL)
		node = (++size, node->next);
	return (size);
}
