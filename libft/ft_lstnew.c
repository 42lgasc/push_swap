/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:45:04 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/28 16:39:56 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Allocate (with `malloc``(3)`) and return a new node.
///The `datum` field is initialized with the value of the
///	`datum` parameter. The field `next` is initialized to `NULL`.
///@param datum The datum to create the node with
///@return A new node
///@remark External function: `malloc`
__attribute__ ((warn_unused_result))
t_node	*ft_lstnew(void *const datum)
{
	t_node *const	node = malloc(sizeof * node);

	if (node == NULL)
		return (NULL);
	node->datum = datum;
	node->next = NULL;
	return (node);
}

__attribute__ ((warn_unused_result))
t_inode	*ft_ilstnew(const int datum)
{
	t_inode *const	node = malloc(sizeof * node);

	if (node == NULL)
		return (NULL);
	node->datum = datum;
	node->next = NULL;
	return (node);
}

__attribute__ ((warn_unused_result))
t_znode	*ft_zlstnew(const size_t inner)
{
	t_znode *const	node = malloc(sizeof * node);

	if (node == NULL)
		return (NULL);
	node->inner = inner;
	node->next = NULL;
	return (node);
}
