/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:07:05 by lgasc             #+#    #+#             */
/*   Updated: 2023/06/29 19:09:44 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Adds the `new` node at the end of the `list`.
 * 
 * @param list The address of a pointer to the first link of a list.
 * @param new The address of the node to be added to the `list`.
 */
void	ft_lstadd_back(t_list **list, t_list *new)
{
	if (! list)
		return ;
	if (! *list)
		*list = new;
	else
		ft_lstlast(*list)->next = new;
}
