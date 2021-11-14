# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 18:12:02 by tlemma            #+#    #+#              #
#    Updated: 2021/11/14 18:26:51 by tlemma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = 
# -Wall -Werror -Wextra -g

RM = rm -f

AR = ar rs

SOURCES = ./src/bonus/so_long_bonus.c ./src/utils.c ./src/game.c ./src/map.c 

OBJECTS = $(SOURCES:.c=.o)

LIBFT = $(MAKE) -C ./libft 

$(NAME):
	# $(LIBFT)
	$(CC) $(CFLAGS) $(SOURCES) ./libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I ./mlx

all: $(NAME)

clean:
	# $(MAKE) -C ./libft clean
	$(RM) $(OBJECTS) 

fclean: clean
	# $(RM) ./libft/libft.a
	$(RM) $(NAME)

re: fclean all
		
.PHONY: all clean fclean re bonus .c .o