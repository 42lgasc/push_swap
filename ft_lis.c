/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@students.42perpignan.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:58:04 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/10 19:23:26 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_lis.h"

///Longuest Increasing Subsequence
const int	*ft_lis(
	const int super[const], const size_t super_length)
{
	size_t *const					end_lengths
		= malloc(super_length * sizeof * end_lengths);
	struct s_end_predecessor *const	end_predecessors
		= malloc(super_length * sizeof * end_predecessors);
	size_t							i;
	const int						*lis;

	if (end_lengths == NULL || end_predecessors == NULL)
		return (free(end_lengths), free(end_predecessors), NULL);
	i = 0;
	while (i < super_length)
	{
		end_lengths[i] = 1;
		end_predecessors[i].e_is_first = IsFirst;
		++i;
	}
	ft_loop(super, super_length, end_lengths, end_predecessors);
	lis = ft_hydrate_lis(super, super_length, end_lengths, end_predecessors);
	return (free(end_lengths), free(end_predecessors), lis);
}

static void	ft_loop(const int super[const], const size_t super_length,
	size_t end_lengths[const], struct s_end_predecessor end_predecessors[const])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < super_length)
	{
		j = 0;
		while (j < i)
		{
			if (super[j] < super[i] && end_lengths[j] >= end_lengths[i])
			{
				end_lengths[i] = end_lengths[j] + 1;
				end_predecessors[i] = (struct s_end_predecessor)
				{.e_is_first = HasPredecessor, .offset = j};
			}
			++j;
		}
		++i;
	}
}

static const int	*ft_hydrate_lis(const int super[const],
	const size_t super_length, const size_t end_lengths[const],
	const struct s_end_predecessor end_predecessors[const])
{
	struct s_max_result		greatest_end;
	int *const				lis = malloc(super_length * sizeof * lis);
	size_t					i;

	if (lis == NULL)
		return (NULL);
	greatest_end = ft_try_zmaxo(end_lengths, super_length);
	if (greatest_end.type == Error)
		return ((void)(0x70D0 * greatest_end.error), NULL);
	i = super_length;
	while (! end_predecessors[greatest_end.ok].e_is_first)
	{
		lis[--i] = super[greatest_end.ok];
		greatest_end.ok = end_predecessors[greatest_end.ok].offset;
	}
	lis[--i] = super[greatest_end.ok];
	return (lis);
}
