/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:06:06 by abtouait          #+#    #+#             */
/*   Updated: 2025/07/10 21:10:39 by abder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void one_philo(t_table *data)
{
	data->start_time = get_time_in_u();
	printf("%lu     Philosopher 1 has taken a fork\n",
		(get_time_in_u() - data->start_time));
	ft_usleep(data->time_to_die);
	printf("%lu    Philosopher 1 died\n", (get_time_in_u() - data->start_time));
}
void philo_sleep(t_table *data)
{
	data->start_time = get_time_in_u();
	printf("%lu Philosopher %d is sleeping\n", (get_time_in_u() - data->start_time), data->philos->id);
	ft_usleep(data->time_to_sleep);
}
void philo_thinking(t_table *data)
{
	data->start_time = get_time_in_u();
	printf("%lu Philo %d is thinking\n", (get_time_in_u() - data->start_time), data->philos->id);
}
void initialize_forks(t_info *data, t_table *atad)
{
	int i;

	i = 0;
	atad->forks = malloc(sizeof(pthread_mutex_t) * atad->philo_nbr);
	while (i < atad->philo_nbr)
	{
		pthread_mutex_init(&atad->forks[i], NULL);
		i++;
	}
}
void initialize_philo(t_info *data, t_table *atad)
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