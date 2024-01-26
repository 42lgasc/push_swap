/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:27:12 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/26 18:37:16 by lgasc            ###   ########.fr       */
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
	const size_t			length = (size_t)argc - 1;
	struct s_stacks			stacks = (struct s_stacks)
			{.primary = malloc(length * sizeof * stacks.primary)};
	size_t					i;
	struct s_atoi_result	atoi_result;
	t_int_array				lis;

	if (argc - 1 < 1)
		return (1);
	i = 0;
	while (i < length)
	{
		atoi_result = ft_try_atoi(argv[i + 1]);
		if (atoi_result.type == Error)
			return (free(stacks.primary), (signed)(10 + atoi_result.error));
		stacks.primary[i++] = atoi_result.ok;
	}
	lis = ft_lis(stacks.primary, length);
	if (lis->length == 0)
		return (free(stacks.primary), 20);
	i = 0, ft_printf("lis: {->length: %u, ->ints: [", lis->length);
	while (i < lis->length)
		ft_printf("%i", lis->ints[i++]), (i < lis->length) && ft_printf(", ");
	ft_printf("]}\n");
	free(stacks.primary), free(lis);
}
