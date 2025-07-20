/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:06:06 by abtouait          #+#    #+#             */
/*   Updated: 2025/07/19 01:55:06 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void one_philo(t_table *data)
{
	printf("%lu     Philosopher 1 has taken a fork\n",
		(get_time_in_u() - data->start_time));
	ft_usleep(data->time_to_die);
	printf("%lu    Philosopher 1 died\n", (get_time_in_u() - data->start_time));
}
void philo_sleep(t_info *data)
{
	pthread_mutex_lock(&data->printf_mutex);
	printf("%lu %d is sleeping\n", (get_time_in_u() - data->table->start_time), data->id);
	pthread_mutex_unlock(&data->printf_mutex);
	ft_usleep(data->table->time_to_sleep);
}
void philo_thinking(t_info *data)
{	
	pthread_mutex_lock(&data->printf_mutex);
	printf("%lu %d is thinking\n", (get_time_in_u() - data->table->start_time), data->id);
	pthread_mutex_unlock(&data->printf_mutex);
}
void initialize_forks(t_table *atad)
{
	int i;

	i = 0;
	atad->forks = malloc(sizeof(pthread_mutex_t) * atad->philo_nbr);
	while (i < atad->philo_nbr)
	{
		pthread_mutex_init(&atad->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&atad->philos->printf_mutex, NULL);
}
void initialize_philo(t_table *atad)
{
	int i;

	i = 0;
	atad->philos = malloc(sizeof(t_info) * (atad->philo_nbr));
	while (i < atad->philo_nbr)
	{
		atad->philos[i].id = i + 1;
		atad->philos[i].table = atad;
		atad->philos[i].l_fork = &atad->forks[i]; //on donne au pointeur l fork l'adresse du tableau mutex a l'indewx i 
		atad->philos[i].r_fork = &atad->forks[(i + 1) % atad->philo_nbr]; //modulo pour que le dernier philosophe a la premiere fourchette
		i++;
	}
	
}