/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:30:17 by abtouait          #+#    #+#             */
/*   Updated: 2025/05/08 14:16:11 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_table data;

	if (argc != 5 && argc != 6)
		ft_error();
	init_struct(&data, argv, argc);
	printf("%ld\n", data.philo_nbr);
	
}