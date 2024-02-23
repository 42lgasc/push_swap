/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:09:49 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/15 21:41:17 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "libft/libft.h"

# include "push_swap_types.h"

void				ft_print_stacks(struct s_stacks stacks);

struct s_int_option	ft_primary_top(struct s_stacks stacks)
					__attribute__ ((warn_unused_result));
struct s_int_option	ft_primary_next(struct s_stacks stacks)
					__attribute__ ((warn_unused_result));
struct s_int_option	ft_primary_bottom(struct s_stacks stacks)
					__attribute__ ((warn_unused_result));
struct s_int_option	ft_secondary_top(struct s_stacks stacks)
					__attribute__ ((warn_unused_result));
struct s_int_option	ft_secondary_next(struct s_stacks stacks)
					__attribute__ ((warn_unused_result));
struct s_int_option	ft_secondary_bottom(struct s_stacks stacks)
					__attribute__ ((warn_unused_result));

#endif
