/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstplast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:35:34 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/09 21:04:38 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "bonus.h"

///@returns A pointer to the previous-to-last node,
///	only if the `list` has more than one element.
t_node	*ft_lstplast(const t_list list)
{
	t_node	*node;

	node = list;
	if (node == NULL || node->next == NULL)
		return (NULL);
	while (node->next->next != NULL)
		node = node->next;
	return (node);
}

t_int_node	*ft_lstplast_int(const t_int_list list)
{
	t_int_node	*node;

	node = list;
	if (node->next == NULL)
		return (NULL);
	while (node->next->next != NULL)
		node = node->next;
	return (node);
}
