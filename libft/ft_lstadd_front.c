/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:08:00 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/21 17:57:33 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Adds the node `new` at the beginning of the list.
 * 
 * @param list The address of a pointer to the first link of the list.
 * @param new The address of a pointer to the node to be added to the list.
 */
void	ft_lstadd_front(t_list **list, t_list *new)
{
	if ((! list) || (! new))
		return ;
	new->next = *list;
	*list = new;
}
