/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@students.42perpignan.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:58:04 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/15 13:57:11 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lis.h"

#ifdef TEST
# include "ft_printf/ft_printf.h"
#endif

static
void		ft_loop(t_khipu *khipu, t_int_list int_list)
			__attribute__ ((nonnull));
static
t_int_array	ft_hydrate_lis(t_int_list int_list, t_khipu khipu)
			__attribute__ ((warn_unused_result)) __attribute__ ((nonnull));
#ifdef TEST

static void	ft_print_khipu(const t_khipu khipu) __attribute__ ((unused));
#endif

///Longuest Increasing Subsequence
		//= malloc(super_length * sizeof * end_predecessors);
		//|| end_predecessors == NULL)
t_int_array	ft_lis(const t_int_list int_list)
{
	t_khipu		khipu;
	size_t		i;
	t_int_array	lis;

	if (int_list == NULL)
		return (NULL);
	//ft_print_int_list(int_list);
	khipu.amount //= super_length
	= ft_lstsize_int(int_list);
	khipu.ranks
		= malloc(khipu.amount * sizeof * khipu.ranks);
	khipu.knots
		= malloc(khipu.amount * sizeof * khipu.knots);
	if (khipu.ranks == NULL || khipu.knots == NULL)
		return (
			free(khipu.ranks), free(khipu.knots), NULL);
	i = 0;
	while (i < //super_length
		khipu.amount)
		khipu.ranks[i++] = 0;
	ft_loop(&khipu, int_list);
	//ft_print_khipu(khipu);
	lis = ft_hydrate_lis(int_list, khipu);
	return (free(khipu.ranks), free(khipu.knots), lis);
}

///TODO
t_int_array	ft_lis_circular(const t_int_list list)
{
	return (ft_lis(list));
}

static void	ft_loop(t_khipu *const khipu, const t_int_list int_list)
{
	size_t		i;
	size_t		j;
	t_int_node	*p;
	t_int_node	*q;

	i = 0;
	p = int_list;
	while (i //< super_length
		< khipu->amount
		&& p != NULL)
	{
		j = 0;
		q = int_list;
		while (j < i && q != p)
		{
			if (//super[j] < super[i]
				q->datum < p->datum
				&& khipu->ranks[j] >= khipu->ranks[i])
			{
				khipu->ranks[i] = khipu->ranks[j] + 1;
				khipu->knots[i] = j;
			}
			++j, q = q->next;
		}
		++i, p = p->next;
	}
	return ;
}

///TODO: Better error returns
	//	return ((struct s_int_array){.length = 0});
static t_int_array	ft_hydrate_lis(
	const t_int_list int_list, const t_khipu khipu)
{
	t_max_result	high_tip;
	t_int_array		lis;
	size_t			i;

	high_tip = ft_try_zmaxo(khipu.ranks, //super_length
		khipu.amount);
	if (high_tip.code != Max_Ok)
		return ((void)(TODO * high_tip.code), NULL);
	lis = malloc(sizeof * lis
			+ (1 + khipu.ranks[high_tip.ok]) * sizeof * lis->ints);
	if (lis == NULL)
		return (NULL);
	i = khipu.ranks[high_tip.ok];
	lis->length = i + 1;
	while (khipu.ranks[high_tip.ok] != 0)
	{
		//ft_printf("lis->ints + i: %p, ", (void *)(lis->ints + i));
		//ft_printf(
		//	"ft_lstget_int(int_list, high_tip.ok: %u)", (unsigned)high_tip.ok);
		//ft_printf(": %p", (void *)ft_lstget_int(int_list, high_tip.ok));
		//ft_printf("->datum: %i\n",ft_lstget_int(int_list,high_tip.ok)->datum);
		lis->ints[i--] //= super[high_tip.ok]
		= ft_lstget_int(int_list, high_tip.ok)->datum;
		high_tip.ok
			= khipu.knots[high_tip.ok];
	}
	lis->ints[i] //= super[high_tip.ok]
	= ft_lstget_int(int_list, high_tip.ok)->datum;
	return (lis);
}

// TODO: Implement the si`z`e_t length modifier for `ft_printf`.
static void	ft_print_khipu(const t_khipu khipu)
{
	size_t	i;

	ft_printf("khipu: { amount: %u, ranks: [", (unsigned)khipu.amount);
	i = 0;
	while (i < khipu.amount)
		(ft_printf("%u", (unsigned)khipu.ranks[i]),
			ft_print_if(++i < khipu.amount, ", "));
	ft_putstr_fd("], knots: [", 1);
	i = 0;
	while (i < khipu.amount)
		(ft_printf("%u", (unsigned)khipu.knots[i]),
			ft_print_if(++i < khipu.amount, ", "));
	ft_putendl_fd("] }", 1);
}
