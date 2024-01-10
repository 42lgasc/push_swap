# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgasc <lgasc@students.42perpignan.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:30:49 by lgasc             #+#    #+#              #
#    Updated: 2024/01/10 17:07:02 by lgasc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# #### ### ## #  === == =  ~~ ~  - VARIABLES= -  ~ ~~  = == ===  # ## ### #### #

NAME = libft.a

# Special variables
#CC = gcc
#DEBUG_FLAG = -g
CFLAGS += -Wall -Wextra -Werror $(DEBUG_FLAG)

#INCLUDES = libft.h

SOURCES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c \
		ft_strncmp.c ft_memcmp.c \
		ft_strchr.c ft_strrchr.c ft_memchr.c ft_strnstr.c \
		ft_atoi.c \
	ft_calloc.c \
		ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c \
		ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_isspace.c ft_max.c

OBJECTS = $(SOURCES:.c=.o)


# #### ### ## #  === == =  ~~ ~  -  recipes:  -  ~ ~~  = == ===  # ## ### #### #
.PHONY: all clean fclean re bclean bonus

$(NAME): all ;

all: $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean bclean ;

re: fclean all ;

bclean:
	$(RM) $(NAME)

# The implicit "`.o` from `.c`" rule is used instead.
#$(OBJECTS): $(SOURCE:OBJECTS:.o=.c)
#	cc $(FLAGS) -c $(@:.o=.c) -o $@



# #### ### ## #  === == =  ~~ ~  -   Bonus!   -  ~ ~~  = == ===  # ## ### #### #

BONUS_SOURCES = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)


bonus: $(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)
