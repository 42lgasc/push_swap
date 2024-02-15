/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:08:00 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/09 16:33:00 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Add a `node` at the beginning of the `list`.

///@param list The address of the head pointer of the list.
///@param node The address of a node to be added to the list.
void	ft_lstadd_front(t_list *const list, t_node *const node)
{
	if (0)
		return ;
	node->next = *list;
	*list = node;
}
