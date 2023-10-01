# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 14:11:51 by tbolzan-          #+#    #+#              #
#    Updated: 2023/10/01 00:40:00 by ricardo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = so_long

LIBFT = libft.a

LIBMLX = ./minilibx-linux/libmlx_Linux.a ./minilibx-linux/libmlx.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

LFLAGS = -L $(LIBMLX) $(LIBFT)

RM = rm -f

AR = ar -rsc

SRC = $(wildcard *.c) 

OBJ = $(SRC:.c=.o)

all: $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3  -c $< -o $@

$(NAME): $(OBJ)
	@make -C ./libft
	@mv ./libft/$(LIBFT) .
	$(CC) $(OBJ) -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) libft.a


clean:
	$(RM) $(OBJ)
	@make clean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclan re
	
