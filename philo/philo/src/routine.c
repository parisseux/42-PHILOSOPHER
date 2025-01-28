/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:23:27 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/28 17:16:43 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_monitor_start(t_data *data)
{
	pthread_mutex_lock(&data->start_mutex);
	while (data->n_philo != data->philo_ready)
	{
		pthread_mutex_unlock(&data->start_mutex);
		usleep(100);
		pthread_mutex_lock(&data->start_mutex);
	}
	data->time_start = ft_get_starting_time();
	pthread_mutex_unlock(&data->start_mutex);
}

void	*ft_routine(void *arg)
{
	t_philo		*philo;
	if (!arg)
	{
		printf("error: Null pointer passed to thread routine\n");
		pthread_exit(NULL);
	}
	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->start_mutex);
	while (philo->data->time_start == 0)
	{
		pthread_mutex_unlock(&philo->data->start_mutex);
		usleep(100);
		pthread_mutex_lock(&philo->data->start_mutex);
	}
	pthread_mutex_unlock(&philo->data->start_mutex);
	ft_think(philo);
	if ((*philo).id % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&philo->data->stop_mutex);
		if (philo->data->stop)
		{
			pthread_mutex_unlock(&philo->data->stop_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->stop_mutex);
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}

void	ft_think(t_philo *philo)
{
	ft_print_actions(philo, 1);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_actions(philo, 4);
	usleep(philo->data->time_to_sleep * 1000);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print_actions(philo, 3);
	if (philo->data->n_philo == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		usleep(philo->data->time_to_die * 1000);
		ft_print_actions(philo, 5);
		exit (0);
	}
	pthread_mutex_lock(philo->right_fork);
	ft_print_actions(philo, 3);
	pthread_mutex_lock(&philo->count_meal);
	philo->n_meal++;
	pthread_mutex_unlock(&philo->count_meal);
	ft_print_actions(philo, 2);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->last_meal);
	philo->time_last_meal = ft_get_simulation_time(philo->data);
	pthread_mutex_unlock(&philo->last_meal);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
