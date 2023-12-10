/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:57:21 by lgasc             #+#    #+#             */
/*   Updated: 2023/03/02 17:32:14 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Returns a pointer to the first occurrence of
 * the `character` in the `string`.
 * @param[in] string The string in which to search `character`.
 * @param[in] character The character to be searched in `string`.
 * @remarks Here "character" means "byte";
 * 	this function do not work with wide or multibyte characters.
 * @returns A pointer to the matched character or
 * 	NULL if the `character` is not found. The terminating null byte is
 * 	considered part of the `string`, so that if `character` is specified as
 * 	'\0', this function returns a pointer to the terminator.
 * @remark This function aims to replicate the `libc` function `strchr`.
 */
char	*ft_strchr(const char *string, int character)
{
	unsigned int	i;

	if (! string)
		return (NULL);
	i = 0;
	while (string[i])
	{
		if (((const unsigned char *const) string)[i]
			== (const unsigned char) character)
			return (& ((char *const) string)[i]);
		i++;
	}
	if (((const unsigned char *const) string)[i]
		== (const unsigned char) character)
		return (& ((char *const) string)[i]);
	return (NULL);
}
