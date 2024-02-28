/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:15:21 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 22:04:55 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "bonus.h"

///TODO: Remove calls to `ft_zlstget`
__attribute__ ((nonnull)) __attribute__ ((warn_unused_result))
size_t	ft_minzlst_offset(const t_zlist list)
{
	size_t	i;
	size_t	min;

	i = 1;
	min = 0;
	while (i < ft_zlstsize(list))
		if (ft_zlstget(list, i++)->inner < ft_zlstget(list, min)->inner)
			min = i - 1;
	return (min);
}
