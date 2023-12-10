/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:28:09 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/14 14:41:27 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Counts the number of nodes in a list.
 * @param list The beginning of the list.
 * @return The length of the list.
 */
int	ft_lstsize(t_list *list)
{
	struct s_list	*next_link;
	size_t			size;

	next_link = list;
	size = 0;
	while (next_link)
	{
		size++;
		next_link = next_link->next;
	}
	return (size);
}
