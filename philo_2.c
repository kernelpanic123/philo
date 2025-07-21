/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:04:47 by abder             #+#    #+#             */
/*   Updated: 2025/07/21 23:16:54 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_table *atad)
{
	int	i;

	i = 0;
	while (i < atad->philo_nbr)
	{
		if ((get_time_in_u()) - (atad->philos[i].last_meal_time)
			> atad->time_to_die)
		{
			pthread_mutex_lock(&atad->philos[i].printf_mutex);
			printf("%lu %d died\n", (get_time_in_u() - atad->start_time),
				atad->philos[i].id);
			pthread_mutex_unlock(&atad->philos[i].printf_mutex);
			pthread_mutex_lock(&atad->mutex_dead);
			atad->dead_flag = 1;
			pthread_mutex_unlock(&atad->mutex_dead);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_table	*atad;

	atad = (t_table *)arg;
	while (!dead_protected(atad))
	{
		check_death(atad);
		ft_usleep(10);
	}
	return (NULL);
}

void	initialize_thread(t_table *atad)
{
	int	i;

	i = 0;
	pthread_create(&atad->monitor_thread, NULL, &monitor_routine, atad);
	while (i < atad->philo_nbr)
	{
		pthread_create(&atad->philos[i].th, NULL,
			&philo_routine, &atad->philos[i]);
		i++;
	}
	i = 0;
	while (i < atad->philo_nbr)
	{
		pthread_join(atad->philos[i].th, NULL);
		i++;
	}
	pthread_join(atad->monitor_thread, NULL);
}

void	*philo_routine(void *arg)
{
	t_info	*data;

	data = (t_info *)arg;
	if (data->id % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		if (dead_protected(data->table))
			break ;
		philo_thinking(data);
		if (dead_protected(data->table))
			break ;
		philo_eat(data);
		if (dead_protected(data->table))
			break ;
		philo_sleep(data);
	}
	return (NULL);
}
