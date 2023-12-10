/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:17:29 by lgasc             #+#    #+#             */
/*   Updated: 2023/03/02 17:34:02 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @remark This function aims to replicate the `libc` function `strrchr`. */
char	*ft_strrchr(const char *string, int character)
{
	unsigned int	i;
	const char		*match;

	if (! string)
		return (NULL);
	i = 0;
	match = NULL;
	while (string[i])
	{
		if (((const unsigned char *const) string)[i]
			== (const unsigned char) character)
			match = &string[i];
		i++;
	}
	if (((const unsigned char *const) string)[i]
		== (const unsigned char) character)
		match = &string[i];
	return ((char *const) match);
}
