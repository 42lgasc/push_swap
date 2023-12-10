/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:09:25 by lgasc             #+#    #+#             */
/*   Updated: 2023/10/24 13:03:08 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///The **`strlcat`**() function appends the NUL-terminated
///	string `src`_ to the end of _`dst`_.  It will append at most
///	_`size`_ - `strlen(dst)` - 1 bytes, NUL-terminating the result.
///@see https://stackoverflow.com/a/33155352
///@remark This function aims to replicate the `libc` function `strlcat`.
size_t	ft_strlcat(char *destination, const char *source, size_t size)
{
	size_t		old_destination_size;
	const char	*concatenation_point;

	if ((! source) || (! source))
		return (0);
	if (size <= ft_strlen(destination))
		return (size + ft_strlen(source));
	old_destination_size = ft_strlen(destination);
	if (ft_strlen(source) <= size - 1 - old_destination_size)
		concatenation_point
			= ft_memmove(&destination[old_destination_size], source,
				ft_strlen(source) + 1);
	else
	{
		concatenation_point
			= ft_memmove(&destination[old_destination_size], source,
				size - old_destination_size - 1);
		destination[size -1] = '\0';
	}
	return (old_destination_size + ft_strlen(source));
}
