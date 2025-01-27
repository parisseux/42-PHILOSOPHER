/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:18:36 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/27 10:59:27 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_mutex(t_data *data)
{
	int	i;

	if (data->fork_init)
	{
		i = 0;
		while (i < data->n_philo)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&data->stop_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}

void	ft_clean_up(t_data *data, t_philo **philo, pthread_mutex_t *forks)
{
	int	i;

	if (philo && *philo)
		free (*philo);
	if (forks)
	{
		i = 0;
		while (i < data->n_philo)
		{
			pthread_mutex_destroy(&forks[i]);
			i++;
		}
		free(forks);
	}
	pthread_mutex_destroy(&data->stop_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}

void	ft_join_threads(int n, pthread_t *philo_threads)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join(philo_threads[i], NULL);
		i++;
	}
}
