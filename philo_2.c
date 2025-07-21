/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:04:47 by abder             #+#    #+#             */
/*   Updated: 2025/07/21 08:20:47 by abder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_table *atad)
{
    int i;
    
    i = 0;
    while (i < atad->philo_nbr)
    {
        printf("DEBUG: check_death PHILO %d => last_meal: %lu | now: %lu | diff: %lu\n",
       atad->philos[i].id,
       atad->philos[i].last_meal_time,
       get_time_in_u(),
       get_time_in_u() - atad->philos[i].last_meal_time);
        if ((get_time_in_u()) - (atad->philos[i].last_meal_time) > atad->time_to_die)
        {
            pthread_mutex_lock(&atad->philos[i].printf_mutex);
            printf("%lu Philosopher %d died\n", (get_time_in_u() - atad->start_time), atad->philos[i].id);
            pthread_mutex_unlock(&atad->philos[i].printf_mutex);
            pthread_mutex_lock(&atad->mutex_dead);
            atad->dead_flag = 1;
            printf("DEBUG: DEAD FLAG SET TO 1 BY PHILO %d\n", atad->philos[i].id);
            pthread_mutex_unlock(&atad->mutex_dead);
            return (1);
        }
        i++;
    }
    return (0);
}

void *monitor_routine(void *arg)
{
    t_table *atad = (t_table *)arg;

    while (!dead_protected(atad))
    {
        check_death(atad);
        ft_usleep(40);
    }
    if (check_death(atad))
        printf("DEBUG MONITOR: Death detected. Exiting loop.\n");
    return NULL;
}

void initialize_thread(t_table *atad)
{
    int i;

    i = 0;
    pthread_create(&atad->monitor_thread, NULL, &monitor_routine, atad);
    while (i < atad->philo_nbr)
    {
        pthread_create(&atad->philos[i].th, NULL, &philo_routine, &atad->philos[i]);
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
void *philo_routine(void *arg)
{
    t_info *data = (t_info *)arg;
    
	if (data->id % 2 == 0)
		ft_usleep(10);
    while (1)
    {
        printf("DEBUG PHILO %d LOOP (dead_flag = %d)\n", data->id, dead_protected(data->table));
        if (dead_protected(data->table))
            break ;
        philo_thinking(data);
        if (dead_protected(data->table))
            break ;
        philo_eat(data);
        if (dead_protected(data->table))
            break ;
        philo_sleep(data);
        if (dead_protected(data->table))
        {
            printf("DEBUG PHILO %d: Detected death flag. Exiting routine.\n", data->id);
            break;
        }
    }
    return NULL;
}