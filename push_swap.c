/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:27:12 by lgasc             #+#    #+#             */
/*   Updated: 2023/12/06 19:35:52 by lgasc            ###   ########.fr       */
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
///>: une liste d’entiers
///>## Fonctions externes autorisées
///>* * `read`
///>  * `write`
///>  * `malloc`
///>  * `free`
///>  * `exit`
///>* `ft_printf` et tout équivalent que **vous** avez codé
///>## Libft autorisée
///>Oui
///>## Description
///>Trier les piles
int	main(const int argc, const char *const argv[const])
{
	struct s_stacks			stacks;
	size_t					i;
	struct s_atoi_result	atoi_result;

	if (argc - 1 < 1)
		return (1);
	stacks.primary = malloc((unsigned)(argc - 1) * sizeof * stacks.primary);
	i = 0;
	while (i < (size_t)argc - 1)
	{
		atoi_result = ft_try_atoi(argv[i + 1]);
		if (atoi_result.type == Error)
			return (free(stacks.primary), (signed)(10 + atoi_result.error));
		stacks.primary[i++] = atoi_result.ok;
	}
	gnome_sort(NULL, NULL);
	free(stacks.primary);
}
