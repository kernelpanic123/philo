/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:00:30 by abder             #+#    #+#             */
/*   Updated: 2025/07/21 08:13:13 by abder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void mutex_printf(t_info *data)
{   
    pthread_mutex_lock(&data->printf_mutex);
    printf("%ld %d has taken a fork\n", (get_time_in_u() - data->table->start_time),data->id);
    printf("%ld %d has taken a fork\n", (get_time_in_u() - data->table->start_time),data->id);
    printf("%ld %d is eating\n",(get_time_in_u() - data->table->start_time) ,data->id);
    pthread_mutex_unlock(&data->printf_mutex);
}

void philo_eat(t_info *data)
{
    pthread_mutex_lock(data->r_fork);
    pthread_mutex_lock(data->l_fork);
    mutex_printf(data);
    pthread_mutex_lock(&data->meal_mutex);
    data->last_meal_time = get_time_in_u();
    pthread_mutex_unlock(&data->meal_mutex);
    ft_usleep(data->table->time_to_eat);
    printf("DEBUG PHILO %d finished eating after sleep\n", data->id);
    pthread_mutex_unlock(data->r_fork);
    pthread_mutex_unlock(data->l_fork);
    
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
