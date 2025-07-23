/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:04:47 by abder             #+#    #+#             */
/*   Updated: 2025/07/23 06:47:16 by abder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_table *atad)
{
    int i = 0;
    while (i < atad->philo_nbr)
    {
        pthread_mutex_lock(&atad->philos[i].meal_mutex); // Verrou avant lecture
        if ((get_time_in_u() - atad->philos[i].last_meal_time) > atad->time_to_die)
        {
            pthread_mutex_unlock(&atad->philos[i].meal_mutex);
            pthread_mutex_lock(&atad->printf_mutex); // Utilisez un mutex global pour printf
            printf("%lu %d died\n", (get_time_in_u() - atad->start_time), atad->philos[i].id);
            pthread_mutex_unlock(&atad->printf_mutex);
            pthread_mutex_lock(&atad->mutex_dead);
            atad->dead_flag = 1;
            pthread_mutex_unlock(&atad->mutex_dead);
            return (1);
        }
        pthread_mutex_unlock(&atad->philos[i].meal_mutex); // Déverrouillez après lecture
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
		if (check_death(atad))
			break ;
		if (check_meal_max(atad))
			break ;
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

int	check_meal_max(t_table *atad)
{
	int	i;
	int	max_meal;

	if (atad->must_eat <= 0)
		return (0);
	i = 0;
	max_meal = 0;
	while (i < atad->philo_nbr)
	{
		pthread_mutex_lock(&atad->philos[i].meal_mutex);
		if (atad->philos[i].nbr_meals >= atad->must_eat)
			max_meal++;
		pthread_mutex_unlock(&atad->philos[i].meal_mutex);
		i++;
	}
	if (max_meal == atad->philo_nbr)
	{
		pthread_mutex_lock(&atad->mutex_dead);
		atad->dead_flag = 1;
		pthread_mutex_unlock(&atad->mutex_dead);
		return (1);
	}
	return (0);
}
