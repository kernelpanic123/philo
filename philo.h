/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:27:20 by abtouait          #+#    #+#             */
/*   Updated: 2025/05/08 14:16:00 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

typedef struct s_table
{
	long philo_nbr;
	long time_to_die;
	long time_to_sleep;
	long time_to_eat;
	long must_eat;
}t_table;

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//ultis
int	ft_atol(const char *str);
int	ft_isdigit(int c);
void	ft_error(void);
void init_struct(t_table *data, char **argv, int argc);

#endif