/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:27:12 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/23 17:14:37 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_lis.h"

//
# include "ft_printf/print_misc.h"
//

#include "push_swap.h"

static enum e_atoi_code	ft_parse_into(t_int_list *destination,
							const char *const strings[], size_t amount);
size_t					ft_waxing_aim(t_int_list list, int value);
size_t					ft_waning_aim(t_int_list list, int value);

///> # Nom du programme
///> _`push_swap`_

///> ## Fichiers de rendu
///> * `Makefile`
///> * `*.h`
///> * `*.c`

///> ## Makefile
///> * _`NAME`_
///> * `all`
///> * `clean`
///> * `fclean`
///> * `re`

///> ## Arguments
///> pile _`a`_
///> : une liste d'entiers

///> ## Fonctions externes autoriseies
///> * * `read`
///>   * `write`
///>   * `malloc`
///>   * `free`
///>   * `exit`
///> * `ft_printf` et tout eiquivalent que **vous** avez codei

///> ## Libft autoriseie
///> Oui

///> ## Description
///> Trier les piles

///Shoutout to _`bedos-sa` Beatriz Dos Santos Dile_ and _`yogun` Ali Yigit Ogun_
///	for the Mechanical Turk hint.
int	main(const int argc, const char *const argv[const])
{
	struct s_stacks		stacks;
	enum e_atoi_code	code;
	const char *const	atoi_error[] = {[Atoi_Ok] = "OK",
		[NullString] = "NULL STRING", [NonNumeric] = "NON-NUMERIC STRING",
		[BeyondLimits] = "INTEGER BEYOND LIMITS"};
	t_int_node			*p;
	t_int_node			*q;
	//t_int_list			clone;
	//t_int_array			clone_lis;
	size_t				i;
	t_int_array			lis;
	//size_t				j;
	///t_int_node			*node;
	//size_t				min_pos;
	//int					min_val;

	if (argc <= 1)
		return (ft_putendl_fd("Error!", 1),
			ft_putendl_fd("Missing argument "
				"(try the following: `./push_swap 8 6 2 5 7 4 1 9 3`)", 2), 1);
	stacks.primary = NULL;
	code = ft_parse_into(&stacks.primary, argv + 1, (size_t)argc - 1);
	if (code != Atoi_Ok)
		return (ft_lstclear_int(&stacks.primary),
			ft_putendl_fd("Error!", 1), ft_putstr_fd("Parsing error: ", 2),
			ft_putendl_fd(atoi_error[code], 2), 10 + (signed)code);
	p = stacks.primary;
	while (p->next != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			if (q->datum == p->datum)
				return (ft_putendl_fd("Error!", 1),
					ft_putstr_fd("Duplicate number: ", 2),
					ft_putnbr_fd(p->datum, 2),
					//ft_putstr_fd(" at positions ", 2),
					//ft_putstr_fd(" and ", 2),
					//ft_putnbr_fd(ft_lstget_int(ft_lstget_int
					//		(stacks.primary, p.datum)->next, q.datum, 2),
					ft_putendl_fd("", 2),
					ft_lstclear_int(&stacks.primary), 20);
			q = q->next;
		}
		p = p->next;
	}
	lis = ft_lis_circular(stacks.primary);
	if (lis == NULL || lis->length == 0)
		return (ft_lstclear_int(&stacks.primary), free(lis),
			ft_putendl_fd("Error!", 1), 30);
	stacks.secondary = NULL;
	ft_print_stacks(stacks);
	ft_print_array(lis);
	//if (stacks.primary->next != NULL)
	//{
	//	clone = ft_lstclone_int(stacks.primary);
	//	ft_lstswap_int(&clone, &clone->next);
	//	clone_lis = ft_lis_circular(clone);
	//	if (clone_lis->length > lis->length)
	//		lis = (ft_swap_a(&stacks), free(lis), clone_lis);
	//	else
	//		free(clone_lis);
	//	ft_lstclear_int(&clone);
	//}
	
	//i = 0;
	//j = 0;
	//while (i++ < ft_lstsize_int(stacks.primary)
	//	+ ft_lstsize_int(stacks.secondary) + j - lis->length)
	//	if (j < lis->length && ft_arrint(lis, stacks.primary->datum) != NULL)
	//		(ft_raise_a(&stacks), ++j);
	//else
	//	ft_push_to_b(&stacks);
	if (ft_lstsize_int(stacks.primary) >= 5)
		ft_push_to_b(&stacks);
	if (ft_lstsize_int(stacks.primary) >= 5)
		ft_push_to_b(&stacks);
	
	//while (ft_print_stacks(stacks), stacks.secondary != NULL)
	//\// Is the stack oriented in way such its boundary
	//\// 	is aligned correctly; with the top being the
	//\// 	smallest and the bottom being the biggest?
	//	if (stacks.primary->datum < ft_lstlast_int(stacks.primary)->datum)
	//		if (stacks.primary->datum > stacks.secondary->datum)
	//		// Prepend
	//			ft_push_to_a(&stacks);
	//		else if (ft_lstlast_int(stacks.primary)->datum
	//			< stacks.secondary->datum)
	//		// Append
	//			ft_push_to_a(&stacks);
	//		else if (ft_lstlast_int(stacks.primary)->datum
	//			> ft_lstlast_int(stacks.secondary)->datum)
	//			if (stacks.primary->datum
	//				< ft_lstlast_int(stacks.secondary)->datum)
	//				if (stacks.primary->next != NULL
	//					&& stacks.secondary->next != NULL
	//					&& stacks.primary->next->datum
	//					> stacks.secondary->next->datum)
	//					ft_rake_raise(&stacks);
	//				else
	//					ft_rake_refurb(&stacks);
	//			else
	//				ft_refurb_b(&stacks);
	//		else
	//			ft_refurb_b(&stacks);
	//	else if (ft_primary_bottom(stacks).value > stacks.secondary->datum)
	//		if (ft_secondary_bottom(stacks).value
	//			< ft_primary_bottom(stacks).value)
	//			if (ft_lstplast_int(stacks.primary) == NULL)
	//				ft_push_to_a(&stacks);
	//			else if (ft_lstplast_int(stacks.primary)->datum
	//				< ft_lstlast_int(stacks.secondary)->datum)
	//				ft_rake_refurb(&stacks);
	//			else if (ft_lstplast_int(stacks.primary)->datum
	//				< stacks.secondary->datum)
	//				ft_refurb_a(&stacks);
	//			else if (ft_lstplast_int(stacks.primary)->datum
	//				> ft_lstlast_int(stacks.primary)->datum)
	//				ft_refurb_a(&stacks);
	//			else
	//				ft_rake_refurb(&stacks);
	//		else
	//			ft_refurb_a(&stacks);
	//	else if (stacks.primary->datum < stacks.secondary->datum)
	//		if (stacks.primary->datum > ft_lstlast_int(stacks.secondary)->datum)
	//			ft_refurb_b(&stacks);
	//		else
	//			ft_rake_refurb(&stacks);
	//	else
	//	// Classically insert
	//		ft_push_to_a(&stacks);
	while (ft_lstsize_int(stacks.primary) > 3)
	{
		size_t		offset = 0;
		t_znode	*costs = NULL;
		while (offset < ft_lstsize_int(stacks.secondary))
		{
			size_t	aim_offset = ft_waning_aim(
				stacks.secondary, ft_lstget_int(stacks.primary, offset)->datum);
			//if (aim_offset <= ft_lstsize(stacks.secondary))
			ft_zlstadd_back(&costs, ft_zlstnew(ft_zmin(ft_zmin(ft_zmin
								(ft_zmax(offset, aim_offset),
									ft_lstsize_int(stacks.secondary)
										- aim_offset + offset),
							ft_lstsize_int(stacks.primary)
								- offset + aim_offset),
						ft_zmax(ft_lstsize_int(stacks.primary) - offset,
							ft_lstsize_int(stacks.secondary) - aim_offset))));
			++offset;
		}
		offset = 0;
		size_t	best_offset = 0;
		while (offset < ft_lstsize_int(stacks.primary))
			if (ft_zlstget(costs, offset++)->inner
				< ft_zlstget(costs, best_offset)->inner)
				best_offset = offset - 1;
		size_t	goal_offset = ft_waning_aim
		(stacks.secondary, ft_lstget_int(stacks.primary, best_offset)->datum);
		if (ft_zlstget(costs, best_offset)->inner
			== ft_zmax(best_offset, goal_offset))
		{
			i = 0;
			while (i < ft_zmin(best_offset, goal_offset))
				(ft_rake_raise(&stacks), ++i);
			if (best_offset > goal_offset)
				while (i < best_offset)
					(ft_raise_a(&stacks), ++i);
			else while (i < goal_offset)
				(ft_raise_b(&stacks), ++i);
		}
		else if (ft_zlstget(costs, best_offset)->inner
			== ft_lstsize_int(stacks.secondary) - goal_offset + best_offset)
		{
			i = 0;
			while (i < best_offset)
				(ft_raise_a(&stacks), ++i);
			i = 0;
			while (i < ft_lstsize_int(stacks.secondary) - goal_offset)
				(ft_refurb_b(&stacks), ++i);
		}
		else if (ft_zlstget(costs, best_offset)->inner
			== ft_lstsize_int(stacks.primary) - best_offset + goal_offset)
		{
			i = 0;
			while (i < ft_lstsize_int(stacks.primary) - best_offset)
				(ft_refurb_a(&stacks), ++i);
			i = 0;
			while (i < goal_offset)
				(ft_raise_b(&stacks), ++i);
		}
		else
		{
			i = 0;
			while (i < ft_zmin(ft_lstsize_int(stacks.primary) - best_offset,
					ft_lstsize_int(stacks.secondary) - goal_offset))
				(ft_rake_refurb(&stacks), ++i);
			if (ft_lstsize_int(stacks.primary) - best_offset
				> ft_lstsize_int(stacks.secondary) - goal_offset)
				while (i < ft_lstsize_int(stacks.primary) - best_offset)
					(ft_refurb_a(&stacks), ++i);
			else while (i < ft_lstsize_int(stacks.secondary) - goal_offset)
					(ft_refurb_b(&stacks), ++i);
		}
		ft_zlstclear(&costs);
		ft_push_to_b(&stacks);
		ft_print_stacks(stacks);
	}
	if (ft_lstsize_int(stacks.primary) == 3
		&& ((stacks.primary->datum > stacks.primary->next->datum
				&& stacks.primary->next->datum
				> stacks.primary->next->next->datum)
			|| (stacks.primary->next->datum > stacks.primary->next->next->datum
				&& stacks.primary->next->next->datum > stacks.primary->datum)
			|| (stacks.primary->next->next->datum > stacks.primary->datum
				&& stacks.primary->datum > stacks.primary->next->datum)))
		ft_swap_a(&stacks);
	//\// TODO: Extract to function, Remove call to `ft_lstget`
	//node = stacks.primary->next;
	//min_pos = 0;
	//\//min_val = stacks.primary->datum;
	//i = 1;
	//while (node != NULL)
	//{
	//	if (node->datum < ft_lstget_int(stacks.primary, min_pos)->datum)
	//		min_pos = i;
	//	node = (++i, node->next);
	//}
	//\//ft_putnbr_fd((int)min_pos, 2);
	//if (min_pos <= ft_lstsize_int(stacks.primary) / 2)
	//	while (stacks.primary->datum > ft_lstlast_int(stacks.primary)->datum)
	//		ft_raise_a(&stacks);
	//else while (stacks.primary->datum > ft_lstlast_int(stacks.primary)->datum)
	//	ft_refurb_a(&stacks);
	while (stacks.secondary != NULL)
	{
		size_t	aim_offset;
		aim_offset = ft_waxing_aim(stacks.primary, stacks.secondary->datum);
		i = 0;
		if (aim_offset <= ft_lstsize_int(stacks.primary) / 2)
			while (i < aim_offset)
				(ft_raise_a(&stacks), ++i);
		else while (i < ft_lstsize_int(stacks.primary) - aim_offset)
			(ft_refurb_a(&stacks), ++i);
		ft_push_to_a(&stacks);
	}
	//if (stacks.primary->next != NULL)size_t	aim;
	//aim = ft_waxing_aim(stacks.primary->next, stacks.primary->datum);
	//t_int_node	*node;
	//node = stacks.primary;
	i = 0;
	while (ft_lstget_int(stacks.primary, i) != NULL)
		if (ft_lstget_int(stacks.primary, ++i) == NULL
			|| ft_lstget_int(stacks.primary, i - 1)->datum
			> ft_lstget_int(stacks.primary, i)->datum)
			break ;
	i %= ft_lstsize_int(stacks.primary);
	while (stacks.primary->datum > ft_lstlast_int(stacks.primary)->datum)
		if (i <= ft_lstsize_int(stacks.primary) / 2)
			ft_raise_a(&stacks);
	else
		ft_refurb_a(&stacks);
	ft_print_stacks(stacks);
	(ft_lstclear_int(&stacks.primary), ft_lstclear_int(&stacks.secondary),
		free(lis));
}

