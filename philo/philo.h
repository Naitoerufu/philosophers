/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:16:35 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/22 12:05:04 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

#define ERROR -1
#define FORK_STATE 1
#define EAT_STATE 2
#define SLEEP_STATE 3
#define THINK_STATE 4
#define DEAD_STATE 5

typedef struct s_philo
{
	struct s_global *global;
	pthread_t thread;
	int	id;
	int last_lunch_time;
}				t_philo;

typedef struct s_global
{
	t_philo *philos;
	int quantity;
	int time_to_eat;
	int time_to_sleep;
	int time_to_die;
	size_t start_time;
	int lunch_quantity;
	bool limit;
	bool dead;
	pthread_mutex_t write_mutex;
	pthread_mutex_t *forks;
}	t_global;

size_t ft_get_time(void);
int	ft_usleep(size_t ms);

int	ft_strlen(const char *s);
int	ft_strcmp(char *s1, char *s2);
int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
int				ft_arg_check(int ac, char **av);
int			ft_parse(int ac, char **av, t_global *global);
int				ft_error_check(t_philo philo);

int ft_create_philos(t_global *global);
void    *ft_philo(void* philo);
int ft_wait_philos(t_global *global);

#endif
