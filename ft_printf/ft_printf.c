/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:44:17 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/14 17:37:10 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/types.h"

//#include "ft_printf.h"
#include "ft_printf_conversion.h"
#include "ft_printf_utils.h"

// TODO: Support these conversions: cspdiuxX%

extern void		*malloc(const size_t size) __attribute__ ((warn_unused_result));
extern void		free(void *const pointer);
			// Not applicable if there is no result (*v*)
			//__attribute__ ((warn_unused_result);)
extern ssize_t	write(const int file_descriptor, const void *const buffer,
					const size_t amount) __attribute__ ((warn_unused_result));

ssize_t			ft_printf_one(unsigned char *const in_percent,
					const unsigned char character,
					va_list *const argument_pointer, ssize_t *const length)
				__attribute__ ((warn_unused_result));

// If you wonder why `argument_pointer`, see
// 	https://stackoverflow.com/a/24345372/14792858

/// @returns The TODO,
/// 	-2 if the format string is a `NULL` pointer.
/// @remark External functions: `malloc`, `free`, and `write`;
/// 	External macro functions:
/// 		`va_start()`, `va_arg`, `va_copy`, and `va_end`.
__attribute__ ((format (printf, 1, 2))) __attribute__ ((warn_unused_result))
int	ft_printf(const char *format, ...)
{
	va_list			argument_pointer;
	size_t			i;
	unsigned char	in_percent;
	ssize_t			length;

	if (format == NULL)
		return (-2);
	va_start(argument_pointer, format);
	length = 0;
	i = 0;
	in_percent = 0;
	while (format[i] != '\0')
	{
		if (ft_printf_one(& in_percent, (const unsigned char) format[i],
				& argument_pointer, & length) < 0)
			return (va_end(argument_pointer), (const signed int) length);
		i++;
	}
	va_end(argument_pointer);
	if (in_percent > 0)
		return (-1);
	return ((signed int) length);
}

////////

ssize_t	ft_printf_one(unsigned char *const in_percent,
			const unsigned char character, va_list *const argument_pointer,
			ssize_t *const length)
{
	ssize_t			code;

	if (*in_percent && ft_select_conversion
		(character, argument_pointer, & code, length) < 0)
		return (code);
	else if (*in_percent && (*in_percent)--)
		*length += code;
	else if (character == '%')
		(*in_percent)++;
	else if (ft_handler(write(1, &character, 1), length) != 0)
		return (*length);
	return (*length);
}

////////

ssize_t	ft_select_conversion(const unsigned char specifier,
			va_list *const argument_pointer, ssize_t *const code,
			ssize_t *const length)
{
	if (specifier == 'c')
		*code = ft_print_character
			((const unsigned char) va_arg(*argument_pointer, unsigned int));
	else if (specifier == 's')
		*code = ft_print_string(va_arg(*argument_pointer, const char *const));
	else if (specifier == 'p')
		*code = ft_print_pointer(va_arg(*argument_pointer, const void *const));
	else if ((specifier == 'd' || specifier == 'i'))
		*code = ft_print_integer(va_arg(*argument_pointer, const signed int));
	else if (specifier == 'u')
		*code = ft_print_unsigned_integer(va_arg(*argument_pointer, unsigned));
	else if (specifier == 'x' || specifier == 'X')
		*code = ft_print_hexadecimal
			(va_arg(*argument_pointer, const unsigned int), specifier == 'x');
	else if (specifier == '%')
		*code = ft_print_character('%');
	else
	{
		if (ft_handler(ft_print_character('%'), length) != 0)
			return (*length);
		*code = ft_print_character(specifier);
	}
	return (*code);
}

struct s_int_option	ft_print_if(const int condition, const char string[const])
{
	if (condition)
		return ((struct s_int_option)
			{.type = Some, .value = ft_printf("%s", string)});
	else
		return ((struct s_int_option){.type = None});
}

void	ft_print_array(void)
{
}
