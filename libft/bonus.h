/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:47:42 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/22 21:04:04 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "bonus_types.h"

// ///
// ~~ ~ -  BONUS

t_node		*ft_lstnew(void *datum)__attribute__ ((warn_unused_result));
void		ft_lstadd_front(t_list *list, t_node *node)
			__attribute__ ((nonnull));
size_t		ft_lstsize(t_list list) __attribute__ ((warn_unused_result));
t_list		ft_lstlast(t_list list) __attribute__ ((warn_unused_result));
void		ft_lstadd_back(t_list *list, t_node *node)
			__attribute__ ((nonnull));
void		ft_lstdelone(t_node **node, void (*deleter)(const void *datum))
			__attribute__ ((nonnull));
void		ft_lstclear(t_list *list, void (deleter)(const void *datum))
			__attribute__ ((nonnull));
void		ft_lstiter(t_list list, void (*action)(const void *const datum))
			__attribute__ ((nonnull));
t_list		ft_lstmap(t_list list, void *(*mapper)(const void *const datum),
				void (*deleter)(const void *const datum))
			__attribute__ ((nonnull)) __attribute__ ((warn_unused_result));

// ///
// My personnal add-ons

void		ft_lstrot(t_list *list);
void		ft_lstrrot(t_list *list);
t_node		*ft_lstplast(t_list list)
			__attribute__ ((warn_unused_result)) __attribute__ ((nonnull));
t_node		*ft_lstget(t_list list, size_t offset)
			__attribute__ ((warn_unused_result));

//\///Not defined yet, I am reserving this name for later kernel-related use.
//typedef void		t_inode;
// Nevermind ~~lgasc 2024-02-22T21:01

t_int_node	*ft_lstnew_int(int datum) __attribute__ ((warn_unused_result));
t_znode		*ft_zlstnew(size_t inner);
t_zlist		ft_zlstlast(t_zlist list);
size_t		ft_lstsize_int(t_int_list list)__attribute__ ((warn_unused_result));
t_int_list	ft_lstlast_int(t_int_list list)__attribute__ ((warn_unused_result));
void		ft_lstadd_back_int(t_int_list *list, t_int_node *node)
			__attribute__ ((nonnull));
void		ft_zlstadd_back(t_zlist *list, t_znode *node);
void		ft_lstclear_int(t_int_list *list) __attribute__ ((nonnull));
void		ft_zlstclear(t_zlist *list);
void		ft_lstrot_int(t_int_list *list);
void		ft_lstrrot_int(t_int_list *list);
t_int_node	*ft_lstplast_int(t_int_list list)
			__attribute__ ((warn_unused_result)) __attribute__ ((nonnull));
t_int_node	*ft_lstget_int(t_int_list list, size_t offset)
			__attribute__ ((warn_unused_result));
t_znode		*ft_zlstget(t_zlist, size_t offset);
t_int_list	ft_lstclone_int(t_int_list list);
char		ft_lstswap_int(t_int_node **a, t_int_node **b);
#endif
