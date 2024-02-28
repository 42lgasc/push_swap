/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offload.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:10:38 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/28 18:17:15 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/libft.h"

#include "stacks.h"
#include "push_swap.h"
#include "aim.h"
#include "offload.h"

static t_zlist		ft_compute_costs(struct s_stacks stacks);
static void			ft_align_stacks(struct s_stacks *stacks,
						size_t from_offset, size_t goal_offset, enum e_wib wib);
static enum e_wib	ft_wib(struct s_stacks stacks,
						t_zlist costs, size_t from_offset, size_t goal_offset);

__attribute__ ((nonnull)) __attribute__ ((warn_unused_result))
///TODO: Remove call to `ft_lstget`
char	ft_offload(struct s_stacks *const stacks)
{
	t_zlist	costs;
	size_t	from_offset;
	size_t	goal_offset;

	while (ft_ilstsize(stacks->primary) > 3)
	{
		costs = ft_compute_costs(*stacks);
		if (costs == NULL)
			return (1);
		from_offset = ft_minzlst_offset(costs);
		goal_offset = ft_waning_aim(stacks->secondary,
				ft_ilstget(stacks->primary, from_offset)->datum);
		ft_align_stacks(stacks, from_offset, goal_offset,
			ft_wib(*stacks, costs, from_offset, goal_offset));
		ft_zlstclear(&costs);
		ft_push_to_b(stacks);
		ft_print_stacks(*stacks);
	}
	return (0);
}

__attribute__ ((warn_unused_result))
///TODO: Remove call to `ft_lstget`
static t_zlist	ft_compute_costs(const struct s_stacks stacks)
{
	size_t	offset;
	size_t	aim_offset;
	t_zlist	costs;
	t_znode	*node;

	offset = 0;
	costs = NULL;
	while (offset < ft_ilstsize(stacks.primary))
	{
		aim_offset = ft_waning_aim(stacks.secondary,
				ft_ilstget(stacks.primary, offset)->datum);
		node = ft_zlstnew(ft_zmin(ft_zmin(ft_zmin(
							ft_zmax(offset, aim_offset), ft_ilstsize
							(stacks.secondary) - aim_offset + offset),
						ft_ilstsize(stacks.primary) - offset + aim_offset),
					ft_zmax(ft_ilstsize(stacks.primary) - offset,
						ft_ilstsize(stacks.secondary) - aim_offset)));
		if (node == NULL)
			return (ft_zlstclear(&costs), NULL);
		ft_zlstadd_back(&costs, node);
		++offset;
	}
	return (costs);
}

__attribute__ ((nonnull))
static void	ft_align_stacks(struct s_stacks *const stacks,
	const size_t from_offset, const size_t goal_offset, const enum e_wib wib)
{
	size_t			i;
	const size_t	rdstf = ft_ilstsize(stacks->primary) - from_offset;
	const size_t	rdstg = ft_ilstsize(stacks->secondary) - goal_offset;

	i = 0;
	if (wib == Rr)
		while (i < ft_zmin(from_offset, goal_offset))
			(ft_rake_raise(stacks), ++i);
	if ((wib == Rr && from_offset > goal_offset) || wib == RaAndRrb)
		while (i < from_offset)
			(ft_raise_a(stacks), ++i);
	if ((wib == Rr && from_offset <= goal_offset) || wib == RraAndRb)
		while (i < goal_offset)
			(ft_raise_b(stacks), ++i);
	i = 0;
	if (wib == Rrr)
		while (i < ft_zmin(rdstf, rdstg))
			(ft_rake_refurb(stacks), ++i);
	if ((wib == Rrr && rdstf > rdstg) || wib == RraAndRb)
		while (i < rdstf)
			(ft_refurb_a(stacks), ++i);
	if (wib == RaAndRrb || (wib == Rrr && rdstf <= rdstg))
		while (i < rdstg)
			(ft_refurb_b(stacks), ++i);
}

///TODO: Remove call to `ft_lstget`
static enum e_wib	ft_wib(const struct s_stacks stacks,
	const t_zlist costs, const size_t from_offset, const size_t goal_offset)
{
	if (ft_zlstget(costs, from_offset)->inner
		== ft_zmax(from_offset, goal_offset))
		return (Rr);
	if (ft_zlstget(costs, from_offset)->inner
		== ft_ilstsize(stacks.secondary) - goal_offset + from_offset)
		return (RaAndRrb);
	if (ft_zlstget(costs, from_offset)->inner
		== ft_ilstsize(stacks.primary) - from_offset + goal_offset)
		return (RraAndRb);
	return (Rrr);
}
