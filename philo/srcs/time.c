/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:24:57 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/22 12:04:11 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t ft_get_time(void)
{
    struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(STDERR_FILENO, "Getting time error\n", 20);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t ms)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < ms)
		usleep(1);
	return (0);
}