/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:16:42 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/20 13:28:16 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	if (ac < 5 || ac > 6)
	{
		printf("There are too many or not enough arguments !\n");
		return (-1);
	}
	if (ft_arg_check(ac, av) < 0)
		return (-1);
	ft_parse(ac, av, &philo);
	
		
}
