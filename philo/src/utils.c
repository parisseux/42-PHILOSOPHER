/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:15:51 by pchatagn          #+#    #+#             */
/*   Updated: 2025/02/03 18:20:11 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_actions(t_philo *philo, int c)
{
	long long	time;

	if (ft_stop_loop(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->print_mutex);
	time = ft_get_simulation_time(philo->data);
	if (c == 1)
		printf("\033[90m%04lld\033[0m Philo %d is \033[32mthinking\033[0m\n", time, philo->id);
	else if (c == 2)
	{
		printf("\033[90m%04lld\033[0m Philo %d is \033[35meating\033[0m. ", time, philo->id);
		printf("Philo %d has now eaten %d time(s)\n", philo->id, philo->n_meal);
	}
	else if (c == 3)
		printf("\033[90m%04lld\033[0m Philo %d has taken a fork\n", time, philo->id);
	else if (c == 4)
		printf("\033[90m%04lld\033[0m Philo %d is \033[34msleeping\033[0m\n", time, philo->id);
	printf("\n");
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	ft_print_death(t_philo *philo, int index)
{
	long long	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = ft_get_simulation_time(philo->data);
	printf("\033[90m%04lld\033[0m Philo %d is \033[31mdead\033[0m\n", time, index);
	printf("\n");
	pthread_mutex_unlock(&philo->data->print_mutex);
}

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

void	ft_wait(int time_ms, t_data *data)
{
	long long	start_time;

	start_time = ft_get_simulation_time(data);
	while ((ft_get_simulation_time(data) - start_time) < time_ms)
	{
		pthread_mutex_lock(&data->stop_mutex);
		if (data->stop == 1)
		{
			pthread_mutex_unlock(&data->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->stop_mutex);
		usleep(500);
	}
}
