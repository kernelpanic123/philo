# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 15:25:25 by abtouait          #+#    #+#              #
#    Updated: 2025/07/23 07:56:27 by abtouait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c utils.c parse.c utils2.c init_philo.c destroy_and_eat.c monitor.c

CFLAGS = -Wall -Wextra -Werror


OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	cc $(CFLAGS) -pthread -c $< -o $@

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) -pthread

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re