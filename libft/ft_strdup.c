/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:00:03 by lgasc             #+#    #+#             */
/*   Updated: 2023/02/21 18:27:47 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *original)
{
	char			*duplicant;
	unsigned int	i;

	if (! original)
		return (NULL);
	duplicant = ft_calloc(ft_strlen(original) + 1, sizeof * duplicant);
	if (! duplicant)
		return (NULL);
	i = 0;
	while (original[i])
	{
		duplicant[i] = original[i];
		i++;
	}
	duplicant[i] = '\0';
	return (duplicant);
}
