/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:06:10 by lgasc             #+#    #+#             */
/*   Updated: 2023/12/20 21:56:14 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>

# include "libft/libft.h"

struct s_stacks
{
	size_t	size;
	int		*primary;
	int		*secondary;
};

void		gnome_sort(int*destination, int*source) __attribute__ ((nonnull));
const int	*ft_lis(const int circular_buffer[], size_t length)
			__attribute__ ((nonnull)) __attribute__ ((warn_unused_result));

#endif
