/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:55:03 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 17:36:18 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdarg.h>
# include <stddef.h>
//# include <stdint.h>
//# include <unistd.h>

ssize_t			ft_select_conversion(const unsigned char specifier,
					va_list *const argument_pointer, ssize_t *const code,
					ssize_t *const length) __attribute__ ((warn_unused_result));
//ssize_t			ft_print_small_hexadecimal(const unsigned int number)
//				__attribute__ ((warn_unused_result));
//ssize_t			ft_print_capital_hexadecimal(const unsigned int number)
//				__attribute__ ((warn_unused_result));
//ssize_t			ft_print_percent_sign(void)
//				__attribute__ ((warn_unused_result));
ssize_t			ft_handler(const ssize_t code, ssize_t *const length)
				__attribute__ ((warn_unused_result));

#endif
