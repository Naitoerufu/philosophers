/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:18:24 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/24 10:45:17 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void ft_init_mutex(t_global *global)
{
    int i;

    i = 0;
    while (i < global->quantity)
    {
        pthread_mutex_init(&global->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&global->check, NULL);
    pthread_mutex_init(&global->write_mutex, NULL);
}

int ft_create_philos(t_global *global)
{
    int i;

    i = 0;
    global->start_time = ft_get_time();
    while (i < global->quantity)
    {
        if (pthread_create(&global->philos[i].thread, NULL, &ft_philo, &global->philos[i]) != 0)
        {
            write (STDERR_FILENO, "Thread creation error !\n", 25);
            return (ERROR);
        }
        i++;
    }
    return (0);
}

int ft_wait_philos(t_global *global)
{
    int i;

    i = 0;
    while (i < global->quantity)
    {
        if (pthread_join(global->philos[i].thread, NULL) < 0)
        {
            write(STDERR_FILENO, "Thread joining error\n", 22);
            return (ERROR);
        }
        i++;
    }
    return (0);
}