/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:35:49 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/21 17:58:11 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Takes as a parameter a node and frees the memory of the node’s content using
 * 	the `deleter` function given as a parameter and free the node.
 * 	The memory of `next` must not be freed.
 * 
 * @param node The node to free.
 * @param deleter The addres of the function used to delete the `content`.
 * @remark External function: `free`.
 */
void	ft_lstdelone(t_list *node, void (*deleter)(void *))
{
	struct s_list	*next_node;

	if ((! node) || (! deleter))
		return ;
	deleter(node->content);
	next_node = node->next;
	free(node);
	node = next_node;
}
