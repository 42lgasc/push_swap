/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:44:41 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/09 21:06:12 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Iterate the `list` and applie the `action` on the `datum` of each node.
///@param list The head pointer of the list
///@param action The address of the function
void	ft_lstiter(t_list list, void (*action)(const void *const datum))
{
	t_node	*node;

	node = list;
	while (node != NULL)
		(action(node->datum), node = node->next);
}
