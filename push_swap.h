/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:06:10 by lgasc             #+#    #+#             */
/*   Updated: 2023/12/06 20:15:04 by lgasc            ###   ########.fr       */
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

void	gnome_sort(int*destination, int*source);

#endif
