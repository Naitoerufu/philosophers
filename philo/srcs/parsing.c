/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:41:18 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/22 10:36:14 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_arg_check(int ac, char **av)
{
	int	index;
	int	j;

	index = 1;
	while (index < ac)
	{
		j = 0;
		while (av[index][j])
		{
			if (!ft_isdigit(av[index][j]))
			{
				printf("There are not only a numbers in the arguments !\n");
				return (ERROR);
			}
			j++;
		}
		if (ft_strlen(av[index]) > 10 || (ft_strlen(av[index]) == 10 && ft_strcmp(av[index], "2147483647") > 0))
		{
			printf("There are arguments that are superior of INT_MAX\n");
			return (ERROR);
		}
		index++;
	}
	return (0);
}

static void	ft_philo_init(t_global *global)
{
	int i;

	i = 0;
	while (i < global->quantity)
	{
		global->philos[i].global = global;
		global->philos[i].id = i;
		global->philos[i].last_lunch_time = 0;
		i++;
	}
}

int	ft_parse(int ac, char **av, t_global *global)
{
	global->quantity = ft_atoi(av[1]);
	global->time_to_die = ft_atoi(av[2]);
	global->time_to_eat = ft_atoi(av[3]);
	global->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		global->lunch_quantity = ft_atoi(av[5]);
		global->limit = true;
	}
	global->forks = malloc(sizeof(pthread_mutex_t) * global->quantity);
	if (!global->forks)
		return (ERROR);
	global->philos = malloc(sizeof(t_philo) * global->quantity);
	if (!global->philos)
		return (ERROR);
	ft_philo_init(global);
	
	return (0);
}
