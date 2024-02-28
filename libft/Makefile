# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:30:49 by lgasc             #+#    #+#              #
#    Updated: 2024/02/27 21:25:46 by lgasc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# #### ### ## #  === == =  ~~ ~  - VARIABLES= -  ~ ~~  = == ===  # ## ### #### #

NAME = libft.a

# Special variables
#CC = gcc
#DEBUG_FLAG = -g
CFLAGS += -Wall -Wextra -Werror $(DEBUG_FLAG) -fpie#-fPIC#-fPIE
CLANG_FLAGS += $(CFLAGS)
GCC_FLAGS += $(CLANG_FLAGS)

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
	min.c max.c swap.c ft_isspace.c ft_arrint.c

OBJECTS = $(SOURCES:.c=.o)


# #### ### ## #  === == =  ~~ ~  -  recipes:  -  ~ ~~  = == ===  # ## ### #### #
.PHONY: all clean fclean re bclean test raw_test norm \
	bonus bonus_test raw_bonus_test ;

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
#	cc $(CFLAGS) -c $(@:.o=.c) -o $@

test: fclean
	$(MAKE) CFLAGS+=-g3 CFLAGS+=-O0 CFLAGS+='-D TEST' raw_test
	$(MAKE) fclean

raw_test: $(SOURCES)
	:     $(CC) $(CFLAGS)      \
			-D TEST $(SOURCES) --output $(NAME); \
		$(MAKE) CC='$(CC)' CFLAGS='$(CFLAGS)'      CFLAGS+='-D TEST' bonus; \
		CC_STATUS=$$?   ; \
		: clang $(CLANG_FLAGS) \
			-D TEST $(SOURCES) --output $(NAME); \
		$(MAKE) CC=clang   CFLAGS='$(CLANG_FLAGS)' CFLAGS+='-D TEST' bonus; \
		CLANG_STATUS=$$?; \
		:gcc   $(GCC_FLAGS)   \
			-D TEST $(SOURCES) --output $(NAME); \
		$(MAKE) CC=gcc     CFLAGS='$(GCC_FLAGS)'   CFLAGS+='-D TEST' bonus; \
		GCC_STATUS=$$?  ; \
		echo CC:$$CC_STATUS CLANG:$$CLANG_STATUS GCC:$$GCC_STATUS; \
		test $$CC_STATUS    -eq 0 && \
		test $$CLANG_STATUS -eq 0 && \
		test $$GCC_STATUS   -eq 0
	  tput smso; tput setaf 1; \
		grep -w FIXME *.c *.h $$(: */*.c */*.h); \
		test $$? -eq 1; TEST_STATUS=$$?;         tput sgr0; exit $$TEST_STATUS
	$(MAKE) norm
	- tput smso; tput setaf 3; \
		grep -w XXX   *.c *.h $$(: */*.c */*.h); tput sgr0
	- tput smso; tput setaf 2; \
		grep -w TODO  *.c *.h $$(: */*.c */*.h); tput sgr0

norm:
	tput smso; tput setaf 12; \
		norminette $$(find . -type f -regex '\./\w+/\w+\.[ch]'); \
		NORM_STATUS=$$?; \
		tput sgr0; \
		test $$NORM_STATUS -eq 0
	tput smso; tput setaf 13; \
		norminette $$(find . -type f -regex '\./\w+\.[ch]'); \
			NORM_STATUS=$$?; \
		tput sgr0; \
		test $$NORM_STATUS -eq 0

# #### ### ## #  === == =  ~~ ~  -   Bonus!   -  ~ ~~  = == ===  # ## ### #### #

BONUS_SOURCES = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c \
	minlst.c ft_lstrot.c ft_lstplast.c ft_lstget.c ft_lstclone.c ft_lstswap.c

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)


bonus: $(NAME) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)

bonus_test: fclean
	$(MAKE) DEBUG_FLAG+=-g3 DEBUG_FLAG+=-O0 raw_bonus_test
	$(MAKE) fclean

raw_bonus_test: $(SOURCES)
	:     $(CC) $(CFLAGS)      \
			-D TEST $(SOURCES) --output $(NAME); \
		$(MAKE) CC='$(CC)' CFLAGS='$(CFLAGS)'      CFLAGS+='-D TEST' bonus; \
		CC_STATUS=$$?   ; \
		: clang $(CLANG_FLAGS) \
			-D TEST $(SOURCES) --output $(NAME); \
		$(MAKE) CC=clang   CFLAGS='$(CLANG_FLAGS)' CFLAGS+='-D TEST' bonus; \
		CLANG_STATUS=$$?; \
		:gcc   $(GCC_FLAGS)   \
			-D TEST $(SOURCES) --output $(NAME); \
		$(MAKE) CC=gcc     CFLAGS='$(GCC_FLAGS)'   CFLAGS+='-D TEST' bonus; \
		GCC_STATUS=$$?  ; \
		echo CC:$$CC_STATUS CLANG:$$CLANG_STATUS GCC:$$GCC_STATUS; \
		test $$CC_STATUS    -eq 0 && \
		test $$CLANG_STATUS -eq 0 && \
		test $$GCC_STATUS   -eq 0
	  tput smso; tput setaf 1; \
		grep -w FIXME *.c *.h $$(: */*.c */*.h); \
		test $$? -eq 1; TEST_STATUS=$$?;         tput sgr0; exit $$TEST_STATUS
	$(MAKE) norm
	- tput smso; tput setaf 3; \
		grep -w XXX   *.c *.h $$(: */*.c */*.h); tput sgr0
	- tput smso; tput setaf 2; \
		grep -w TODO  *.c *.h $$(: */*.c */*.h); tput sgr0
