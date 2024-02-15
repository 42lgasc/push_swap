/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:39:23 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 20:53:13 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

# include <stddef.h>

# include "constants.h"

// Indeed, `clang` seems to support no attribute...
# ifndef __clang__
#  ifdef TEST

typedef struct __attribute__ ((designated_init)) s_int_array
{
	size_t	length;
	int		ints[];
}	*t_int_array;
///TODO: Settle on a typedef name.
typedef t_int_array	t_iarr;

typedef struct __attribute__ ((designated_init)) s_int_option
{
	enum e_option_type	type;
	int					value;
}	t_int_option;
#   define LIBFT_TYPES_H_ATTRIBUTES
#  endif
# endif
# ifndef LIBFT_TYPES_H_ATTRIBUTES

typedef struct s_int_array
{
	size_t	length;
	int		ints[];
}	*t_int_array;
///TODO: Settle on a typedef name.
typedef t_int_array	t_iarr;

typedef struct s_int_option
{
	enum e_option_type	type;
	int					value;
}	t_int_option;
# endif

#endif
