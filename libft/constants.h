/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:39:33 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 17:47:21 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# ifdef TODO

"Whomst defined it already?!": TODO;
# else
#  define TODO 0x70D0
# endif

enum e_result_type
{
	Ok = 0,
	Error = 1
};

enum e_option_type
{
	None,
	Some
};

#endif
