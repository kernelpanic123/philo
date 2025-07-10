/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:04:47 by abder             #+#    #+#             */
/*   Updated: 2025/07/10 19:08:53 by abder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_table *atad)
{
    int i;
    size_t
    
    i = 0;
    while (i < atad->philo_nbr)
    {
        
    }
}
void monitor_death(t_table *atad, t_info *data)
{
    pthread_t thread;
    pthread_create(thread, NULL, &monitor_routine, NULL);
    pthread_join(thread, NULL);
}
void *monitor_routine()
{
    t_table *atad;
    while (atad->dead_flag != 1)
    {
        check_death(atad);
        ft_usleep(100);
    }
    return NULL;
}

void initialize_thread(t_info *data, t_table *atad)
{
    int i;

    i = 0;
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

}
void *philo_routine()
{
    t_table *data;

    philo_sleep(&data);
    philo_thinking(&data);
}