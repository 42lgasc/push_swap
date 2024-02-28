/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:12:32 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/28 17:30:11 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft/bonus.h"

__attribute__ ((nonnull)) __attribute__ ((warn_unused_result))
///TODO: Remove call to `ft_lstget`
size_t	ft_waxing_aim(const t_ilist list, const int arrow)
{
	size_t	aim;

	if (list->datum < ft_ilstlast(list)->datum
		&& (arrow < list->datum || ft_ilstlast(list)->datum < arrow))
		return (0);
	if (ft_ilstlast(list)->datum < arrow && arrow < list->datum)
		return (0);
	aim = 0;
	while (arrow < ft_ilstget(list, aim)->datum)
		if (ft_ilstget(list, aim)->datum
			> ft_ilstget(list, aim + 1)->datum
			&& arrow < ft_ilstget(list, aim + 1)->datum)
			return (aim + 1);
	else
		++aim;
	while (1)
		if ((ft_ilstget(list, aim)->datum
				> ft_ilstget(list, aim + 1)->datum)
			^ (arrow < ft_ilstget(list, aim + 1)->datum))
			return (aim + 1);
	else
		++aim;
}

__attribute__ ((nonnull)) __attribute__ ((warn_unused_result))
///TODO: Remove call to `ft_lstget`
size_t	ft_waning_aim(const t_ilist list, const int arrow)
{
	size_t	aim;

	if (list->datum > ft_ilstlast(list)->datum
		&& (arrow > list->datum || ft_ilstlast(list)->datum > arrow))
		return (0);
	if (ft_ilstlast(list)->datum > arrow && arrow > list->datum)
		return (0);
	aim = 0;
	while (arrow > ft_ilstget(list, aim)->datum)
		if (ft_ilstget(list, aim)->datum
			< ft_ilstget(list, aim + 1)->datum
			&& arrow > ft_ilstget(list, aim + 1)->datum)
			return (aim + 1);
	else
		++aim;
	while (1)
		if ((ft_ilstget(list, aim)->datum
				< ft_ilstget(list, aim + 1)->datum)
			^ (arrow > ft_ilstget(list, aim + 1)->datum))
			return (aim + 1);
	else
		++aim;
}
