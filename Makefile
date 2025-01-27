# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ligharbi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 12:21:10 by ligharbi          #+#    #+#              #
#    Updated: 2025/01/02 12:23:11 by ligharbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME =libftprintf.a

CC = gcc

CFLAGS += -Wall -Wextra -Werror

SRC = ft_printf.c treat_c.c  treat_hex.c  treat_p.c ft_putstr.c print_i.c print_u.c

BNS =

all: $(NAME)

OBJ = $(SRC:.c=.o)

BNS_OBJ = $(BNS:.c=.o)

bonus: $(BNS_OBJ)
	ar rcs $(NAME) $(BNS_OBJ)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS)	-c	$<	-o	$@

clean:
	rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
