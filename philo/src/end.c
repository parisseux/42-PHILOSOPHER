/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:18:36 by pchatagn          #+#    #+#             */
/*   Updated: 2025/02/10 12:39:19 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_end_of_philo(t_data data, t_philo *philo,
						pthread_mutex_t *forks, pthread_t *philo_threads)
{
	if (philo || forks)
		ft_clean_up(&data, &philo, forks);
	free(philo_threads);
}

void	ft_destroy_mutex(t_data *data)
{
	int	i;

	if (data->fork_init && data->forks)
	{
		i = 0;
		while (i < data->n_philo)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	pthread_mutex_destroy(&data->start_mutex);
	pthread_mutex_destroy(&data->stop_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}

void	ft_clean_up(t_data *data, t_philo **philo, pthread_mutex_t *forks)
{
	int	i;

	if (philo && *philo)
	{
		i = -1;
		while (++i < data->n_philo)
		{
			pthread_mutex_destroy(&(*philo)[i].count_meal);
			pthread_mutex_destroy(&(*philo)[i].last_meal);
		}
		free (*philo);
	}
	if (forks)
		free(forks);
}
