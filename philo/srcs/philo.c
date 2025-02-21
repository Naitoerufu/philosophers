/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:38:08 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/21 15:37:26 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void    ft_take_forks(t_philo *ph)
{
    if (ph->id % 2 == 0)
    {
        pthread_mutex_lock(&ph->global->forks[ph->id]);
        if (ph->id != ph->global->quantity - 1)
            pthread_mutex_lock(&ph->global->forks[ph->id + 1]);
        else
            pthread_mutex_lock(&ph->global->forks[0]);
    }
    else
    {
        if (ph->id != ph->global->quantity - 1)
            pthread_mutex_lock(&ph->global->forks[ph->id + 1]);
        else
            pthread_mutex_lock(&ph->global->forks[0]);
        pthread_mutex_lock(&ph->global->forks[ph->id]);
    }
}

void    *ft_philo(void* philo)
{
    t_philo ph;

    ph = *(t_philo*)philo;
    ft_take_forks(&ph);
    usleep(ph.global->time_to_eat); // TODO: change the usleep cuz of latency
    // TODO: print the message
}