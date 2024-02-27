/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:51:22 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 11:28:00 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "bonus.h"

#ifdef TEST
# include "libft.h"
#endif

__attribute__ ((warn_unused_result))
t_ilist	ft_ilstclone(t_ilist list)
{
	t_inode	*node;
	t_ilist	clone;

	node = list;
	clone = NULL;
	while (node != NULL)
	{
		ft_ilstadd_back(&clone, ft_ilstnew(node->datum));
		node = node->next;
	}
	return (clone);
}
