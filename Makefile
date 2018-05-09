# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 21:34:06 by gmalpart          #+#    #+#              #
#    Updated: 2018/03/26 13:59:21 by gmalpart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIB = libft/
CFLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = libft/includes
FLAGSHEAD = -I libft/includes -I includes/

# Only using a few libft functions

FTFILES = ft_memalloc.c \
		  ft_putnbr.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_strlen.c

LIBFTFILES = $(addprefix libft/, $(FTFILES))

# MAIN WORK files of the project

FILES = parser.c \
		f_conversions.c \
		parse_intfloat.c \
		parser_strings.c \
		f_align.c \
		f_leftalign.c \
		f_space.c \
		f_zero.c \
		f_zero_debug.c \
		printf.c 

SRCFILES = $(addprefix src/, $(FILES))

# CONVERSIONS / MULTICASTING files

CONVERSIONS =	h_conversions.c \
				hh_conversions.c \
				j_conversions.c \
				l_conversions.c \
				ll_conversions.c \
				z_conversions.c 

SRCCONVERS = $(addprefix src/conversions/, $(CONVERSIONS))

# FUNCTIONS JUST FOR PRINTING

HELPERS =	j_numbers.c \
			help_intfloat.c \
			help_strings.c \
			help_widechar.c \
			ll_helpers.c \
			hh_helpers.c \

SRCHELP = $(addprefix src/helpers/, $(HELPERS))

# Global call to all .c files

GENFILES = $(LIBFTFILES) $(SRCFILES) $(SRCCONVERS) $(SRCHELP)

# Objects transform

REGFILES = $(FTFILES) $(FILES) $(CONVERSIONS) $(HELPERS)
GENOBJECTS = $(REGFILES:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(FLAGSHEAD) $(GENFILES)
	ar rc $(NAME) $(GENOBJECTS)
	ranlib $(NAME)

norm:
	norminette $(GENFILES) includes/ft_printf.h

comp:
	gcc $(FLAGSHEAD) $(GENFILES) -o test

clean:
	rm -rf $(GENOBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
