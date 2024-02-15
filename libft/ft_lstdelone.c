/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:35:49 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/12 15:58:04 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///> Take as a parameter a `node` and free the memory of the `node.datum`
///> using the `deleter` function given as a parameter and free the `node`.
///> The memory of `next` must not be freed.

///# Nah. I won't.

///@param node The address of a pointer to the node to free
///@param deleter The addres of the function used to delete the `node.datum`

///@remark External function: `free`.
void	ft_lstdelone(
	t_node **const node, void (*const deleter)(const void *const))
{
	t_node *const	next_node = (**node).next;

	deleter((**node).datum);
	free(*node);
	*node = next_node;
}
