/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:51:22 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/20 16:22:50 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "bonus.h"

#ifdef TEST
# include "libft.h"
#endif

__attribute__ ((warn_unused_result))
t_int_list	ft_lstclone_int(t_int_list list)
{
	t_int_node	*node;
	t_int_list	clone;

	node = list;
	clone = NULL;
	while (node != NULL)
	{
		ft_lstadd_back_int(&clone, ft_lstnew_int(node->datum));
		node = node->next;
	}
	return (clone);
}
