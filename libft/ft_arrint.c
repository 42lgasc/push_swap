/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:00:57 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/22 10:19:12 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

#include "types.h"

__attribute__ ((nonnull)) __attribute__ ((warn_unused_result))
const int	*ft_arrint(const t_int_array array, const int integer)
{
	size_t	i;

	i = 0;
	while (i < array->length)
		if (array->ints[i++] == integer)
			return (&array->ints[--i]);
	return (NULL);
}
