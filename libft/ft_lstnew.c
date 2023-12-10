/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:45:04 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/16 18:49:40 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Allocates (with malloc(3)) and returns a new node.
 * 	 The field `content` is initialized with the value of the
 * 	parameter `content`. The field `next` is initialized to `NULL`.
 *
 * @param content The content to create the node with.
 * @return The new node.
 * @remark External function: `malloc`.
 */
t_list	*ft_lstnew(void *content)
{
	struct s_list	*node;

	node = ft_calloc(1, sizeof * node);
	if (! node)
		return (NULL);
	node->content = content;
	return (node);
}
