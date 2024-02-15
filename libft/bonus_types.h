/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:00:31 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 17:01:13 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_TYPES_H
# define BONUS_TYPES_H

// Indeed, `clang` seems to support no attribute...
# ifndef __clang__
#  ifdef TEST

typedef struct __attribute__ ((designated_init)) s_node
{
	void			*datum;
	struct s_node	*next;
}	t_node;
typedef t_node		*t_list;

typedef struct __attribute__ ((designated_init)) s_int_node
{
	int					datum;
	struct s_int_node	*next;
}	t_int_node;
typedef t_int_node	*t_int_list;
#   define BONUS_H_ATTRIBUTES
#  endif
# endif
# ifndef BONUS_H_ATTRIBUTES

typedef struct s_node
{
	void			*datum;
	struct s_node	*next;
}	t_node;
typedef t_node		*t_list;

typedef struct s_int_node
{
	int					datum;
	struct s_int_node	*next;
}	t_int_node;
typedef t_int_node	*t_int_list;
# endif

#endif
