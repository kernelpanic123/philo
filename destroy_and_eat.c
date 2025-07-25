/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:00:30 by abder             #+#    #+#             */
/*   Updated: 2025/07/23 07:43:53 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_printf(t_info *data)
{
	pthread_mutex_lock(&data->table->printf_mutex);
	printf("%ld %d has taken a fork\n",
		(get_time_in_u() - data->table->start_time), data->id);
	printf("%ld %d has taken a fork\n",
		(get_time_in_u() - data->table->start_time), data->id);
	printf("%ld %d is eating\n",
		(get_time_in_u() - data->table->start_time), data->id);
	pthread_mutex_unlock(&data->table->printf_mutex);
}

void	philo_eat(t_info *data)
{
	pthread_mutex_lock(data->l_fork);
	pthread_mutex_lock(data->r_fork);
	if (dead_protected(data->table))
	{
		pthread_mutex_unlock(data->r_fork);
		pthread_mutex_unlock(data->l_fork);
		return ;
	}
	mutex_printf(data);
	pthread_mutex_lock(&data->meal_mutex);
	data->last_meal_time = get_time_in_u();
	data->nbr_meals = data->nbr_meals + 1;
	pthread_mutex_unlock(&data->meal_mutex);
	ft_usleep(data->table->time_to_eat);
	pthread_mutex_unlock(data->r_fork);
	pthread_mutex_unlock(data->l_fork);
}

void	destroy_mutex(t_info *data)
{
	int	i;

	i = 0;
	while (i < data->table->philo_nbr)
	{
		pthread_mutex_destroy(&data->table->forks[i]);
		i++;
	}
	i = 0;
	while (i < data->table->philo_nbr)
	{
		pthread_mutex_destroy(&data->table->philos[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->table->mutex_dead);
	pthread_mutex_destroy(&data->table->printf_mutex);
}
