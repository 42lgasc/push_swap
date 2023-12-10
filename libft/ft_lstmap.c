/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:59:30 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/21 19:07:05 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*new_list_skeleton(const size_t size);
static void		hydrate_list(
					const t_list *const source,
					void *(*const mapper)(void *),
					t_list *const destination);

/** Iterates the `original` list and applies the `function` on the content of
 * 	each node, and creates a new `map` list resulting of the successive
 * 	applications of the `mapper` function.
 * The `deleter` function is used to delete the content of a node if needed.
 * 
 * @param original The address of a pointer to a node.
 * @param mapper The address of a function used to
 * 	iterate on the `original` list.
 * @param deleter The address of a function used to
 * 	delete the `content` of a node if needed.
 * 
 * @return The new `map` list. `NULL` if the allocation fails.
 * 
 * @remark External functions: `malloc`, `free`.
 * @remark This function assumes that `NULL` being returned by the `mapper`
 * 	function is just a normal (valid) value, and not some kind of error code.
 * 
 * deleter?
 * I barely know her!
 * DEL-EAT DEEZ 
 */
t_list	*ft_lstmap(
	t_list *original, void *(*mapper)(void *), void (*deleter)(void *))
{
	t_list	*map;

	if ((! original) || (! mapper) || (! deleter))
		return (NULL);
	map = new_list_skeleton(ft_lstsize(original));
	if (! map)
		return (NULL);
	hydrate_list(original, mapper, map);
	return (map);
}

static void		noop(void *x);

static t_list	*new_list_skeleton(const size_t size)
{
	unsigned int	i;
	t_list			*skeleton;
	struct s_list	*node;

	i = 0;
	skeleton = NULL;
	while (i < size)
	{
		node = ft_lstnew(NULL);
		if (node)
			ft_lstadd_back(&skeleton, node);
		else
		{
			ft_lstclear(&skeleton, noop);
			return (NULL);
		}
		i++;
	}
	return (skeleton);
}

static void	noop(void *x)
{
	if (x)
		return ;
	return ;
}

static void	hydrate_list(
				const t_list *const source,
				void *(*const mapper)(void *),
				t_list *const destination)
{
	struct s_list		*destination_link;
	const struct s_list	*source_link;

	if ((! source) || (! mapper) || (! destination))
		return ;
	destination_link = destination;
	source_link = source;
	while (destination_link)
	{
		destination_link->content = mapper(source_link->content);
		destination_link = destination_link->next;
		source_link = source_link->next;
	}
}
