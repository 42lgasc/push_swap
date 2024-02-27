/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:07:05 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 11:17:20 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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

void	ft_ilstadd_back(t_ilist *const list, t_inode *const node)
{
	if (*list == NULL)
		*list = node;
	else
		ft_ilstlast(*list)->next = node;
}

__attribute__ ((nonnull))
void	ft_zlstadd_back(t_zlist *const list, t_znode *const node)
{
	if (*list == NULL)
		*list = node;
	else
		ft_zlstlast(*list)->next = node;
}
