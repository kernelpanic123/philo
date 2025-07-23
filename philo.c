/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:06:06 by abtouait          #+#    #+#             */
/*   Updated: 2025/07/23 07:21:31 by abder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_table *data)
{
	printf("%lu     Philosopher 1 has taken a fork\n",
		(get_time_in_u() - data->start_time));
	ft_usleep(data->time_to_die);
	printf("%lu   Philosopher 1 died\n", (get_time_in_u() - data->start_time));
}

void	philo_sleep(t_info *data)
{
	pthread_mutex_lock(&data->table->printf_mutex);
	printf("%lu %d is sleeping\n",
		(get_time_in_u() - data->table->start_time), data->id);
	pthread_mutex_unlock(&data->table->printf_mutex);
	ft_usleep(data->table->time_to_sleep);
}

void	philo_thinking(t_info *data)
{
	pthread_mutex_lock(&data->table->printf_mutex);
	printf("%lu %d is thinking\n",
		(get_time_in_u() - data->table->start_time), data->id);
	pthread_mutex_unlock(&data->table->printf_mutex);
}

void	initialize_forks(t_table *atad)
{
	int	i;

	i = 0;
	atad->forks = malloc(sizeof(pthread_mutex_t) * atad->philo_nbr);
	while (i < atad->philo_nbr)
	{
		pthread_mutex_init(&atad->forks[i], NULL);
		i++;
	}
}

//le premier philo prends la fourchette droite en premier pour casser la symetrie (deadlock)
//et modulo pour dernier philo qu'il retombe sur la premier fourchette
void initialize_philo(t_table *atad)
{
	int i;
	
	i = 0;
	atad->philos = malloc(sizeof(t_info) * (atad->philo_nbr));
	
	while (i < atad->philo_nbr)
	{
		atad->philos[i].id = i + 1;
		atad->philos[i].table = atad;
		if (i == 0) 
		{
			atad->philos[i].l_fork = &atad->forks[(i + 1) % atad->philo_nbr];
			atad->philos[i].r_fork = &atad->forks[i];
		}
		else
		{
			atad->philos[i].l_fork = &atad->forks[i];
			atad->philos[i].r_fork = &atad->forks[(i + 1) % atad->philo_nbr];
		}
		atad->philos[i].last_meal_time = atad->start_time;
		atad->philos[i].nbr_meals = 0;
		pthread_mutex_init(&atad->philos[i].meal_mutex, NULL);
		i++;
	}
	pthread_mutex_init(&atad->mutex_dead, NULL);
	pthread_mutex_init(&atad->printf_mutex, NULL);
}
