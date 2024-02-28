/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:51:38 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 17:10:39 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

#include "libft/libft.h"

#include "ft_printf.h"
#include "ft_printf_conversion.h"
#include "ft_printf_utils.h"
//#include "print_misc.h"

void	ft_print_int_list(const t_ilist list)
{
	const char		prefix[] = "(t_ilist)";
	ssize_t			length;
	const t_inode	*node;

	length = (ft_putstr_fd(prefix, 1), (signed)ft_strlen(prefix));
	(ft_putchar_fd('[', 1), ++length);
	node = list;
	while (node != NULL)
	{
		length += ft_handler(ft_print_pointer(node), &length) << 1 & 1;
		ft_putstr_fd(": ", 1);
		if (length >= 0)
			length += 2;
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
void	ft_debug_array(const t_int_array array)
{
	const char	prefix[] = "(t_int_array)";
	size_t		i;

	ft_putstr_fd(prefix, 2);
	ft_putchar_fd('[', 2);
	i = 0;
	while (i < array->length)
		if (ft_putnbr_fd(array->ints[i], 2), ++i < array->length)
			ft_putstr_fd(", ", 2);
	ft_putendl_fd("]", 2);
}
