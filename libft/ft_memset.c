/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:37:56 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/07 14:06:41 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///@remark This function aims to replicate the `libc` function `memset`.
// Stop changing the argument type to `char`!
void	*ft_memset(void *start, int character, size_t size)
{
	size_t	i;

	if (! start)
		return (start);
	i = 0;
	while (i < size)
		((unsigned char *const) start)[i++] = (unsigned char) character;
	return (start);
}
