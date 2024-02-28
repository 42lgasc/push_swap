# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgasc <lgasc@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 17:30:49 by lgasc             #+#    #+#              #
#    Updated: 2024/02/28 18:15:29 by lgasc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# #### ### ## #  === == =  ~~ ~  - VARIABLES= -  ~ ~~  = == ===  # ## ### #### #

NAME = push_swap

# Special variables
#CC = gcc
export DEBUG_FLAG = #-g -O0
CFLAGS += -Wall -Wextra -Werror $(DEBUG_FLAG) -fpie#-fPIC#-fPIE
CLANG_FLAGS += $(CFLAGS) -g -pedantic -pedantic-errors -Wunused-result \
	-Wconversion -Wsign-conversion -Wmissing-field-initializers
GCC_FLAGS += $(CLANG_FLAGS) -Warith-conversion

LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

SOURCES = $(NAME).c stacks.c parsing.c aim.c offload.c \
	ft_swap_push.c ft_raise.c ft_refurb.c ft_gnome_sort.c ft_lis.c

#OBJECTS = $(SOURCES:.c=.o)

ARGUMENTS = 

# #### ### ## #  === == =  ~~ ~  -  recipes:  -  ~ ~~  = == ===  # ## ### #### #
.PHONY: all clean fclean re bclean test raw_test norm

all: $(NAME) ;

# Archive files must come after object files?
$(NAME): $(SOURCES) $(LIBFT) $(FT_PRINTF) #$(OBJECTS)
	- clang $(CLANG_FLAGS) $(SOURCES) $(LIBFT) $(FT_PRINTF) --output $(NAME)
	  gcc     $(GCC_FLAGS) $(SOURCES) $(LIBFT) $(FT_PRINTF) --output $(NAME)
	  $(CC)      $(CFLAGS) $(SOURCES) $(LIBFT) $(FT_PRINTF) --output $(NAME)
	#cp $(LIBFT) $(NAME)
	#ar rcs $(NAME) $(OBJECTS) $(LIBFT)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	#$(MAKE) -C $(dir $(LIBFT))     clean
	$(MAKE) -C $(dir $(FT_PRINTF)) clean

fclean: clean bclean ;

re: fclean all ;

bclean:
	$(RM) $(NAME)
	#$(MAKE) -C $(dir $(LIBFT))     bclean
	$(MAKE) -C $(dir $(FT_PRINTF)) bclean

debug:
	$(MAKE) DEBUG_FLAG+=-g3 DEBUG_FLAG+=-O0 raw_debug

raw_debug: $(SOURCES) $(LIBFT) $(FT_PRINTF)
	- clang $(CLANG_FLAGS) -D TEST \
		$(SOURCES) $(LIBFT) $(FT_PRINTF) --output $(NAME)
	  gcc     $(GCC_FLAGS) -D TEST \
		$(SOURCES) $(LIBFT) $(FT_PRINTF) --output $(NAME)
	  $(CC)      $(CFLAGS) -D TEST \
		$(SOURCES) $(LIBFT) $(FT_PRINTF) --output $(NAME)

test: fclean
	$(MAKE) CFLAGS+='$(CFLAGS)' CFLAGS+=-g3 CFLAGS+=-O0 CFLAGS+='-D TEST' \
		raw_test
	$(MAKE) fclean

raw_test: $(SOURCES) $(LIBFT) $(FT_PRINTF) #$(NAME)
	$(CC)          $(CFLAGS) \
			-D TEST $(SOURCES) $(LIBFT) $(FT_PRINTF) --output $(NAME); \
		CC_STATUS=$$?   ; \
		clang $(CLANG_FLAGS) \
			-D TEST $(SOURCES) $(LIBFT) $(FT_PRINTF) --output $(NAME); \
		CLANG_STATUS=$$?; \
		gcc     $(GCC_FLAGS) \
			-D TEST $(SOURCES) $(LIBFT) $(FT_PRINTF) --output $(NAME); \
		GCC_STATUS=$$?  ; \
		echo CC:$$CC_STATUS CLANG:$$CLANG_STATUS GCC:$$GCC_STATUS; \
		test $$CC_STATUS    -eq 0 && \
		test $$CLANG_STATUS -eq 0 && \
		test $$GCC_STATUS   -eq 0
	  tput smso; tput setaf 1; \
		grep -w FIXME *.c *.h $$(: */*.c */*.h); \
		test $$? -eq 1; CODE=$$?;                tput sgr0; exit $$CODE
	$(MAKE) norm
	- tput smso; tput setaf 3; \
		grep -w XXX   *.c *.h $$(: */*.c */*.h); tput sgr0
	- tput smso; tput setaf 2; \
		grep -w TODO  *.c *.h $$(: */*.c */*.h); tput sgr0
	./$(NAME) $(ARGUMENTS) \
		; echo $$?

norm:
	tput smso; \
		tput setaf 12; \
		norminette $$(find . -type f -regex '\./\w+/\w+\.[ch]'); \
		NORM_STATUS=$$?; \
		tput sgr0; \
		test $$NORM_STATUS -eq 0
	tput smso; \
		tput setaf 13; \
		norminette $$(find . -type f -regex '\./\w+\.[ch]'); \
			NORM_STATUS=$$?; \
		tput sgr0; \
		test $$NORM_STATUS -eq 0

# Implicit
#$(OBJECTS)%: $(%:.o=.c)
#	$(CC) $(CFLAGS) -c $^ --output $@

$(LIBFT):
	$(MAKE) -C $(dir $@) $$(: DEBUG_FLAG=$(DEBUG_FLAG)) bonus #$(notdir $@)
$(FT_PRINTF):
	$(MAKE) -C $(dir $@) $$(: DEBUG_FLAG=$(DEBUG_FLAG)) $(notdir $@)

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
