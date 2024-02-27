/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:37:56 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 11:29:37 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Stop changing the pointee type to `char`! I don't quite understand why,
// 	but this is important. ~~lgasc 2024-02-27T10:45

///@remark This function aims to replicate the `libc` function `memset`.
///@return The `start` pointer again, for chaining purposes
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
