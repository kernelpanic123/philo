/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:06:06 by abtouait          #+#    #+#             */
/*   Updated: 2025/06/17 11:54:52 by abtouait         ###   ########.fr       */
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

