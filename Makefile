# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abtouait <abtouait@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 15:25:25 by abtouait          #+#    #+#              #
#    Updated: 2025/06/07 01:22:19 by abtouait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c utils.c parse.c philo.c utils2.c

CFLAGS = -Wall -Wextra


OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(MLX_LIB)
	cc $(OBJ) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re