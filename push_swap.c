/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:27:12 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/30 18:38:32 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///># Nom du programme
///>_`push_swap`_
///>## Fichiers de rendu
///>* `Makefile`
///>* `*.h`
///>* `*.c`
///>## Makefile
///>* _`NAME`_
///>* `all`
///>* `clean`
///>* `fclean`
///>* `re`
///>## Arguments
///>pile _`a`_
///>: une liste d'entiers
///>## Fonctions externes autoriseies
///>* * `read`
///>  * `write`
///>  * `malloc`
///>  * `free`
///>  * `exit`
///>* `ft_printf` et tout eiquivalent que **vous** avez codei
///>## Libft autoriseie
///>Oui
///>## Description
///>Trier les piles
int	main(const int argc, const char *const argv[const])
{
	size_t					length;
	struct s_stacks			stacks;
	struct s_parsing_result	result;
	size_t					i;
	t_int_array				lis;

	(void)argv;
	length = (size_t)argc - 1;
	if (length < 1)
		return (1);
	stacks.primary = malloc(length * sizeof * stacks.primary);
	stacks.secondary = NULL;
	if (stacks.primary == NULL)
		return (2);
	result = ft_parse(stacks.primary, &argv[1], length);
	if (result.type == Error)
		return (free(stacks.primary), (signed)(10 + result.error));
	lis = ft_lis(stacks.primary, length);
	if (lis->length == 0)
		return (free(stacks.primary), 20);
	i = (ft_printf("lis: {->length: %u, ->ints: [", (unsigned)lis->length), 0);
	while (i < lis->length)
		(ft_printf("%i", lis->ints[i]), ft_print_if(++i < lis->length, ", "));
	ft_printf("]}\n");
	(free(stacks.primary), free(lis));
}

static void	ft_push_to_b(void)
{
}

// FIXME: Better error returns.
///@param[out] destination
static struct s_parsing_result	ft_parse(int destination[const],
	const char *const strings[const], const size_t amount)
{
	size_t					i;
	struct s_atoi_result	atoi_result;

	if (destination == NULL)
		return ((struct s_parsing_result)
			{.type = Error, .error = E_ATOIR_ERROR_LAST + 1});
	if (strings == NULL)
		return ((struct s_parsing_result)
			{.type = Error, .error = E_ATOIR_ERROR_LAST + 2});
	i = 0;
	while (i < amount)
	{
		if (strings[i] == NULL)
			return (
				(struct s_parsing_result){.type = Error, .error = NullString});
		atoi_result = ft_try_atoi(strings[i]);
		if (atoi_result.type == Error)
			return ((struct s_parsing_result)
				{.type = Error, .error = atoi_result.error});
		destination[i++] = atoi_result.ok;
	}
	return ((struct s_parsing_result){.type = Ok});
}