///@param[out] destination
__attribute__((warn_unused_result)) __attribute__((nonnull))
static enum e_atoi_code	ft_parse_into(t_int_list *const destination,
	const char *const strings[const], const size_t amount)
{
	size_t			i;
	t_atoi_result	atoi_try;

	i = 0;
	while (i < amount)
	{
		atoi_try = ft_try_atoi(strings[i]);
		if (atoi_try.code != Atoi_Ok)
			return (atoi_try.code);
		ft_lstadd_back_int(destination, ft_lstnew_int(atoi_try.ok));
		++i;
	}
	return (Atoi_Ok);
}

__attribute__ ((nonnull)) __attribute__ ((warn_unused_result))
size_t	ft_waxing_aim(const t_int_list list, const int arrow)
{
	size_t	aim;

	//aim = 0;
	//if (ft_lstlast_int(list)->datum > arrow)
	//	while (arrow > ft_lstget_int(list, aim)->datum)
	//		if (ft_lstget_int(list, aim)->datum
	//			< ft_lstget_int(list, ++aim)->datum) ;
	//while (aim < ft_lstsize_int(list))
	//	if (arrow < ft_lstget_int(list, aim++)->datum)
	//	// Normal insertion
	//		return (aim - 1);
	//	else if (ft_lstget_int(list, aim) != NULL
	//		&& arrow > ft_lstget_int(list, aim)->datum)
	//		return (aim);
	//return (0);
	if (list->datum < ft_lstlast_int(list)->datum
		&& (arrow < list->datum || ft_lstlast_int(list)->datum < arrow))
		return (0);
	if (ft_lstlast_int(list)->datum < arrow && arrow < list->datum)
		return (0);
	aim = 0;
	while (arrow < ft_lstget_int(list, aim)->datum)
		if (ft_lstget_int(list, aim)->datum
			> ft_lstget_int(list, aim + 1)->datum
			&& arrow < ft_lstget_int(list, aim + 1)->datum)
			return (aim + 1);
	else
		++aim;
	//while (aim < ft_lstsize_int(list))
	//	if (arrow > ft_lstget_int(list, aim++))
	//		return (aim - 1);
	
	//aim = ft_lstsize_int(list) - 2;
	
	while (1)
		if ((ft_lstget_int(list, aim)->datum
				> ft_lstget_int(list, aim + 1)->datum)
			^ (arrow < ft_lstget_int(list, aim + 1)->datum))
			return (aim + 1);
	else
		++aim;
}

__attribute__ ((nonnull)) __attribute__ ((warn_unused_result))
size_t	ft_waning_aim(const t_int_list list, const int arrow)
{
	size_t	aim;

	if (list->datum > ft_lstlast_int(list)->datum
		&& (arrow > list->datum || ft_lstlast_int(list)->datum > arrow))
		return (0);
	if (ft_lstlast_int(list)->datum > arrow && arrow > list->datum)
		return (0);
	aim = 0;
	while (arrow > ft_lstget_int(list, aim)->datum)
		if (ft_lstget_int(list, aim)->datum
			< ft_lstget_int(list, aim + 1)->datum
			&& arrow > ft_lstget_int(list, aim + 1)->datum)
			return (aim + 1);
	else
		++aim;
	while (1)
		if ((ft_lstget_int(list, aim)->datum
				< ft_lstget_int(list, aim + 1)->datum)
			^ (arrow > ft_lstget_int(list, aim + 1)->datum))
			return (aim + 1);
	else
		++aim;
}
