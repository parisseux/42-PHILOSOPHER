/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:28:13 by pchatagn          #+#    #+#             */
/*   Updated: 2025/02/10 11:30:25 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(t_philo *philo,
			pthread_t *philo_threads, pthread_t *monitor_thread)
{
	int	i;

	i = 0;
	while (i < philo->data->n_philo)
	{
		pthread_create(&philo_threads[i], NULL,
			ft_monitor_start, (void *)&philo[i]);
		pthread_mutex_lock(&philo[i].data->start_mutex);
		philo->data->philo_ready++;
		pthread_mutex_unlock(&philo[i].data->start_mutex);
		i++;
	}
	pthread_create(monitor_thread, NULL, ft_monitor, (void *)philo);
}

void	ft_join_threads(t_philo *philo,
			pthread_t *philo_threads, pthread_t monitor_thread)
{
	int	i;

	i = 0;
	while (i < philo->data->n_philo)
	{
		pthread_join(philo_threads[i], NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
}
