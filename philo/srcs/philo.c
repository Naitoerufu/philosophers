/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:38:08 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/22 11:17:09 by mmaksymi         ###   ########.fr       */
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

static void ft_message(t_philo *ph, int state)
{
    pthread_mutex_lock(&ph->global->write_mutex);
    if (state == FORK_STATE)
        printf("TIMESTAMP %d has taken a fork\n", ph->id + 1);
    if (state == EAT_STATE)
        printf("TIMESTAMP %d is eating\n", ph->id + 1);
    if (state == SLEEP_STATE)
        printf("TIMESTAMP %d is sleeping\n", ph->id + 1);
    if (state == THINK_STATE)
        printf("TIMESTAMP %d is thinking\n", ph->id + 1);
    pthread_mutex_unlock(&ph->global->write_mutex);
}

void    *ft_philo(void* philo)
{
    t_philo ph;

    ph = *(t_philo*)philo;
    while (!ph.global->dead)
    {
    ft_take_forks(&ph);
    ft_message(&ph, FORK_STATE);
    ft_message(&ph, EAT_STATE);
    usleep(ph.global->time_to_eat); // TODO: change the usleep cuz of latency
    ft_put_forks(&ph);
    ft_message(&ph, SLEEP_STATE);
    usleep(ph.global->time_to_sleep); // TODO: change the usleep cuz of latency
    ft_message(&ph, THINK_STATE);
    }
    return NULL;
}
