/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@students.42perpignan.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:32:57 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/10 17:21:53 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_isspace(const char character)
{
	return (('\t' <= character && character <= '\r') || character == ' ');
}
