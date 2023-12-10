/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:56:55 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/12 00:40:01 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @remark This function aims to replicate the `libc` function `tolower`. */
int	ft_tolower(int character)
{
	if ('A' <= character && character <= 'Z')
		return (character + ('a' - 'A'));
	return (character);
}
