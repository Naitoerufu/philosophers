/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:18:24 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/21 15:25:25 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int ft_create_philos(t_global *global)
{
    int i;

    i = 0;
    while (i < global->quantity)
    {
        if (pthread_create(global->philos[i].thread, NULL, NULL, &global->philos[i]) != 0)
        {
            write (STDERR_FILENO, "Thread creation error !\n", 25);
            return (ERROR);
        }
        i++;
    }
    return (0);
}
