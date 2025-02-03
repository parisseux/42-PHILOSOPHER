/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:23:27 by pchatagn          #+#    #+#             */
/*   Updated: 2025/02/03 18:05:43 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	*ft_monitor_start(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;

	pthread_mutex_lock(&philo->data->start_mutex);
	philo->data->philo_ready++;
	pthread_mutex_unlock(&philo->data->start_mutex);

	while (1)
	{
		pthread_mutex_lock(&philo->data->start_mutex);
		if (philo->data->philo_ready >= philo->data->n_philo)
		{
			if (philo->data->time_start == 0)
				philo->data->time_start = ft_get_starting_time();
			pthread_mutex_unlock(&philo->data->start_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->data->start_mutex);
		usleep(100);
	}
	while (!ft_stop_loop(philo->data))
	{
		ft_routine(philo);
	}
	return (NULL);
}

void	*ft_routine(t_philo *philo)
{
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
	while (!ft_stop_loop(philo->data))
	{
		if (ft_stop_loop(philo->data))
			return (NULL);
		ft_eat(philo);
		if (ft_stop_loop(philo->data))
			return (NULL);
		ft_sleep(philo);
		if (ft_stop_loop(philo->data))
			return (NULL);
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
	ft_wait(philo->data->time_to_sleep, philo->data);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_print_actions(philo, 3);
	if (philo[0].data->n_philo == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		ft_wait(philo->data->time_to_die, philo->data);
		pthread_mutex_lock(&philo[0].data->stop_mutex);
		philo[0].data->stop = 1;
		pthread_mutex_unlock(&philo[0].data->stop_mutex);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	ft_print_actions(philo, 3);
	pthread_mutex_lock(&philo->last_meal);
	philo->time_last_meal = ft_get_simulation_time(philo->data);
	pthread_mutex_unlock(&philo->last_meal);
	pthread_mutex_lock(&philo->count_meal);
	philo->n_meal++;
	pthread_mutex_unlock(&philo->count_meal);
	ft_print_actions(philo, 2);
	ft_wait(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
