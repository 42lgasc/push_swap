/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:40:07 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/22 20:10:57 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_H
# define MAX_H

//# include <stddef.h>

//# include "libft.h"

enum e_max_code
{
	Max_Ok,
	NullPointer,
	NoElement
};

// Indeed, `clang` seems to support no attribute...
# ifndef __clang__
#  ifdef TEST

typedef struct __attribute__ ((designated_init)) s_max_result
{
	enum e_max_code	code;
	union
	{
		size_t	ok;
	};
}	t_max_result;
#   define MAX_H_ATTRIBUTES
#  endif
# endif
# ifndef MAX_H_ATTRIBUTES

typedef struct s_max_result
{
	enum e_max_code	code;
	union
	{
		size_t	ok;
	};
}	t_max_result;
# endif

void			ft_umaxo(const unsigned int integers[], size_t length)
				;//__attribute_warn_unused_result__;
unsigned long	ft_ulmaxo(const unsigned long array[], size_t length)
				__attribute__ ((warn_unused_result));
size_t			ft_zmaxo(const size_t array[], size_t length)
				__attribute__ ((warn_unused_result));
t_max_result	ft_try_zmaxo(const size_t array[], size_t length)
				__attribute__ ((warn_unused_result));
size_t			ft_zmax(size_t a, size_t b);
#endif
