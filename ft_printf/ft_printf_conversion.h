/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:31:08 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 17:17:51 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONVERSION_H
# define FT_PRINTF_CONVERSION_H

//# include <unistd.h>
# include <stdint.h>
# include <sys/types.h>

//# include "libft/libft.h"

ssize_t			ft_print_character(const unsigned char character)
				__attribute__ ((warn_unused_result));
ssize_t			ft_print_string(const char *const string)
				__attribute__ ((warn_unused_result));
ssize_t			ft_print_pointer(const void *const pointer)
				__attribute__ ((warn_unused_result));
ssize_t			ft_print_integer(const int number)
				__attribute__ ((warn_unused_result));
ssize_t			ft_print_unsigned_integer(const unsigned int number)
				__attribute__ ((warn_unused_result));
ssize_t			ft_print_hexadecimal(const uintptr_t number,
					const unsigned char lowercase)
				__attribute__ ((warn_unused_result));

#endif
