/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:44:41 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/15 14:02:31 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Iterates the `list` and applies the `function` on the content of each node.
 * @param list The address to a pointer to a node.
 * @param function The address of the function used to iterate on the `list`.
 */
void	ft_lstiter(t_list *list, void (*function)(void *))
{
	struct s_list	*node;

	if (! function)
		return ;
	node = list;
	while (node)
	{
		function(node->content);
		node = node->next;
	}
}
