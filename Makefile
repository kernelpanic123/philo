# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 15:25:25 by abtouait          #+#    #+#              #
#    Updated: 2025/05/03 15:45:26 by abtouait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = thread.c

CFLAGS = -Wall -Wextra -pthread


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