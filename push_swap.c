/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:27:12 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/28 18:29:05 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include "push_swap.h"
#include "parsing.h"
#include "aim.h"
#include "offload.h"

#ifdef TEST
# include "ft_printf/print_misc.h"
#else

void	ft_debug_array(const t_int_array array)
{
	(void) array;
}
#endif

static void	ft_realign_primary(struct s_stacks *const stacks);
static void	ft_order_three(struct s_stacks *stacks);
static void	ft_reload(struct s_stacks *stacks);

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
__attribute__ ((nonnull)) __attribute__ ((warn_unused_result))
///> ## Nom du programme
///> # `push_swap`
///> ## Fichiers de rendu
///> * `Makefile`
///> * _`*`_`.h`
///> * _`*`_`.c`
///> ## Makefile
///> * _`NAME`_
///> * `all`
///> * `clean`
///> * `fclean`
///> * `re`
///> ## Arguments
///> * ### pile _`a`_
///>    une liste d'entiers
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
///
///Shoutout to _Beatriz `bedos-sa` Dos Santos Dile_ and _Ali Yigit `yogun` Ogun_
///	for the _Mechanical Turk_ hint.
///__TODO: Extract to function, Remove call to `ft_lstget`__
int	main(const int argc, const char *const argv[const])
{
	struct s_stacks	stacks;
	int				code;
	t_int_array		lis;

	code = ft_check_input(&stacks.primary, &lis, argc, argv);
	if (code != 0)
		return (ft_putendl_fd("Error!", 1), code);
	stacks.secondary = NULL;
	ft_print_stacks(stacks);
	ft_debug_array(lis);
	if (lis->length == ft_ilstsize(stacks.primary))
		return (ft_realign_primary(&stacks), ft_ilstclear(&stacks.primary),
			free(lis), 0);
	free(lis);
	if (ft_ilstsize(stacks.primary) >= 5)
		ft_push_to_b(&stacks);
	if (ft_ilstsize(stacks.primary) >= 4)
		ft_push_to_b(&stacks);
	if (ft_offload(&stacks) != 0)
		return (ft_putstr_fd("Offload error: ALLOCATION ERROR", 2),
			ft_putendl_fd("Error!", 1), 40);
	(ft_order_three(&stacks), ft_reload(&stacks), ft_realign_primary(&stacks));
	ft_print_stacks(stacks);
	(ft_ilstclear(&stacks.primary), ft_ilstclear(&stacks.secondary));
}

///TODO: Remove call to `ft_lstget`
__attribute__ ((nonnull))
static void	ft_realign_primary(struct s_stacks *const stacks)
{
	size_t	i;

	i = 0;
	while (ft_ilstget(stacks->primary, i) != NULL)
		if (ft_ilstget(stacks->primary, ++i) == NULL
			|| ft_ilstget(stacks->primary, i - 1)->datum
			> ft_ilstget(stacks->primary, i)->datum)
			break ;
	i %= ft_ilstsize(stacks->primary);
	while (stacks->primary->datum > ft_ilstlast(stacks->primary)->datum)
		if (i <= ft_ilstsize(stacks->primary) / 2)
			ft_raise_a(stacks);
	else
		ft_refurb_a(stacks);
}

__attribute__ ((nonnull))
///   |   | a>b && b>c | a>b && b<c | a<b && b>c | a<b && b<c 
///------:|:----------:|:----------:|:----------:|:----------:
///__a>c__|    swap    |    noop    |    noop    | ~nonsense~ 
///__a<c__| ~nonsense~ |    swap    |    swap    |    noop    
static void	ft_order_three(struct s_stacks *const stacks)
{
	if (ft_ilstsize(stacks->primary) < 3)
		return ;
	if ((stacks->primary->next->datum > stacks->primary->next->next->datum
			&& stacks->primary->datum > stacks->primary->next->datum)
		|| (stacks->primary->next->datum > stacks->primary->next->next->datum
			&& stacks->primary->next->next->datum > stacks->primary->datum)
		|| (stacks->primary->next->next->datum > stacks->primary->datum
			&& stacks->primary->datum > stacks->primary->next->datum))
		ft_swap_a(stacks);
}

__attribute__ ((nonnull))
static void	ft_reload(struct s_stacks *const stacks)
{
	size_t	aim_offset;
	size_t	i;

	while (stacks->secondary != NULL)
	{
		aim_offset = ft_waxing_aim(stacks->primary, stacks->secondary->datum);
		i = 0;
		if (aim_offset <= ft_ilstsize(stacks->primary) / 2)
			while (i < aim_offset)
				(ft_raise_a(stacks), ++i);
		else
			while (i < ft_ilstsize(stacks->primary) - aim_offset)
				(ft_refurb_a(stacks), ++i);
		ft_push_to_a(stacks);
	}
}
