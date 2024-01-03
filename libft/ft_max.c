/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:21:39 by lgasc             #+#    #+#             */
/*   Updated: 2023/12/20 21:25:14 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_smax(const intmax_t array[const], const size_t length)
{
	intmax_t	max;
	size_t		i;

	max = 1;
	i = 0;
	while (i < length)
	{
		if (array[i] > max)
			max = array[i];
		++i;
	}
	return (max);
}

intmax_t	ft_simax(const int array[const], const size_t length)
{
	intmax_t	max;
	size_t		i;

	max = 1;
	i = 0;
	while (i < length)
	{
		if (array[i] > max)
			max = array[i];
		++i;
	}
	return (max);
}

uintmax_t	ft_umax(const uintmax_t array[const], const size_t length)
{
	uintmax_t	max;
	size_t		i;

	max = 1;
	i = 0;
	while (i < length)
	{
		if (array[i] > max)
			max = array[i];
		++i;
	}
	return (max);
}

struct s_umaxvo	ft_umaxvo(const uintmax_t array[const], const size_t length)
{
	size_t	greatest_offset;
	size_t	i;

	greatest_offset = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] > array[greatest_offset])
			greatest_offset = i;
		++i;
	}
	return ((struct s_umaxvo)
		{.value = array[greatest_offset], .offset = greatest_offset});
}

size_t	ft_umaxo(const uintmax_t array[const], const size_t length)
{
	size_t	grandest_offset;
	size_t	i;

	grandest_offset = 0;
	i = 1;
	while (i < length)
	{
		if (array[i] > array[grandest_offset])
			grandest_offset = i;
		++i;
	}
	return (grandest_offset);
}
