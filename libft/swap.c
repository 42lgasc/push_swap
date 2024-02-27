/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:17:25 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 11:22:59 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!@see `ft_lstswap.c`

__attribute__ ((nonnull))
void	ft_ipswap(const int **const a, const int **const b)
{
	const int *const	temp = *a;

	*a = *b;
	*b = temp;
}
