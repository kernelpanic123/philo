/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:16:17 by abtouait          #+#    #+#             */
/*   Updated: 2025/05/10 20:55:50 by abtouait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_arg(char **argv, int argc, t_table *data)
{
    
    if (argc != 5 && argc != 6)
        return (write(1, "wrong arguments\n", 17));
    else if (ft_atoi(argv[1]) <= 0)
        return (write(1, "philosophers cant be negative or null\n", 39));
    else if (ft_atoi(argv[2]) <= 60)
        return (write(1, "ERROR\n", 7));
    else if (ft_atoi(argv[3]) <= 60)
        return (write(1, "ERROR\n", 7));
    else if (ft_atoi(argv[4]) <= 60)
        return (write(1, "ERROR\n", 7));
    else if (check_str(argv[1]) == 1)
        return (write(1, "ERROR\n", 7));
    else if (check_str(argv[2]) == 1)
        return (write(1, "ERROR\n", 7));
    else if (check_str(argv[3]) == 1)
        return (write(1, "ERROR\n", 7));
    else if (check_str(argv[4]) == 1)
        return( write(1, "ERROR\n", 7));
	else if (argc == 6)
		if (check_str(argv[5]) == 1)
			return (write(1, "ERROR\n", 7));
    return (0);
}

int check_str(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (!ft_isdigit(str[i]))
            return (1);
        i++;
    }
    return (0);
}
