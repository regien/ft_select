# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: regien <gmalpart@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 04:24:39 by regien            #+#    #+#              #
#    Updated: 2018/05/16 11:45:03 by regien           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
DUMMY = test
MAKE = make -C 
LIBFT = libft/libft.a
CURSES = -l ncurses
# LIBPRINTF = ft_printf/libft
FLAGSC = -Wall -Wextra -Werror
HEADERS = -I includes -I libft/includes
CC = gcc

FILES = main.c

SRCFIL = $(addprefix src/, $(FILES))


all: $(NAME)


# REMEMBER TO INCLUDES THE FLAGSC in the final version
$(NAME):
	$(MAKE) libft 
	gcc $(HEADERS) $(CURSES) $(LIBFT) $(SRCFIL) -o $(NAME)
	

comp:
	gcc $(HEADERS) $(CURSES) $(SRCFIL) $(LIBFT) -o $(DUMMY)

clean:
	$(MAKE) libft clean
	

fclean:
	$(MAKE) libft fclean
	rm $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
