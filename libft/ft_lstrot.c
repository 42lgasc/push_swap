/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:49:57 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 11:16:13 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///Move the first node to the end of the `list`

// (source) {destination} [result]

// list (-> A)  -> B  -> C  --x0      ; top {####}
// list {-> A} (-> B) -> C  --x0      ; top [-> A]  ...
// list [--------> B] -> C  --x0      ; top  -> A  {-> B} ...
// list  --------> B  -> C {--x0}     ; top (-> A) [--x0]
// list  --------> B  -> C [-> A] --x0; top  -> A   ...

// list (-> A)  -> B   --x0      ; top {####}
// list {-> A} (-> B)  --x0      ; top [-> A]  ...
// list [--------> B]  --x0      ; top  -> A  {-> B} ...
// list  --------> B  {--x0}     ; top (-> A) [--x0]
// list  --------> B  [-> A] --x0; top  -> A   ...

// list (-> A)  --x0 ; top {####}
// list {-> A} (--x0); top [-> A]  ...
// list [--x0]       ; top  -> A  {--x0}
// list {--x0}       ; top (-> A) [--x0]
// list [-> A]  --x0 ; top  -> A   ...

// list (--x0)       ; top {####}
// list {--x0} (--!!); top [--x0]
// list [--!!]       ; top  --x0  {--!!}
// list  --!!  {--!!}; top (--x0) [--x0]
// list  --!!  [--x0]; top  --x0
void	ft_lstrot(t_list *const list)
{
	t_node *const	top = *list;
	t_node *const	last = ft_lstlast(*list);

	if (top == NULL)
		return ;
	*list = top->next;
	top->next = NULL;
	last->next = top;
}

///Move the last node to the start of the `list`
void	ft_lstrrot(t_list *const list)
{
	t_node *const	last = ft_lstlast(*list);
	t_node *const	pre_last = ft_lstplast(*list);

	if (pre_last == NULL)
		return ;
	pre_last->next = NULL;
	last->next = *list;
	*list = last;
}

void	ft_ilstrot(t_ilist *const list)
{
	t_inode *const	top = *list;
	t_inode *const	last = ft_ilstlast(*list);

	if (top == NULL)
		return ;
	*list = top->next;
	top->next = NULL;
	last->next = top;
}

///Move the last node to the start of the `list`
void	ft_ilstrrot(t_ilist *const list)
{
	t_inode *const	last = ft_ilstlast(*list);
	t_inode *const	pre_last = ft_ilstplast(*list);

	if (pre_last == NULL)
		return ;
	pre_last->next = NULL;
	last->next = *list;
	*list = last;
}
