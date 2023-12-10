/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:17:13 by lgasc             #+#    #+#             */
/*   Updated: 2023/03/02 17:29:26 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @remark This function aims to replicate the `libc` function `memmove`. */
void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned int	i;

	if ((! destination) || (! source))
		return (destination);
	i = 0;
	while (i < n)
	{
		if (source < destination)
			((char *const) destination)[n - i - 1]
				= ((const char *const) source)[n - i - 1];
		else
			((char *const) destination)[i]
				= ((const char *const) source)[i];
		i++;
	}
	return (destination);
}
