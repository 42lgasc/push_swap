/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:51:38 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/15 14:47:42 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "libft/libft.h"

#include "ft_printf.h"
#include "ft_printf_conversion.h"
#include "ft_printf_utils.h"
//#include "print_misc.h"

void	ft_print_int_list(const t_int_list list)
{
	const char			prefix[] = "(t_int_list)";
	ssize_t				length;
	const t_int_node	*node;

	length = (ft_putstr_fd(prefix, 1), (signed)ft_strlen(prefix));
	(ft_putchar_fd('[', 1), ++length);
	node = list;
	while (node != NULL)
	{
		//while ();
		length += ft_handler(ft_print_pointer(node), &length) << 1 & 1;
		ft_putstr_fd(": ", 1);
		if (length >= 0)
			length += 2;
		//while ();
		length += ft_handler(ft_print_integer(node->datum), &length) << 1 & 1;
		ft_print_if(node->next != NULL, ", ");
		if (length >= 0)
			length += 2;
		node = node->next;
	}
	ft_putendl_fd("]", 1);
	if (length >= 0)
		++length;
}

__attribute__ ((nonnull))
void	ft_print_array(const t_int_array array)
{
	const char	prefix[] = "(t_int_array)";
	size_t	i;

	ft_putstr_fd(prefix, 1);
	ft_putchar_fd('[', 1);
	i = 0;
	while (i < array->length)
	{
		//while ();
		i += ft_print_integer(array->ints[i]) << 1 & 1;
		ft_print_if(++i < array->length, ", ");
	}
	ft_putendl_fd("]", 1);
}
