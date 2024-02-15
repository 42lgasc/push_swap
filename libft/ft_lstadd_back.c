/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:07:05 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 13:15:27 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Add a `node` at the end of the `list`

///@param list The address of the head pointer of the list
///@param node The address of a node to be added

///@remark The address of the head pointer is assumed to be nonnull.
void	ft_lstadd_back(t_list *const list, t_node *const node)
{
	if (*list == NULL)
		*list = node;
	else
		ft_lstlast(*list)->next = node;
}

void	ft_lstadd_back_int(t_int_list *const list, t_int_node *const node)
{
	if (*list == NULL)
		*list = node;
	else
		ft_lstlast_int(*list)->next = node;
}
