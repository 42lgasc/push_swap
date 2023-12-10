/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:48:14 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/12 00:32:42 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @remark This function aims to replicate the `libc` function `isalpha`. */
int	ft_isalpha(int character)
{
	return (('A' <= character && character <= 'Z')
		|| ('a' <= character && character <= 'z'));
}
