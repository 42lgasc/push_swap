/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:07:56 by lgasc             #+#    #+#             */
/*   Updated: 2023/11/17 17:53:01 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	locate_trim(const char *const scruffy, const char *const blade,
				unsigned int *const start, size_t *const end);

static void	hydrate_trim(const char *const scruffy,
				unsigned int start, size_t end, char *const trim);

///# Allocates (with `malloc`) and returns a copy of
///`scruffy` with the characters specified in `blade`
///removed from the beginning and the end of the string.
///## Params
///@param[in] `scruffy` The string to be trimmed.
///@param[in] `blade` The reference set of characters to trim.
///## Return
///@returns The trimmed string. NULL if the allocation fails.
///## Note
///@remarks External function: `malloc`
char	*ft_strtrim(char const *scruffy, char const *blade)
{
	unsigned int	start;
	size_t			end;
	char			*trim;

	if (! scruffy)
		return (NULL);
	if (! blade)
		return (ft_strdup(scruffy));
	locate_trim(scruffy, blade, &start, &end);
	trim = ft_calloc(2 + end - start, sizeof * trim);
	if (trim == NULL)
		return (NULL);
	hydrate_trim(scruffy, start, end, trim);
	return (trim);
}

/**
 * @param[in] scruffy
 * @param[in] blade
 * @param[out] start
 * @param[out] end
 */
static void	locate_trim(const char *const scruffy, const char *const blade,
				unsigned int *const start, size_t *const end)
{
	*start = 0;
	while (ft_strchr(blade, scruffy[*start]) && *start <= ft_strlen(scruffy))
		(*start)++;
	*end = ft_strlen(scruffy);
	while (*start < *end && ft_strchr(blade, scruffy[*end]))
		(*end)--;
}

/**
 * @param[in] scruffy
 * @param[in] start
 * @param[in] end
 * @param[out] trim
 */
static void	hydrate_trim(const char *const scruffy, const unsigned int start,
				size_t end, char *const trim)
{
	unsigned int	i;

	i = 0;
	while (start + i <= end)
	{
		trim[i] = scruffy[start + i];
		i++;
	}
	trim[i] = '\0';
}
