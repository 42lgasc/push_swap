/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:37:56 by lgasc             #+#    #+#             */
/*   Updated: 2023/06/29 18:52:42 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @remark This function aims to replicate the `libc` function `memset`. */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	if (! s)
		return (s);
	i = 0;
	while (i < n)
		((char *const) s)[i++] = (char) c;
	return (s);
}
