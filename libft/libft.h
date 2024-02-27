/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:44 by lgasc             #+#    #+#             */
/*   Updated: 2024/02/27 11:05:03 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// ///
// TODO: Split into yet another header file.

//# include "common.h"
# include "ft_atoi.h"
# include "bonus.h"

# include "max.h"

// ///
// > You must write your own function implementing the following original ones.
// > They do not require any external functions:

int				ft_isalpha(int character) __attribute__ ((warn_unused_result));
int				ft_isdigit(int character) __attribute__ ((warn_unused_result));
int				ft_isalnum(int character) __attribute__ ((warn_unused_result));
int				ft_isascii(int character) __attribute__ ((warn_unused_result));
int				ft_isprint(int character) __attribute__ ((warn_unused_result));
size_t			ft_strlen(const char *string)
				__attribute__ ((warn_unused_result));
void			*ft_memset(void *start, int character, size_t size);
void			ft_bzero(void *start, size_t size);
void			*ft_memcpy(void *destination, const void *source, size_t n)
				__attribute__ ((warn_unused_result));
void			*ft_memmove(void *destination, const void *source, size_t n);
size_t			ft_strlcpy(char *destination, const char *source, size_t total)
				__attribute__ ((warn_unused_result));
size_t			ft_strlcat(char *destination, const char *source, size_t total)
				__attribute__ ((warn_unused_result));
int				ft_toupper(int character) __attribute__ ((warn_unused_result));
int				ft_tolower(int character) __attribute__ ((warn_unused_result));
char			*ft_strchr(const char *string, int character)
				__attribute__ ((warn_unused_result));
char			*ft_strrchr(const char *string, int character)
				__attribute__ ((warn_unused_result));
int				ft_strncmp(const char *string1, const char *string2, size_t n)
				__attribute__ ((warn_unused_result));
void			*ft_memchr(const void *s, int character, size_t length)
				__attribute__ ((warn_unused_result));
int				ft_memcmp(const void *string1, const void *string2, size_t n)
				__attribute__ ((warn_unused_result));
char			*ft_strnstr(const char *big, const char *little, size_t length)
				__attribute__ ((warn_unused_result));
int				ft_atoi(const char *string)__attribute__ ((warn_unused_result));

// ///
// > In order to implement the two following functions, you will use `malloc()`:

void			*ft_calloc(size_t member_amount, size_t member_size)
				__attribute__ ((warn_unused_result));
char			*ft_strdup(const char *original)
				__attribute__ ((warn_unused_result));

// ///
// > In this second part, you must develop a set of functions that are either
// > 	not in the libc, or that are part of it but in a different form.

char			*ft_substr(const char *superstring, size_t start, size_t length)
				__attribute__ ((warn_unused_result));
char			*ft_strjoin(const char *start, char const *end)
				__attribute__ ((warn_unused_result));
char			*ft_strtrim(const char *scruffy, char const *blade)
				__attribute__ ((warn_unused_result));
char			**ft_split(const char *whole, char delimiter)
				__attribute__ ((warn_unused_result));
char			*ft_itoa(int integer) __attribute__ ((warn_unused_result));
char			*ft_strmapi(const char *original,
					char (*action)(size_t offset, char character))
				__attribute__ ((warn_unused_result));
void			ft_striteri(char *string,
					void (*action)(size_t offset, char *character));
void			ft_putchar_fd(const char character, int file_descriptor);
void			ft_putstr_fd(const char *string, int file_descriptor)
				__attribute__ ((nonnull));
void			ft_putendl_fd(const char *string, int file_descriptor)
				__attribute__ ((nonnull));
void			ft_putnbr_fd(int integer, int file_descriptor);

// ///
// My personnal add-ons

//static char *(*const	ft_concatenate)(const char *start, const char *end)
//	= ft_strjoin;
//# define ft_concatenate ft_strjoin

t_atoi_result	ft_try_atoi(const char string[])
				__attribute__ ((warn_unused_result));
unsigned char	ft_isspace(char character)
				__attribute__ ((warn_unused_result));
typedef struct s_SIZEt_UNSIGNEDchar
{
	enum e_result_type	type;
	union
	{
		size_t			ok;
		unsigned char	error;
	};
}	t_result_sizeT_unsignedChar __attribute__ ((deprecated));
//typedef t_result_sizeT_unsignedChar	t_result_z_uc;
//typedef t_result_z_uc	t_res_z_uc;
//typedef t_res_z_uc	t_reszuc;
//typedef t_res_z_uc	t_rzuc;

void			ft_swap_intptr(const int **a, const int **b);
int				*ft_intarrint(t_int_array array, int integer);
size_t			ft_zmin(size_t a, size_t b);
#endif
