/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:14:34 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/22 20:12:42 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "max.h"

__attribute__ ((warn_unused_result))
size_t	ft_zmax(const size_t a, const size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

//unsigned	ft_umaxo()
//{
//}

//unsigned long	ft_ulmaxo(void)
//{
//	return (0);
//}

//size_t	ft_zmaxo(const size_t array[const], const size_t length)
//{
//	size_t	i;
//
//	i = 0;
//	
//}

///@returns the offset of one of the maximum values of the `array`
__attribute__ ((nonnull))
t_max_result	ft_try_zmaxo(const size_t array[const], const size_t length)
{
	size_t	i;
	size_t	maximum_offset;

	if (length == 0)
		return ((t_max_result){.code = NoElement});
	i = 0;
	maximum_offset = 0;
	while (++i < length)
		if (array[i] > array[maximum_offset])
			maximum_offset = i;
	return ((t_max_result){.code = Max_Ok, .ok = maximum_offset});
}
