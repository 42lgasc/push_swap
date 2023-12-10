/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:29:02 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/10 15:54:33 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Outputs the `character` to the given `file_descriptor`.
 * @param[in] character The character to output.
 * @param[in] file_descriptor The file descriptor on which to write.
 * @remarks External function: `write`
 */
void	ft_putchar_fd(char character, int file_descriptor)
{
	write(file_descriptor, &character, 1);
}
