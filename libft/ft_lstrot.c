/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:49:57 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/09 19:22:23 by lgasc            ###   ########.fr       */
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

void	ft_lstrot_int(t_int_list *const list)
{
	t_int_node *const	top = *list;
	t_int_node *const	last = ft_lstlast_int(*list);

	if (top == NULL)
		return ;
	*list = top->next;
	top->next = NULL;
	last->next = top;
}

///Move the last node to the start of the `list`
void	ft_lstrrot_int(t_int_list *const list)
{
	t_int_node *const	last = ft_lstlast_int(*list);
	t_int_node *const	pre_last = ft_lstplast_int(*list);

	if (pre_last == NULL)
		return ;
	pre_last->next = NULL;
	last->next = *list;
	*list = last;
}
