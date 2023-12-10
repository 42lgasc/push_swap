/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:27:12 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/21 18:07:13 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @remark This function aims to replicate the `libc` function `memchr`. */
void	*ft_memchr(const void *s, int character, size_t n)
{
	unsigned int	i;

	if (! s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((const unsigned char *const) s)[i]
			== (const unsigned char) character)
			return (&((unsigned char *const) s)[i]);
		i++;
	}
	return (NULL);
}
