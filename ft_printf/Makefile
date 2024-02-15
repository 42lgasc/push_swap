# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgasc <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:30:49 by lgasc             #+#    #+#              #
#    Updated: 2024/02/14 20:36:35 by lgasc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# #### ### ## #  === == =  ~~ ~  - VARIABLES= -  ~ ~~  = == ===  # ## ### #### #

NAME = libftprintf.a

# Special variables
#CC = gcc
CFLAGS += -Wall -Wextra -Werror -fpie#-fPIC
CLANG_FLAGS += $(CFLAGS) -g -pedantic -pedantic-errors -Wunused-result \
	-Wconversion -Wno-format-extra-args -Wno-format-invalid-specifier \
	-Wno-format -Wno-format-pedantic
GCC_FLAGS += $(CLANG_FLAGS) -Warith-conversion

LIBFT = libft/libft.a

SOURCES = ft_printf.c ft_printf_conversion.c ft_printf_utils.c print_misc.c

OBJECTS = $(SOURCES:.c=.o)


# #### ### ## #  === == =  ~~ ~  -  recipes:  -  ~ ~~  = == ===  # ## ### #### #
.PHONY: all clean fclean re bclean bonus test norm

$(NAME): all ;

# Archive files must come after object files?
all: $(OBJECTS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS) $(LIBFT)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	$(MAKE) -C $(dir $(LIBFT)) clean

fclean: clean bclean ;

re: fclean all ;

bclean:
	$(RM) $(NAME)
	$(MAKE) -C $(dir $(LIBFT)) bclean

test: #$(NAME)
	   $(MAKE) fclean
	-  $(MAKE) CC=gcc   CFLAGS+='  $(GCC_FLAGS)'        $(NAME) \
		&&        clang          $(CLANG_FLAGS) _main.c $(NAME) --output _a.out
	-  $(MAKE) CC=clang CFLAGS+='$(CLANG_FLAGS)'        $(NAME) \
		&&        gcc              $(GCC_FLAGS) _main.c $(NAME) --output _a.out
	-  $(MAKE) CC=clang CFLAGS+='$(CLANG_FLAGS)'        $(NAME) \
	&&            clang          $(CLANG_FLAGS) _main.c $(NAME) --output _a.out\
	&&                                                                 ./_a.out
	   $(MAKE) CC=gcc   CFLAGS+='  $(GCC_FLAGS)'        $(NAME) \
	&&            gcc              $(GCC_FLAGS) _main.c $(NAME) --output _a.out\
	&&                                                                 ./_a.out
	#rm                                                                  _a.out
	   $(MAKE) fclean
	  tput smso; tput setaf 1; \
		  grep -w FIXME *.c *.h $$(: */*.c */*.h); \
		  test $$? -eq 1; CODE=$$?;                tput sgr0; code $$CODE
	- $(MAKE) norm
	- tput smso; tput setaf 3; \
		  grep -w XXX   *.c *.h $$(: */*.c */*.h); tput sgr0
	- tput smso; tput setaf 2; \
		  grep -w TODO  *.c *.h $$(: */*.c */*.h); tput sgr0

norm:
	tput setab 5; norminette *.h *.c ; tput sgr0

# Implicit
#$(OBJECTS)%: $(%:.o=.c)
#	$(CC) $(CFLAGS) -c $^ --output $@

$(LIBFT):
	$(MAKE) -C $(dir $@) $(notdir $@)

# https://stackoverflow.com/a/4126617
#.SUFFIXES:	# Delete the default suffixes


# #### ### ## #  === == =  ~~ ~  -   Bonus!   -  ~ ~~  = == ===  # ## ### #### #

#BONUS_SOURCES = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_lstiter.c ft_lstmap.c

#BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)


#bonus: $(BONUS_OBJECTS)
#	ar rcs $(NAME) $(BONUS_OBJECTS)
