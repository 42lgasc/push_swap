/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:14:34 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/10 19:08:13 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_max.h"

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
struct s_max_result	ft_try_zmaxo(const size_t array[const], const size_t length)
{
	size_t	i;
	size_t	maximum_offset;

	if (array == NULL)
		return ((struct s_max_result){.error = NullPointer});
	if (length == 0)
		return ((struct s_max_result){.error = ZeroElements});
	i = 0;
	maximum_offset = 0;
	while (++i < length)
		if (array[i] > array[maximum_offset])
			maximum_offset = i;
	return ((struct s_max_result){.ok = maximum_offset});
}
