/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:12:15 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/27 18:37:31 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_starting_time(void)
{
	long long		time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

long long	ft_get_simulation_time(t_data *data)
{
	long long	time;

	time = ft_get_starting_time() - data->time_start;
	return (time);
}

void	ft_philo_ready(t_data *data)
{
	data->philo_ready++;
}
