/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:04:28 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/30 16:43:15 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

# include "libft/libft.h"

int	ft_printf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));
int	ft_print_if(int condition, const char string[]);

#endif
