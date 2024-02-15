/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:41:59 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/13 14:24:32 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Outputs the `string` to the given `file_descriptor`.
///@param[in] string What to put
///@param[in] file_descriptor Where to write
///@remarks External function: `write`
void	ft_putstr_fd(const char *const string, const int file_descriptor)
{
	write(file_descriptor, string, ft_strlen(string));
}
