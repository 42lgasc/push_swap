/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:55:31 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/10 18:37:09 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Allocates (with malloc(3)) and returns a substring from `superstring`.
///The substring begins at index `start` and is of maximum size `length`.
///@param[in] superstring The string from which to create the substring.
///@param[in] start The start index of the substring in `superstring`.
///@param[in] length The maximum length of the substring.
///@returns The substring. NULL if the allocation fails.
///@remarks External function: `malloc`
///@see https://stackoverflow.com/a/5416724
char	*ft_substr(char const *superstring, size_t start, size_t length)
{
	char			*substring;
	unsigned int	i;

	if ((! superstring) || start > ft_strlen(superstring))
		return (ft_strdup(""));
	if (ft_strlen(superstring) < start + length)
		substring = ft_calloc(
				ft_strlen(superstring) + 1 - start, sizeof * substring);
	else
		substring = ft_calloc(length + 1, sizeof * substring);
	if (! substring)
		return (NULL);
	i = 0;
	while (i < length && superstring[start + i] != '\0')
	{
		substring[i] = superstring[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
