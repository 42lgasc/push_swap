/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:47:42 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 10:29:16 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "bonus_types.h"

// ///
// ~~ ~ -  BONUS

t_node	*ft_lstnew(void *datum)__attribute__ ((warn_unused_result));
void	ft_lstadd_front(t_list *list, t_node *node) __attribute__ ((nonnull));
size_t	ft_lstsize(t_list list) __attribute__ ((warn_unused_result));
t_list	ft_lstlast(t_list list) __attribute__ ((warn_unused_result));
void	ft_lstadd_back(t_list *list, t_node *node) __attribute__ ((nonnull));
void	ft_lstdelone(t_node **node, void (*deleter)(const void *datum))
		__attribute__ ((nonnull));
void	ft_lstclear(t_list *list, void (deleter)(const void *datum))
		__attribute__ ((nonnull));
void	ft_lstiter(t_list list, void (*action)(const void *const datum))
		__attribute__ ((nonnull));
t_list	ft_lstmap(t_list list, void *(*mapper)(const void *const datum),
			void (*deleter)(const void *const datum))
		__attribute__ ((nonnull)) __attribute__ ((warn_unused_result));

// ///
// My personnal add-ons

void	ft_lstrot(t_list *list);
void	ft_lstrrot(t_list *list);
t_node	*ft_lstplast(t_list list)
		__attribute__ ((warn_unused_result)) __attribute__ ((nonnull));
t_node	*ft_lstget(t_list list, size_t offset)
		__attribute__ ((warn_unused_result));

//\///Not defined yet, I am reserving this name for later kernel-related use.
//typedef void		t_inode;
// Nevermind ~~lgasc 2024-02-22T21:01

t_inode	*ft_ilstnew(int datum) __attribute__ ((warn_unused_result));
t_znode	*ft_zlstnew(size_t inner);
t_zlist	ft_zlstlast(t_zlist list);
size_t	ft_ilstsize(t_ilist list)__attribute__ ((warn_unused_result));
t_ilist	ft_ilstlast(t_ilist list)__attribute__ ((warn_unused_result));
void	ft_ilstadd_back(t_ilist *list, t_inode *node)
		__attribute__ ((nonnull));
void	ft_zlstadd_back(t_zlist *list, t_znode *node);
void	ft_ilstclear(t_ilist *list) __attribute__ ((nonnull));
void	ft_zlstclear(t_zlist *list);
void	ft_ilstrot(t_ilist *list);
void	ft_ilstrrot(t_ilist *list);
t_inode	*ft_ilstplast(t_ilist list)
		__attribute__ ((warn_unused_result)) __attribute__ ((nonnull));
t_inode	*ft_ilstget(t_ilist list, size_t offset)
		__attribute__ ((warn_unused_result));
t_znode	*ft_zlstget(t_zlist, size_t offset);
t_ilist	ft_ilstclone(t_ilist list);
char	ft_ilstswap(t_inode **a, t_inode **b);
#endif
