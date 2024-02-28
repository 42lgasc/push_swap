/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offload.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:17:23 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/28 18:19:24 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFLOAD_H
# define OFFLOAD_H

char	ft_offload(struct s_stacks *const stacks);

///Which is better?
enum e_wib
{
	Rr,
	RaAndRrb,
	RraAndRb,
	Rrr
};
#endif
