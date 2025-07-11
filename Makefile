# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abder <abder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 15:25:25 by abtouait          #+#    #+#              #
#    Updated: 2025/07/11 15:25:41 by abder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c utils.c parse.c philo.c utils2.c philo_2.c philo_3.c

CFLAGS = -Wall -Wextra


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