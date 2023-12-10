/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:28:07 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/17 11:39:25 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Deletes and frees the given node and every successor of that node, using
 * 	the `deleter` function and free(3).
 * 	Finally, the pointer to the `list` must be set to `NULL`.
 * 
 * @param node The address of a pointer to a node
 * 
 * @param deleter The address of the function
 * 	used to delete the content of the `node`
 * 
 * @remark External function: `free`.
 */
void	ft_lstclear(t_list **list, void (*deleter)(void *))
{
	t_list	*link;
	t_list	*next_link;

	if ((! list) || (! deleter))
		return ;
	link = *list;
	while (link)
	{
		deleter(link->content);
		next_link = link->next;
		free(link);
		link = next_link;
	}
	*list = NULL;
}
