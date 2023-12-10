/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:28:46 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/12 02:38:21 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @see https://cplusplus.com/reference/cctype/
 * @remark This function aims to replicate the `libc` function `isprint`.
 */
int	ft_isprint(int character)
{
	return (' ' <= character && character <= '~');
}
