/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:31:14 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/21 18:38:23 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @remark This function aims to replicate the `libc` function `strlen`. */
size_t	ft_strlen(const char *string)
{
	unsigned int	length;

	if (! string)
		return (0);
	length = 0;
	while (string[length])
		length++;
	return (length);
}
