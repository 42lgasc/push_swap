/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:59:30 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/09 18:51:38 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	map_skeleton(const size_t size);
static void		hydrate_map(const t_list map, const t_list source,
					void *(*const mapper)(const void *const datum));

///Iterate the `list` and call the `mapper` on the `datum` of each node,
/// and create a new list from the results of the calls to the `mapper`.
///The `deleter` function is used to delete the datum of a node if needed.

///@param list The head pointer of the original list
///@param mapper The address of a function used to map
///@param deleter The address of a function which can free a `node.datum`

///@return A new list, or `NULL` if the allocation fails.

///@remark External functions: `malloc`, `free`.
///@remark This function assumes that `NULL` being returned by the `mapper`
///	function is just a normal (valid) value, and not some kind of error code.

///`deleter`?
///I barely know her!
///DEL-EAT DEEZ
t_list	ft_lstmap(const t_list list, void *(*mapper)(const void *const datum),
	void (*const deleter)(const void *const datum))
{
	const t_list	map = map_skeleton(ft_lstsize(list));

	(void) deleter;
	if (map == NULL)
		return (NULL);
	hydrate_map(map, list, mapper);
	return (map);
}

static void		noop(const void *const x);

static t_list	map_skeleton(const size_t size)
{
	size_t	i;
	t_list	skeleton;
	t_node	*node;

	i = 0;
	skeleton = NULL;
	while (i++ < size)
	{
		node = ft_lstnew(NULL);
		if (node)
			ft_lstadd_back(&skeleton, node);
		else
		{
			ft_lstclear(&skeleton, noop);
			return (NULL);
		}
	}
	return (skeleton);
}

static void	noop(const void *const x)
{
	if (x)
		return ;
	return ;
}

static void	hydrate_map(const t_list map, const t_list source,
	void *(*const mapper)(const void *const datum))
{
	t_node			*map_node;
	const t_node	*source_node;

	if ((! source) || (! mapper) || (! map))
		return ;
	map_node = map;
	source_node = source;
	while (map_node != NULL)
	{
		map_node->datum = mapper(source_node->datum);
		map_node = map_node->next;
		source_node = source_node->next;
	}
}
