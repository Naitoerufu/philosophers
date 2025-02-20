/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:16:35 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/20 13:03:15 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t	*philos;
	long		start_time;
	int			quantity;
	int			time_to_die;
	int			time_to_sleep;
	int			time_to_eat;
	int			lunch_quantity;
}				t_philo;

int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
int				ft_arg_check(int ac, char **av);
void			ft_parse(int ac, char **av, t_philo *philo);
int				ft_error_check(t_philo philo);

#endif
