/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@students.42perpignan.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:58:04 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/26 18:36:03 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lis.h"

///Longuest Increasing Subsequence
		//= malloc(super_length * sizeof * end_predecessors);
		//|| end_predecessors == NULL)
t_int_array	ft_lis(
	const int super[const], const size_t super_length)
{
	//size_t *const			predecessions.ranks = (ft_printf("super_length: "),
	//		ft_printf("%u * sizeof * predecessions.ranks: ", super_length),
	//		ft_printf("%u: ", sizeof * predecessions.ranks),
	//		ft_printf("%u\n", super_length * sizeof * predecessions.ranks),
	//		malloc(super_length * sizeof * predecessions.ranks));
	struct s_predecessions	predecessions
		= (struct s_predecessions)
		{.amount = super_length,
		.ranks = malloc(predecessions.amount * sizeof * predecessions.ranks),
		.predecessors
		= malloc(predecessions.amount * sizeof * predecessions.predecessors)};
	size_t					i;
	t_int_array				lis;

	if (predecessions.ranks == NULL || predecessions.predecessors == NULL)
		return (
			free(predecessions.ranks), free(predecessions.predecessors), NULL);
	//i = 0;
	//while (i < super_length * sizeof * predecessions.ranks)
	//	ft_printf("(unsigned char*)predecessions.ranks: "),
	//	ft_printf("%p: ", predecessions.ranks),
	//	ft_printf("%p + i: ", (unsigned char*)predecessions.ranks), ft_printf
	//	("%u: ", i), ft_printf("%p\n", (unsigned char*)predecessions.ranks + i++);
	i = 0;
	while (i < super_length)
		//j = 0;
		//while (j < super_length * sizeof * predecessions.ranks)
		//	ft_printf("(unsigned char*)predecessions.ranks: "),
		//		ft_printf("%p: ", predecessions.ranks), ft_printf
		//		("%p + j: ", (unsigned char*)predecessions.ranks), ft_printf("%u: ", j),
		//		ft_printf("%p\n", (unsigned char*)predecessions.ranks + j++);
		//ft_printf("predecessions.ranks: "), ft_printf("%p[i: ", predecessions.ranks),
		//	ft_printf("%u]: ", i), ft_printf("%p = 0;\n", predecessions.ranks + i),
			predecessions.ranks[i++] = 0;
		//ft_printf("*(predecessions.ranks: "), 
		//	ft_printf("%p + i: ", predecessions.ranks), ft_printf("%u): ", i), ft_printf
		//	("%p: ", predecessions.ranks + i), ft_printf("%u\n", *(predecessions.ranks + i));
		//ft_printf("predecessions->array[i: "),
		//	ft_printf("%u].is_first = IsFirst: ", i), ft_printf
		//	("%u; ", IsFirst), predecessions->array[i].is_first = IsFirst;
		//ft_printf("%u\n", predecessions.array[i].is_first);
	ft_loop(super, super_length, predecessions);
	//i = 0, ft_printf("predecessions{.length: %u, .predecessions: {\n",
	//		predecessions.length);
	//while (i < predecessions.length)
	//{
	//	ft_printf
	//		("\t{.is_first: %u, ", predecessions.predecessions[i].is_first);
	//	if (predecessions.predecessions[i].is_first)
	//		ft_printf("\x1B[2m.predecessors\x1B[22m},\n");
	//	else
	//		ft_printf(".predecessors: %u},\n",
	//				predecessions.predecessions[i].predecessors);
	//	++i;
	//}
	//ft_printf("}\n");
	lis = ft_hydrate_lis(super, super_length, predecessions);
	return (free(predecessions.ranks), free(predecessions.predecessors), lis);
}

static void	ft_loop(const int super[const], const size_t super_length,
	struct s_predecessions predecessions)
{
	size_t	i;
	size_t	j;

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
}

	//if (lis == NULL)
	//	return ((struct s_int_array){.length = 0});
static t_int_array	ft_hydrate_lis(const int super[const],
	const size_t super_length, const struct s_predecessions predecessions)
{
	struct s_max_result	greatest_end;
	t_int_array			lis; //= (ft_printf("sizeof * lis: "),
		//	ft_printf("%u + super_length: ", sizeof lis), ft_printf("%u * sizeo"
		//		"f * lis->ints: ", super_length), ft_printf("%u: ", sizeof * lis
		//		->ints), ft_printf("%u: ", super_length * sizeof * lis->ints),
		//	ft_printf("%u\n", sizeof lis + super_length * sizeof * lis->ints),
		//malloc(sizeof * lis + greatest_end.ok * sizeof * lis->ints);
	size_t				i;

	greatest_end = ft_try_zmaxo(predecessions.ranks, super_length);
	if (greatest_end.type == Error)
		return ((void)(0x70D0 * greatest_end.error), NULL);
	//ft_printf("predecessions.ranks[greatest_end.ok: %u]: %u\n",
	//	greatest_end.ok, predecessions.ranks[greatest_end.ok]);
	lis = malloc(sizeof * lis
			+ (1 + predecessions.ranks[greatest_end.ok]) * sizeof * lis->ints);
	if (lis == NULL)
		return (NULL);
	i = predecessions.ranks[greatest_end.ok];
	lis->length = i + 1;
	//ft_printf("while (! predecessions.predecessions[greatest_end.ok: "),
	//ft_printf("%i].is_first: ", greatest_end.ok),
	//ft_printf("%i: ", predecessions.predecessions[greatest_end.ok].is_first),
	//ft_printf("%i)\n", ! predecessions.predecessions[greatest_end.ok].is_first);
	while (predecessions.ranks[greatest_end.ok] != 0)
	{
		//ft_printf("lis->ints: "),
		//	ft_printf("%i[i: ", lis->ints), ft_printf("%u]: ", i),
		//	ft_printf("%p = super[greatest_end.ok: ", &lis->ints[i]),
		//	ft_printf("%i]: ", greatest_end.ok),
		//	ft_printf("%i;\n", super[greatest_end.ok]);
		lis->ints[i--] = super[greatest_end.ok];
		//ft_printf("%i = predecessions.predecessions[greatest_end.ok: ", greatest_end
		//	.ok), ft_printf("%i].predecessors: ", greatest_end.ok), ft_printf
		//	("%i;\n", predecessions.predecessions[greatest_end.ok].predecessors);
		greatest_end.ok
			= predecessions.predecessors[greatest_end.ok];
	}
	lis->ints[i] = super[greatest_end.ok];
	return (lis);
}
