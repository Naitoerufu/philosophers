/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:38:08 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/22 10:56:29 by mmaksymi         ###   ########.fr       */
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

static void ft_put_forks(t_philo *ph)
{
    if (ph->id % 2 == 0)
    {
        pthread_mutex_unlock(&ph->global->forks[ph->id]);
        if (ph->id != ph->global->quantity - 1)
            pthread_mutex_unlock(&ph->global->forks[ph->id + 1]);
        else
            pthread_mutex_unlock(&ph->global->forks[0]);
    }
    else
    {
        if (ph->id != ph->global->quantity - 1)
            pthread_mutex_unlock(&ph->global->forks[ph->id + 1]);
        else
            pthread_mutex_unlock(&ph->global->forks[0]);
        pthread_mutex_unlock(&ph->global->forks[ph->id]);
    }
}

void    *ft_philo(void* philo)
{
    t_philo ph;

    ph = *(t_philo*)philo;
    while (1)
    {
    ft_take_forks(&ph);
    pthread_mutex_lock(&ph.global->write_mutex);
    printf("TIMESTAMP %d has taken a fork\n", ph.id + 1);
    pthread_mutex_unlock(&ph.global->write_mutex);
    pthread_mutex_lock(&ph.global->write_mutex);
    printf("TIMESTAMP %d is eating\n", ph.id + 1);
    pthread_mutex_unlock(&ph.global->write_mutex);
    usleep(ph.global->time_to_eat); // TODO: change the usleep cuz of latency
    ft_put_forks(&ph);
    pthread_mutex_lock(&ph.global->write_mutex);
    printf("TIMESTAMP %d is sleeping\n", ph.id + 1);
    pthread_mutex_unlock(&ph.global->write_mutex);
    usleep(ph.global->time_to_sleep);
    pthread_mutex_lock(&ph.global->write_mutex);
    printf("TIMESTAMP %d is thinking\n", ph.id + 1);
    pthread_mutex_unlock(&ph.global->write_mutex);
    }
    return NULL;
}
