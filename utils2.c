/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:21:58 by abtouait          #+#    #+#             */
/*   Updated: 2025/07/21 23:25:14 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_values_struct(t_table *data, char **argv, int argc)
{
	data->philo_nbr = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	data->start_time = get_time_in_u();
}

int	dead_protected(t_table *data)
{
	int	death;

	pthread_mutex_lock(&data->mutex_dead);
	death = data->dead_flag;
	pthread_mutex_unlock(&data->mutex_dead);
	return (death);
}
