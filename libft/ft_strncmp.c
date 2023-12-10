/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:13:45 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/17 13:32:06 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @remark This function aims to replicate the `libc` function `strncmp`. */
int	ft_strncmp(const char *string1, const char *string2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (string1[i] != string2[i])
			return ((const unsigned char) string1[i]
				- (const unsigned char) string2[i]);
		if (string1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
