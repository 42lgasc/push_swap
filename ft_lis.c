/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@students.42perpignan.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:58:04 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/30 18:35:07 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lis.h"

///Longuest Increasing Subsequence
		//= malloc(super_length * sizeof * end_predecessors);
		//|| end_predecessors == NULL)
t_int_array	ft_lis(
	const int super[const], const size_t super_length)
{
	struct s_predecessions	predecessions;
	size_t					i;
	t_int_array				lis;

	if (super == NULL)
		return (NULL);
	predecessions.amount = super_length;
	predecessions.ranks
		= malloc(predecessions.amount * sizeof * predecessions.ranks);
	predecessions.predecessors
		= malloc(predecessions.amount * sizeof * predecessions.predecessors);
	if (predecessions.ranks == NULL || predecessions.predecessors == NULL)
		return (
			free(predecessions.ranks), free(predecessions.predecessors), NULL);
	i = 0;
	while (i < super_length)
		predecessions.ranks[i++] = 0;
	if (ft_loop(super, super_length, predecessions) != 0)
		return (
			free(predecessions.ranks), free(predecessions.predecessors), NULL);
	lis = ft_hydrate_lis(super, super_length, predecessions);
	return (free(predecessions.ranks), free(predecessions.predecessors), lis);
}

static unsigned char	ft_loop(const int super[const],
	const size_t super_length, struct s_predecessions predecessions)
{
	size_t	i;
	size_t	j;

	if (super == NULL)
		return (1);
	i = 0;
	while (i < super_length)
	{
		j = 0;
		while (j < i)
		{
			if (super[j] < super[i]
				&& predecessions.ranks[j] >= predecessions.ranks[i])
			{
				predecessions.ranks[i] = predecessions.ranks[j] + 1;
				predecessions.predecessors[i] = j;
			}
			++j;
		}
		++i;
	}
	return (0);
}

	//	return ((struct s_int_array){.length = 0});
static t_int_array	ft_hydrate_lis(const int super[const],
	const size_t super_length, const struct s_predecessions predecessions)
{
	struct s_max_result	greatest_end;
	t_int_array			lis;
	size_t				i;

	if (super == NULL)
		return (NULL);
	greatest_end = ft_try_zmaxo(predecessions.ranks, super_length);
	if (greatest_end.type == Error)
		return ((void)(0x70D0 * greatest_end.error), NULL);
	lis = malloc(sizeof * lis
			+ (1 + predecessions.ranks[greatest_end.ok]) * sizeof * lis->ints);
	if (lis == NULL)
		return (NULL);
	i = predecessions.ranks[greatest_end.ok];
	lis->length = i + 1;
	while (predecessions.ranks[greatest_end.ok] != 0)
	{
		lis->ints[i--] = super[greatest_end.ok];
		greatest_end.ok
			= predecessions.predecessors[greatest_end.ok];
	}
	lis->ints[i] = super[greatest_end.ok];
	return (lis);
}
