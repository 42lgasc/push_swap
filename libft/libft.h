/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <lgasc@students.42perpignan.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:44 by lgasc             #+#    #+#             */
/*   Updated: 2024/01/10 19:20:38 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <errno.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// > You must write your own function implementing the following original ones.
// > They do not require any external functions:

int							ft_isalpha(int character)
							__attribute__ ((warn_unused_result));
int							ft_isdigit(int character)
							__attribute__ ((warn_unused_result));
int							ft_isalnum(int character)
							__attribute__ ((warn_unused_result));
int							ft_isascii(int character)
							__attribute__ ((warn_unused_result));
int							ft_isprint(int character)
							__attribute__ ((warn_unused_result));
size_t						ft_strlen(const char *string)
							__attribute__ ((warn_unused_result));
void						*ft_memset(void *s, int c, size_t n)
							__attribute__ ((warn_unused_result));
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(
								void *destination, const void *source, size_t n)
							__attribute__ ((warn_unused_result));
void						*ft_memmove(void *destination,
								const void *source, size_t n);
size_t						ft_strlcpy(char *destination,
								const char *source, size_t buffer_size)
							__attribute__ ((warn_unused_result));
size_t						ft_strlcat(char *destination,
								const char *source, size_t buffer_size)
							__attribute__ ((warn_unused_result));
int							ft_toupper(int character)
							__attribute__ ((warn_unused_result));
int							ft_tolower(int character)
							__attribute__ ((warn_unused_result));
char						*ft_strchr(const char *string, int character)
							__attribute__ ((warn_unused_result));
char						*ft_strrchr(const char *string, int character)
							__attribute__ ((warn_unused_result));
int							ft_strncmp(const char *string1, const char *string2,
								size_t n) __attribute__ ((warn_unused_result));
void						*ft_memchr(
								const void *s, int character, size_t length)
							__attribute__ ((warn_unused_result));
int							ft_memcmp(const void *string1,
								const void *string2, size_t n)
							__attribute__ ((warn_unused_result));
char						*ft_strnstr(const char *big,
								const char *little, size_t length)
							__attribute__ ((warn_unused_result));
int							ft_atoi(const char *string)
							__attribute__ ((warn_unused_result));

// > In order to implement the two following functions, you will use `malloc()`:

void						*ft_calloc(size_t member_amount,
								size_t member_size)
							__attribute__ ((warn_unused_result));
char						*ft_strdup(const char *original)
							__attribute__ ((warn_unused_result));

// > In this second part, you must develop a set of functions that are either
// > 	not in the libc, or that are part of it but in a different form.

char						*ft_substr(const char *superstring,
								size_t start, size_t length)
							__attribute__ ((warn_unused_result));
char						*ft_strjoin(const char *start, char const *end)
							__attribute__ ((warn_unused_result));
char						*ft_strtrim(const char *scruffy, char const *blade)
							__attribute__ ((warn_unused_result));
char						**ft_split(const char *whole, char delimiter)
							__attribute__ ((warn_unused_result));
char						*ft_itoa(int integer)
							__attribute__ ((warn_unused_result));
char						*ft_strmapi(const char *original,
								char (*action)(size_t offset, char character))
							__attribute__ ((warn_unused_result));
void						ft_striteri(char *string,
								void (*action)(size_t offset, char *character));
void						ft_putchar_fd(char character, int file_descriptor);
void						ft_putstr_fd(char *string, int file_descriptor);
void						ft_putendl_fd(char *string, int file_descriptor);
void						ft_putnbr_fd(int integer, int file_descriptor);

//static char *(*const	ft_concatenate)(const char *start, const char *end)
//	= ft_strjoin;
//# define ft_concatenate ft_strjoin
struct s_atoi_result		ft_try_atoi(const char string[])
							__attribute__ ((warn_unused_result));

enum e_result_type
{
	Ok = 0,
	Error = 1
};

enum e_atoi_error
{
	NullString,
	NonNumeric,
	BeyondLimits
};

# ifndef __clang__
#  ifdef TEST

struct __attribute__ ((designated_init)) s_atoi_result
{
	enum e_result_type	type;
	union
	{
		int					ok;
		enum e_atoi_error	error;
	};
};
#   define S_ATOI_RESULT
#  endif
# endif
# ifndef S_ATOI_RESULT

struct s_atoi_result
{
	enum e_result_type	type;
	union
	{
		int					ok;
		enum e_atoi_error	error;
	};
};
# endif

unsigned char				ft_isspace(char character)
							__attribute__ ((warn_unused_result));
void						ft_umaxo(
								const unsigned int integers[], size_t length)
							;//__attribute_warn_unused_result__;
unsigned long				ft_ulmaxo(
								const unsigned long array[], size_t length)
							__attribute__ ((warn_unused_result));
size_t						ft_zmaxo(const size_t array[], size_t length)
							__attribute__ ((warn_unused_result));
struct s_max_result
{
	enum e_result_type	type;
	union
	{
		size_t			ok;
		unsigned char	error;
	};
}							ft_try_zmaxo(const size_t array[], size_t length)
							__attribute__ ((warn_unused_result));

/*~~ ~ -  BONUS - ~ ~~*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list						*ft_lstnew(void *content)
							__attribute__ ((warn_unused_result));
void						ft_lstadd_front(t_list **list, t_list *addition);
int							ft_lstsize(t_list *list)
							__attribute__ ((warn_unused_result));
t_list						*ft_lstlast(t_list *list)
							__attribute__ ((warn_unused_result));
void						ft_lstadd_back(t_list **list, t_list *addition);
void						ft_lstdelone(
								t_list *node, void (*deleter)(void *content));
void						ft_lstclear(
								t_list **node, void (*deleter)(void *content));
void						ft_lstiter(
								t_list *list, void (*function)(void *content));
t_list						*ft_lstmap(
								t_list *list, void *(*function)(void *content),
								void (*deleter)(void *content))
							__attribute__ ((warn_unused_result));

#endif
