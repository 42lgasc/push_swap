/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:44:15 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/07 13:45:19 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///@remark This function aims to replicate the `libc` function `bzero`.
///@remark Compiler optimizations may remove the erase operation
///	if the compiler deduces that the operation is "unnecessary".
///	See the page of the `man` `BZERO``(3)`
void	ft_bzero(void *start, size_t size)
{
	if (! start)
		return ;
	start = ft_memset(start, '\0', size);
}
