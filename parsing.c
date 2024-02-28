/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:03:46 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/28 17:38:05 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include "ft_lis.h"

static t_int_option	ft_parse_into(t_ilist *destination,
						const char *const strings[], size_t amount);
static char			ft_has_duplicates(t_ilist list);

__attribute__ ((nonnull)) __attribute__ ((warn_unused_result))
int	ft_check_input(t_ilist *const stack, t_int_array *const lis,
	const int argc, const char *const argv[const])
{
	t_int_option		code;
	const char *const	atoi_error[] = {[Atoi_Ok] = "OK",
	[NullString] = "NULL STRING", [NonNumeric]
		= "NON-NUMERIC STRING", [BeyondLimits] = "INTEGER BEYOND LIMITS"};

	if (argc <= 1)
		return (ft_putendl_fd("Missing arguments "
				"(try the following: `./push_swap 8 6 2 5 7 4 1 9 3`)", 2), 1);
	*stack = NULL;
	code = ft_parse_into(stack, argv + 1, (size_t)argc - 1);
	if (code.type == None)
		return (ft_putstr_fd("Parsing error: ALLOCATION ERROR", 2), 10);
	if (code.value != Atoi_Ok)
		return (ft_ilstclear(stack), ft_putstr_fd("Parsing error: ", 2),
			ft_putendl_fd(atoi_error[code.value], 2), 10 + code.value);
	if (ft_has_duplicates(*stack))
		return (ft_ilstclear(stack), 20);
	*lis = ft_lis_circular(*stack);
	if (*lis == NULL)
		return (ft_ilstclear(stack),
			ft_putendl_fd("L.I.S. error: ALLOCATION ERROR", 2), 30);
	return (0);
}

__attribute__((warn_unused_result)) __attribute__((nonnull))
///@param[out] destination
static t_int_option	ft_parse_into(t_ilist *const destination,
	const char *const strings[const], const size_t amount)
{
	size_t			i;
	t_atoi_result	atoi_try;
	t_inode			*node;

	i = 0;
	while (i < amount)
	{
		atoi_try = ft_try_atoi(strings[i]);
		if (atoi_try.code != Atoi_Ok)
			return ((t_int_option){.type = Some, .value = (int)atoi_try.code});
		node = ft_ilstnew(atoi_try.ok);
		if (node == NULL)
			return ((t_int_option){.type = None});
		ft_ilstadd_back(destination, node);
		++i;
	}
	return ((t_int_option){.type = Some, .value = Atoi_Ok});
}

__attribute__ ((warn_unused_result))
static char	ft_has_duplicates(const t_ilist list)
{
	t_inode	*p;
	t_inode	*q;

	p = list;
	while (p->next != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			if (q->datum == p->datum)
				return (ft_putstr_fd("Duplicate number: ", 2),
					ft_putnbr_fd(p->datum, 2),
					//ft_putstr_fd(" at positions ", 2),
					//ft_putstr_fd(" and ", 2),
					//ft_putnbr_fd(ft_lstget_int(ft_lstget_int
					//		(stacks.primary, p.datum)->next, q.datum, 2),
					ft_putendl_fd("", 2), 1);
			q = q->next;
		}
		p = p->next;
	}
	return (0);
}
