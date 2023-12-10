/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:52:21 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/16 19:00:06 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Counts the number of nodes in a list.
 * @param list The beginning of the list.
 * @return Last node of the list.
 */
t_list	*ft_lstlast(t_list *list)
{
	struct s_list	*link;

	if (! list)
		return (NULL);
	link = list;
	while (link->next)
		link = link->next;
	return (link);
}
