/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksymi <mmaksymi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:14:12 by mmaksymi          #+#    #+#             */
/*   Updated: 2025/02/20 11:47:29 by mmaksymi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	count;
	int	out;
	int	sign;

	if (!(*nptr))
		return (0);
	count = 0;
	out = 0;
	sign = 1;
	while (nptr[count] == ' ' || nptr[count] == '\f' || nptr[count] == '\t'
		|| nptr[count] == '\n' || nptr[count] == '\r' || nptr[count] == '\v')
		count++;
	if (nptr[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (nptr[count] == '+')
		count++;
	while (ft_isdigit(nptr[count]))
	{
		out = out * 10 + (nptr[count] - '0');
		count++;
	}
	return (out * sign);
}
