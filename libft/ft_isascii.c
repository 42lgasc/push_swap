/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:21:45 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/12 00:32:59 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @remark This function aims to replicate the `libc` function `isascii`. */
int	ft_isascii(int character)
{
	return ('\0' <= character && character <= '\x7F');
}
