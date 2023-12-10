/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:24:41 by lgasc             #+#    #+#             */
/*   Updated: 2023/09/29 14:11:26 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///@remark This function aims to replicate the `libc` function `strlcpy`.
///@return The length of the `source`.
///> The **`strlcpy()`** [function] return the total length of the string [it]
///> tried to create.  [...] that means the length of _[`source`]_.  While this
///> may seem somewhat confusing, it was done to make truncation detection
///> simple.
size_t	ft_strlcpy(char *destination, const char *const source, size_t size)
{
	if ((! destination) || (! source))
		return (0);
	if (ft_strlen(source) + 1 < size)
		destination = ft_memmove(destination, source, ft_strlen(source) + 1);
	else if (size > 0)
	{
		destination = ft_memmove(destination, source, size - 1);
		destination[size - 1] = '\0';
	}
	return (ft_strlen(source));
}
