/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:27:20 by abtouait          #+#    #+#             */
/*   Updated: 2025/07/10 19:06:51 by abder            ###   ########.fr       */
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

typedef struct s_table t_table;

typedef struct s_info
{
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	int 			id;
	pthread_t 		th;
	t_table			*table; //pointeur vers la struct t_table(en gros toutes ces infos)
	size_t			last_meal_time;
	
}t_info;

typedef struct s_table
{
	int philo_nbr;
	int time_to_die;
	int time_to_sleep;
	int time_to_eat;
	int must_eat;
	size_t start_time;
	pthread_mutex_t *forks;
	t_info *philos;
	int		dead_flag;
	
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
void philo_sleep(t_table *data);
void philo_thinking(t_table *data);
void initialize_forks(t_info *data, t_table *atad);
void initialize_philo(t_info *data, t_table *atad);

#endif