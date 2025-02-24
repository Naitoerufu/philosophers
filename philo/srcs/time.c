/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:24:57 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/24 11:21:43 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t ft_get_time(void)
{
    struct timeval	time;

	if (gettimeofday(&time, NULL) == ERROR)
	{
		write(STDERR_FILENO, "Getting time error\n", 20);
		return(ERROR);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep_cool(size_t ms, t_philo *ph)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < ms)
	{
		if (ft_get_time() - ph->last_lunch_time >= ph->global->time_to_die && ph->last_lunch_time != 0)
		{
			pthread_mutex_lock(&ph->global->check);
			ph->global->dead = true;
			ft_message(ph, DEAD_STATE, ft_get_time() - ph->global->start_time);
			pthread_mutex_unlock(&ph->global->check);
			break ;
		}
		usleep(1);
	}
	return (0);
}