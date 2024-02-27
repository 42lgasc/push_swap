/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:19:40 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 11:28:58 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "bonus.h"

#ifdef TEST
# include "libft.h"
#endif

///Get the node at the given `offset` in the `list`, if it exists
///XXX: You should not need to call this function;
///	you might be using lunk lists wrong!
t_node	*ft_lstget(const t_list list, const size_t offset)
{
	size_t	i;
	t_node	*node;

	node = list;
	i = 0;
	while (i < offset && node != NULL)
		node = node->next;
	return (node);
}

t_inode	*ft_ilstget(const t_ilist list, const size_t offset)
{
	size_t	i;
	t_inode	*node;

	node = list;
	i = 0;
	while (i < offset && node != NULL)
	{
		node = node->next;
		++i;
	}
	return (node);
}

t_znode	*ft_zlstget(const t_zlist list, const size_t offset)
{
	size_t	i;
	t_znode	*node;

	node = list;
	i = 0;
	while (i < offset && node != NULL)
	{
		node = node->next;
		++i;
	}
	return (node);
}
