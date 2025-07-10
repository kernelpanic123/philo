/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:30:17 by abtouait          #+#    #+#             */
/*   Updated: 2025/07/10 14:09:15 by abder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int main(int argc, char **argv)
{
	t_table	data;
	t_info  atad;
	if (check_arg(argv, argc) != 0)
		return (0);
	init_struct(&data, argc);
	put_values_struct(&data, argv, argc);
	if (data.philo_nbr == 1)
	{
		one_philo(&data);
		return (0);
	}
	initialize_forks(&atad, &data);
	initialize_philo(&atad, &data);
