/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:41:18 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/20 13:28:03 by mmaksymi         ###   ########.fr       */
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
				return (-1);
			}
			j++;
		}
		index++;
	}
	return (0);
}

void	ft_parse(int ac, char **av, t_philo *philo)
{
	philo->quantity = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->lunch_quantity = ft_atoi(av[5]);
}
