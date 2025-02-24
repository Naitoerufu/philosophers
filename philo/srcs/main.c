/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:16:42 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/24 13:52:53 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_define(t_global *global)
{
	global->dead_print = 0;
	global->dead = false;
	global->limit = false;
	global->lunch_quantity = 0;
	global->philos = NULL;
	global->quantity = 0;
	global->start_time = 0;
	global->time_to_die = 0;
	global->time_to_eat = 0;
	global->time_to_sleep = 0;
}

void ft_free(t_global *glob)
{
	int i;

	i = 0;
	while (i < glob->quantity)
	{
		pthread_mutex_destroy(&glob->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&glob->check);
	pthread_mutex_destroy(&glob->write_mutex);
	free(glob->forks);
	free(glob->philos);
}

int	main(int ac, char **av)
{
	t_global glob;

	if (ac < 5 || ac > 6)
	{
		write(STDERR_FILENO, "There are too many or not enough arguments !\n", 46);
		return (ERROR);
	}
	if (ft_arg_check(ac, av) < 0)
		return (ERROR);
	ft_define(&glob);
	if (ft_parse(ac, av, &glob) < 0)
	{
		write (STDERR_FILENO, "Memory allocation error !\n", 27);
		return (ERROR);
	}
	ft_init_mutex(&glob);
	ft_create_philos(&glob);
	ft_wait_philos(&glob);
	ft_free(&glob);
	return (0);
}
