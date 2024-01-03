/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:27:12 by lgasc             #+#    #+#             */
/*   Updated: 2023/12/21 14:11:50 by lgasc            ###   ########.fr       */
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
	struct s_stacks			stacks;
	size_t					i;
	struct s_atoi_result	atoi_result;
	const int				*lis;

	if (argc - 1 < 1)
		return (1);
	stacks.primary = malloc(length * sizeof * stacks.primary);
	i = 0;
	while (i < length)
	{
		atoi_result = ft_try_atoi(argv[i + 1]);
		if (atoi_result.type == Error)
			return (free(stacks.primary), (signed)(10 + atoi_result.error));
		stacks.primary[i++] = atoi_result.ok;
	}
	lis = ft_lis(stacks.primary, length);
	if (lis == NULL)
		return (free(stacks.primary), 20);
	(void) 0x70D0;
	free(stacks.primary);
	return (0);
}
