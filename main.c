/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abder <abder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:30:17 by abtouait          #+#    #+#             */
/*   Updated: 2025/07/22 05:25:25 by abder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	data;

	if (check_arg(argv, argc) != 0)
		return (0);
	init_struct(&data, argc);
	put_values_struct(&data, argv, argc);
	if (data.philo_nbr == 1)
	{
		one_philo(&data);
		return (0);
	}
	initialize_forks(&data);
	initialize_philo(&data);
	initialize_thread(&data);
	destroy_mutex(data.philos);
	free(data.philos);
	free(data.forks);
}
