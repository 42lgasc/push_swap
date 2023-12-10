/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:51:52 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/12 00:40:17 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @remark This function aims to replicate the `libc` function `toupper`. */
int	ft_toupper(int character)
{
	if ('a' <= character && character <= 'z')
		return (character - ('a' - 'A'));
	return (character);
}
