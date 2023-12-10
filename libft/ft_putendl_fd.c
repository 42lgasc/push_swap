/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:55:44 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/10 18:04:46 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Outputs the `string` to the given `file_descriptor` followed by a newline.
 * @param[in] string The string to output.
 * @param[in] file_descriptor The file descriptor on which to write.
 * @remarks External function: `write`
 */
void	ft_putendl_fd(char *string, int file_descriptor)
{
	ft_putstr_fd(string, file_descriptor);
	write(file_descriptor, "\n", 1);
}
