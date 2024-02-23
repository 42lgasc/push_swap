/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 21:32:01 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/22 12:26:59 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"
#include "bonus.h"

void	ft_ncklstswap_int(t_int_node **a, t_int_node **b);

///The shape and length of the chain(s) are preserved.
///TODO: Cases #3 and #4 are implementable. (Cases #1 and #2 are no-op.)
//__attribute__ ((nonnull))
char	ft_lstswap_int(t_int_node **const a, t_int_node **const b)
{
	t_int_node	*temp;

	if (*a == NULL)
		return (1);
	if (*b == NULL)
		return (2);
	if ((**a).next == *a)
		return (3);
	if ((**b).next == *b)
		return (4);
	if ((**a).next == *b && (**b).next == *a)
		return (ft_ncklstswap_int(a, b), 0);
	if ((**a).next == *b)
	{
		temp = *b;
		(**a).next = (**b).next;
		temp->next = *a;
		*a = temp;
		return (0);
	}
	if ((**b).next == *a)
		return (ft_lstswap_int(b, a), 0);
	ft_ncklstswap_int(&(**a).next, &(**b).next);
	ft_ncklstswap_int(a, b);
	return (0);
}

///By 'nck' is meant "unchecked";
//	this function is naive and may scar or break chains if used carelessly.
__attribute__ ((nonnull))
void	ft_ncklstswap_int(t_int_node **const a, t_int_node **const b)
{
	t_int_node *const	temp = *a;

	*a = *b;
	*b = temp;
}
