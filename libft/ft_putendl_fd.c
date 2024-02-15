/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:55:44 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/13 13:46:27 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Outputs the `string` to the given `file_descriptor` followed by a newline.
///@param[in] string What to put (A newline will be added.)
///@param[in] file_descriptor Where to put
///@remarks External function: `write`
void	ft_putendl_fd(const char *const string, int file_descriptor)
{
	ft_putstr_fd(string, file_descriptor);
	write(file_descriptor, "\n", 1);
}
