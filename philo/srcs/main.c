/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:16:42 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/21 15:11:12 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_define(t_global *global)
{
	global->limit = false;
	global->lunch_quantity = 0;
	global->philos = NULL;
	global->quantity = 0;
	global->start_time = 0;
	global->time_to_die = 0;
	global->time_to_eat = 0;
	global->time_to_sleep = 0;
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
	{
		write(STDERR_FILENO, "There are too many or not enough arguments !\n", 46);
		return (-1);
	}
	if (ft_arg_check(ac, av) < 0)
		return (-1);
	ft_define(&philo);
	if (ft_parse(ac, av, &philo) < 0)
	{
		write (STDERR_FILENO, "Memory allocation error !\n", 27);
		return (-1);
	}



	
	return (0);
}
