/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:27:20 by abtouait          #+#    #+#             */
/*   Updated: 2025/06/07 03:15:12 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stddef.h>

typedef struct s_table
{
	int philo_nbr;
	int time_to_die;
	int time_to_sleep;
	int time_to_eat;
	int must_eat;
	size_t start_time;
	
}t_table;

//ultis
int	ft_isdigit(int c);
int	ft_usleep(size_t milliseconds);
size_t	get_time_in_u(void);
void init_struct(t_table *data, int argc);
int	ft_atoi(const char *str);

//parse
int check_arg(char **argv, int argc);
int check_str(char *str);

//utils2
void put_values_struct(t_table *data, char **argv, int argc);

//philo
void one_philo(t_table *data);

#endif