/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:38:08 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/24 14:06:45 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int ft_lfork_define(t_philo *ph)
{
	if (ph->id % 2 == 0)
		return (ph->id);
	else
	{
		if (ph->id != ph->global->quantity - 1)
			return (ph->id + 1);
		else
			return (0);
	}
}

int ft_rfork_define(t_philo *ph)
{
	if (ph->id % 2 == 0)
	{
		if (ph->id != ph->global->quantity - 1)
			return (ph->id + 1);
		else
			return (0);
	}
	else
		return (ph->id);
}

bool ft_is_dead(t_global *glob)
{
	bool out;

	pthread_mutex_lock(&glob->check);
	out = glob->dead;
	pthread_mutex_unlock(&glob->check);
	return (out);
}

static void	ft_put_forks(t_philo *ph)
{
	int l_fork_id;
	int r_fork_id;

	l_fork_id = ft_lfork_define(ph);
	r_fork_id = ft_rfork_define(ph);
	pthread_mutex_unlock(&ph->global->forks[l_fork_id]);
	pthread_mutex_unlock(&ph->global->forks[r_fork_id]);
}

static int	ft_take_forks(t_philo *ph)
{
	int l_fork_id;
	int r_fork_id;

	l_fork_id = ft_lfork_define(ph);
	r_fork_id = ft_rfork_define(ph);
	pthread_mutex_lock(&ph->global->forks[l_fork_id]);
	if (ft_is_dead(ph->global))
	{
		pthread_mutex_unlock(&ph->global->forks[l_fork_id]);
		ft_message(ph, DEAD_STATE, ft_get_time() - ph->global->start_time);
		return (DEAD_STATE);
	}
	ft_message(ph, FORK_STATE, ft_get_time() - ph->global->start_time);
	pthread_mutex_lock(&ph->global->forks[r_fork_id]);
	if (ft_is_dead(ph->global))
	{
		ft_put_forks(ph);
		return (DEAD_STATE);
	}
	ft_message(ph, FORK_STATE, ft_get_time() - ph->global->start_time);
	return (0);
}

void	ft_message(t_philo *ph, int state, size_t timestamp)
{
	pthread_mutex_lock(&ph->global->write_mutex);
	if (state == FORK_STATE)
		printf("%lu %d has taken a fork\n", timestamp, ph->id + 1);
	if (state == EAT_STATE)
		printf("%lu %d is eating\n", timestamp, ph->id + 1);
	if (state == SLEEP_STATE)
		printf("%lu %d is sleeping\n", timestamp, ph->id + 1);
	if (state == THINK_STATE)
		printf("%lu %d is thinking\n", timestamp, ph->id + 1);
	if (state == DEAD_STATE && ph->global->dead_print < 1)
	{
		printf("%lu %d died\n", timestamp, ph->id + 1);
		ph->global->dead_print++;
	}
	pthread_mutex_unlock(&ph->global->write_mutex);
}

void	*ft_philo(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (ph->global->start_time == 0 && !ft_is_dead(ph->global))
		usleep(1000);
	while (!ft_is_dead(ph->global))
	{
		if (ph->global->limit && ph->lunch_count >= ph->global->lunch_quantity)
			return (NULL);
		if (ft_take_forks(ph) == DEAD_STATE)
			return (NULL);
		ph->last_lunch_time = ft_get_time();
		ft_message(ph, EAT_STATE, ft_get_time() - ph->global->start_time);
		if (ft_usleep_cool(ph->global->time_to_eat, ph) == DEAD_STATE)
		{
			ft_put_forks(ph);
			return (NULL);
		}
		ft_put_forks(ph);
		ph->lunch_count++;
		if (ft_is_dead(ph->global))
			return (NULL);
		ft_message(ph, SLEEP_STATE, ft_get_time() - ph->global->start_time);
		if (ft_usleep_cool(ph->global->time_to_sleep, ph) == DEAD_STATE)
			return (NULL);
		ft_message(ph, THINK_STATE, ft_get_time() - ph->global->start_time);
	}
	return (NULL);
}
