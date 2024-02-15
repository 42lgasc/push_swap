/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:45:04 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/13 15:21:39 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Allocate (with `malloc``(3)`) and return a new node.
///The `datum` field is initialized with the value of the
///	`datum` parameter. The field `next` is initialized to `NULL`.
///@param datum The datum to create the node with
///@return A new node
///@remark External function: `malloc`
t_node	*ft_lstnew(void *const datum)
{
	t_node *const	node = malloc(sizeof * node);

	if (node == NULL)
		return (NULL);
	node->datum = datum;
	node->next = NULL;
	return (node);
}

t_int_node	*ft_lstnew_int(const int datum)
{
	t_int_node *const	node = malloc(sizeof * node);

	if (node == NULL)
		return (NULL);
	node->datum = datum;
	node->next = NULL;
	return (node);
}
