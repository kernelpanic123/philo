/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:00:30 by abder             #+#    #+#             */
/*   Updated: 2025/07/10 20:58:02 by abder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_eat(t_table *atad, t_info *data)
{
    pthread_mutex_lock(data->r_fork);
    pthread_mutex_lock(data->l_fork);
    printf("Philosopher %d has taken a fork\n", data->id);
    printf("Philosopher %d has taken a fork\n", data->id);
    printf("%ld Philosopher %d is eating\n",(get_time_in_u() - atad->start_time) ,data->id);
    data->last_meal_time = get_time_in_u();
    ft_usleep(atad->time_to_eat);
    pthread_mutex_unlock(data->r_fork);
    pthread_mutex_unlock(data->l_fork);
    
}