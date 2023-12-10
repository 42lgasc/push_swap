/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:40:37 by lgasc             #+#    #+#             */
/*   Updated: 2023/10/24 12:15:49 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	count_subtrings(
						const char *const superstring,
						const char delimiter);
static unsigned int	allocate_substrings(
						const char *const whole,
						const char delimiter,
						char **const array);
static void			set_substrings(
						const char *const whole,
						const char delimiter,
						char *const *const array);

///Allocates (with `malloc`(3)) and returns an array of strings obtained by
///	splitting the `whole` using a `delimiter` character.
///The array must end with a `NULL` pointer.
///
///Leading and trailing delimiters are skup;
///There will be no empty string (`""`) in the returned array.
///
///@param[in] whole The string to be split.
///@param[in] delimiter The delimiter character.
///
///@returns The array of new strings resulting from the split.
///	`NULL` if the allocation fails.
///
///@remarks External functions: `malloc`, `free`
char	**ft_split(char const *whole, char delimiter)
{
	char			**split;
	unsigned int	error;
	unsigned int	i;

	if (! whole)
		return (NULL);
	split = ft_calloc(count_subtrings(whole, delimiter) + 1, sizeof * split);
	if (! split)
		return (NULL);
	split[count_subtrings(whole, delimiter)] = NULL;
	error = allocate_substrings(whole, delimiter, split);
	if (error)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
		return (NULL);
	}
	set_substrings(whole, delimiter, split);
	return (split);
}

static unsigned int	count_subtrings(
	const char *const superstring, const char delimiter)
{
	unsigned int	i;
	unsigned char	in_substring;
	unsigned int	substring_count;

	i = 0;
	in_substring = 0;
	substring_count = 0;
	while (superstring[i])
	{
		if (in_substring && superstring[i] == delimiter)
			in_substring = 0;
		else if (! in_substring && superstring[i] != delimiter)
		{
			in_substring = 1;
			substring_count++;
		}
		i++;
	}
	return (substring_count);
}

/** @returns An error code: 0 means no errors; 1 means allocation error. */
static unsigned int	allocate_substrings(
	const char *const whole, const char delimiter, char **const array)
{
	unsigned int	i;
	unsigned char	is_at_a_delimiter;
	unsigned int	sub_index;
	unsigned int	sub_length;

	i = 0;
	is_at_a_delimiter = 1;
	sub_index = 0;
	while (whole[i])
	{
		if (! is_at_a_delimiter && whole[i] == delimiter)
			is_at_a_delimiter = 1;
		else if (is_at_a_delimiter && whole[i] != delimiter)
		{
			sub_length = 0;
			while (whole[i + sub_length] && whole[i + sub_length] != delimiter)
				sub_length++;
			array[sub_index] = ft_calloc(sub_length + 1, sizeof * *array);
			if (! array[sub_index++])
				return (1);
			is_at_a_delimiter = 0;
		}
		i++;
	}
	return (0);
}

void	set_substrings(
	const char *const whole, const char delimiter, char *const *const split)
{
	unsigned int	i;
	unsigned char	in_substring;
	unsigned int	substring_index;
	unsigned int	j;

	i = 0;
	in_substring = 0;
	substring_index = 0;
	while (whole[i])
	{
		if (in_substring && whole[i] == delimiter)
			in_substring = 0;
		else if ((! in_substring) && whole[i] != delimiter)
		{
			j = 0;
			while (whole[i + j] && whole[i + j] != delimiter)
			{
				split[substring_index][j] = whole[i + j];
				j++;
			}
			split[substring_index++][j] = '\0';
			in_substring++;
		}
		i++;
	}
}
