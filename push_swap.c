/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:27:12 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/15 21:16:38 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_lis.h"

#include "push_swap.h"

static
enum e_atoi_code	ft_parse_into(t_int_list *destination,
						const char *const strings[], size_t amount)
					__attribute__((warn_unused_result))__attribute__((nonnull));

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
int	main(const int argc, const char *const argv[const])
{
	struct s_stacks		stacks;
	enum e_atoi_code	code;
	size_t				i;
	t_int_array			lis;
	size_t				j;

	//stacks.size = (size_t)argc - 1;
	if (//stacks.size
		argc <= 1)
		return (1);
	//stacks.masks = ft_calloc(stacks.size, sizeof * stacks.masks);
	//stacks.primary_top = 0;
	stacks.primary //= malloc(stacks.size * sizeof * stacks.primary);
	= NULL;
	//stacks.secondary_top = 0;
	stacks.secondary //= malloc(stacks.size * sizeof * stacks.secondary);
	= NULL;
	//if (stacks.masks == NULL || stacks.primary == NULL
	//	|| stacks.secondary == NULL)
	//	return (l(stacks.primary),
	//		free(stacks.secondary), 2);
	//i = 0;
	//while (i < stacks.size)
	//	stacks.masks[i++] = Primary;
	code = ft_parse_into(&stacks.primary, argv + 1, //stacks.size
		(size_t)argc - 1);
	if (code != Atoi_Ok)
		return (//free(stacks.masks), free(stacks.primary),
			//free(stacks.secondary),
			ft_lstclear_int(&stacks.primary), (signed)(10 + code));
	ft_print_stacks(stacks);
	lis = ft_lis_circular(stacks.primary//, stacks.size
		);
	if (lis == NULL || lis->length == 0)
		return (free(stacks.primary), free(stacks.primary),
			free(stacks.secondary), free(lis), 20);
	//i= (ft_printf("lis: {->length: %u, ->ints: [", (unsigned)lis->length), 0);
	//while (i < lis->length)
	//	(ft_printf("%i", lis->ints[i]), ft_print_if(++i < lis->length, ", "));
	//ft_printf("]}\n");
	ft_print_array(lis);
	i = 0;
	j = 0;
	while (i < /*stacks.size*/ft_lstsize_int(stacks.primary)
		+ ft_lstsize_int(stacks.secondary))
		if (++i, j < lis->length
			&& ft_primary_top(stacks).value == lis->ints[j])
			(ft_raise_a(&stacks), ++j);
	else
		ft_push_to_b(&stacks);
	//
	ft_print_stacks(stacks);
	//
	while (stacks.secondary != NULL)
	{
		if (ft_primary_top(stacks).type == Some
			&& ft_secondary_top(stacks).type == Some)
		{
			// Is the stack oriented in way such its boundary
			// 	is aligned correctly; with the top being the
			// 	smallest and the bottom being the biggest?
			if (ft_primary_bottom(stacks).value > ft_primary_top(stacks).value)
			//if (0)
			{
				if (stacks.secondary->datum < ft_primary_top(stacks).value)
					// Prepend
					ft_push_to_a(&stacks);
				else if (ft_primary_bottom(stacks).value
					< ft_secondary_top(stacks).value)
					// Append
					ft_push_to_a(&stacks);
				else if (ft_putnbr_fd(ft_secondary_bottom(stacks).value, 2),
					ft_putnbr_fd(ft_primary_bottom(stacks).value, 2),
					ft_primary_bottom(stacks).value
					> ft_secondary_bottom(stacks).value)
					if (stacks.primary->datum
						< ft_lstlast_int(stacks.secondary)->datum)
						ft_rake_refurb(&stacks);//, ft_push_to_a(&stacks));
					else
						ft_refurb_b(&stacks);//, ft_push_to_a(&stacks));
				else
				{
					//(ft_putnbr_fd(__LINE__, 2), ft_putendl_fd(__FILE__, 2),
					//	exit(TODO));
					ft_refurb_b(&stacks);
				}
			}
			else if (ft_primary_bottom(stacks).value > stacks.secondary->datum)
			{
				if (ft_secondary_bottom(stacks).value
					< ft_primary_bottom(stacks).value)
					if (ft_lstplast_int(stacks.primary) == NULL)
						//(ft_putnbr_fd(__LINE__, 2), ft_putendl_fd(__FILE__, 2),
						//	exit(TODO));
						ft_push_to_a(&stacks);
					else if (ft_lstplast_int(stacks.primary)->datum
						< ft_lstlast_int(stacks.secondary)->datum)
						ft_rake_refurb(&stacks);//, ft_push_to_a(&stacks));
					else if (ft_lstplast_int(stacks.primary)->datum
						< stacks.secondary->datum)
						ft_refurb_a(&stacks);//, ft_push_to_a(&stacks));
					else if (ft_lstplast_int(stacks.primary)->datum
						> ft_lstlast_int(stacks.primary)->datum)
						ft_refurb_a(&stacks);//, ft_push_to_a(&stacks));
					else
						ft_rake_refurb(&stacks);//(ft_putnbr_fd(__LINE__, 2),
							//ft_putendl_fd(__FILE__, 2), exit(TODO));
				else
				{
					//(ft_putnbr_fd(__LINE__, 2), ft_putendl_fd(__FILE__, 2),
					//	exit(TODO));
					ft_refurb_a(&stacks);
				}
			}
			else if (
				ft_primary_top(stacks).value < ft_secondary_top(stacks).value)
			{
				if (stacks.primary->datum > ft_lstlast_int(stacks.secondary)->datum)
					ft_refurb_b(&stacks);
				//exit((ft_putnbr_fd(__LINE__, 2), ft_putendl_fd(__FILE__, 2),
				//		TODO));
				else
					ft_rake_refurb(&stacks);
				//ft_print_stacks(stacks);
			}
			else
					// Classically insert
				ft_push_to_a(&stacks);
		}
	}
	ft_print_stacks(stacks);
	while (stacks.primary->datum > ft_lstlast_int(stacks.primary)->datum)
		ft_refurb_a(&stacks);
	ft_print_stacks(stacks);
	(ft_lstclear_int(&stacks.primary), ft_lstclear_int(&stacks.secondary),
		free(lis));
}

///@param[out] destination
static enum e_atoi_code	ft_parse_into(t_int_list *const destination,
	const char *const strings[const], const size_t amount)
{
	size_t			i;
	t_atoi_result	atoi_try;
	t_int_node		*node __attribute__ ((unused));

	i = 0;
	while (i < amount)
	{
		//if (strings[i] == NULL)
		//	return ((t_parse_result){.type = Error, .error = NullString});
		atoi_try = ft_try_atoi(strings[i]);
		if (atoi_try.code != Atoi_Ok)
			return (atoi_try.code);
		//ft_printf("atoi_try.ok: %i\n", atoi_try.ok);
		//destination[i++] = result.ok;
		ft_lstadd_back_int(destination, ft_lstnew_int(atoi_try.ok));
		//ft_putstr_fd("destination: [", 1);
		//node = *destination;
		//while (node != NULL)
		//	ft_printf("%i", node->datum),
		//		ft_print_if(node->next != NULL, ", ")
		//	node = node->next;
		//ft_putendl_fd("]", 1);
		++i;
	}
	return (Atoi_Ok);
}
