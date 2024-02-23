/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:00:31 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/22 21:10:07 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_TYPES_H
# define BONUS_TYPES_H

# include <stddef.h>

// Indeed, `clang` seems to support no attribute...
# ifndef __clang__
#  ifdef TEST

typedef struct __attribute__ ((designated_init)) s_node
{
	void			*datum;
	struct s_node	*next;
}	t_node;
typedef t_node		*t_list;

///TODO: Rename to `s_intnode`, `t_intnode`, and `t_intlist`
typedef struct __attribute__ ((designated_init)) s_int_node
{
	int					datum;
	struct s_int_node	*next;
}	t_int_node;
typedef t_int_node	*t_int_list;

typedef struct __attribute__ ((designated_init)) s_znode
{
	size_t			inner;
	struct s_znode	*next;
}	t_znode;
typedef t_znode		*t_zlist;
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

typedef struct s_znode
{
	size_t			inner;
	struct s_znode	*next;
}	t_znode;
typedef t_znode		*t_zlist;
# endif

#endif
