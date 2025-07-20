/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:04:47 by abder             #+#    #+#             */
/*   Updated: 2025/07/20 07:17:15 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_table *atad)
{
    int i;
    
    i = 0;
    while (i < atad->philo_nbr)
    {
        if ((get_time_in_u()) - (atad->philos[i].last_meal_time) > atad->time_to_die)
        {
            printf("%lu Philosopher %d died\n",(get_time_in_u() - atad->start_time), atad->philos[i].id);
            atad->dead_flag = 1;
            return (1);
        }
        i++;
    }
    return (0);
}
void monitor_death(t_table *atad)
{
    pthread_t thread;
    pthread_create(&thread, NULL, &monitor_routine, atad);
    pthread_join(thread, NULL);
}
void *monitor_routine(void *arg)
{
    t_table *atad = (t_table *)arg;
    
    while (atad->dead_flag != 1)
    {
        check_death(atad);
        ft_usleep(100);
    }
    return NULL;
}

void initialize_thread(t_table *atad)
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
void *philo_routine(void *arg)
{
    t_info *data = (t_info *)arg;
    
	if (data->id % 2 == 0)
		ft_usleep(10);
    while (data->table->dead_flag != 1)
    {
        philo_thinking(data);
        philo_eat(data);
        philo_sleep(data);//commencer par penser au debut et faire start en fivisant par 2
    }
    return NULL;
}