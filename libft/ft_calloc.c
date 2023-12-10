/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:09:58 by lgasc             #+#    #+#             */
/*   Updated: 2023/09/14 14:43:06 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 4 294 967 295 = UINT_MAX */
///@see https://stackoverflow.com/a/1815391
///@remark `errno` is NOT set when the multiplication of `member_amount` and
///	`member_size` would result in an integer overflow.
void	*ft_calloc(size_t member_amount, size_t member_size)
{
	unsigned int	i;
	void			*array;

	if (member_amount == 0 || member_size == 0)
		return (malloc(0));
	if (member_amount > 4294967295 / member_size)
		return (NULL);
	array = malloc(member_amount * member_size);
	if (! array)
		return (NULL);
	i = 0;
	while (i < member_amount * member_size)
	{
		((char *const) array)[i] = 0;
		i++;
	}
	return (array);
}
