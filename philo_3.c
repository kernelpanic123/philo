/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:00:30 by abder             #+#    #+#             */
/*   Updated: 2025/07/11 15:42:33 by abder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_eat(t_info *data)
{
    pthread_mutex_lock(data->r_fork);
    pthread_mutex_lock(data->l_fork);
    printf("%ld Philosopher %d has taken a fork\n", (get_time_in_u() - data->table->start_time),data->id);
    printf("%ld Philosopher %d has taken a fork\n", (get_time_in_u() - data->table->start_time),data->id);
    data->last_meal_time = get_time_in_u();
    printf("%ld Philosopher %d is eating\n",(data->last_meal_time - data->table->start_time) ,data->id);
    ft_usleep(data->table->time_to_eat);
    pthread_mutex_unlock(data->r_fork);
    pthread_mutex_unlock(data->l_fork);
    pthread_mutex_lock(&data->meal_mutex);
    data->nbr_meals = data->nbr_meals + 1;
    pthread_mutex_unlock(&data->meal_mutex);
}
void destroy_mutex(t_info *data)
{
    int i;

    i = 0;
    while (i < data->table->philo_nbr)
    {
        pthread_mutex_destroy(&data->table->forks[i]);
        i++;
    }
    i = 0;
    while (i < data->table->philo_nbr)
    {
        pthread_mutex_destroy(&data[i].meal_mutex);
        i++;
    }
}
