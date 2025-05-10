/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:27:20 by abtouait          #+#    #+#             */
/*   Updated: 2025/05/10 19:23:33 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

typedef struct s_table
{
	long philo_nbr;
	long time_to_die;
	long time_to_sleep;
	long time_to_eat;
	long must_eat;
	
}t_table;

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

//ultis
int	ft_isdigit(int c);
void init_struct(t_table *data, int argc);
int	ft_atoi(const char *str);

//parse
int check_arg(char **argv, int argc, t_table *data);
int check_str(char *str);

#endif