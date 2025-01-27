/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:23:27 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/27 18:31:09 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_monitor_start(t_data *data) 
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
        pthread_mutex_lock(&philo->data->start_mutex);
    }
    pthread_mutex_unlock(&philo->data->start_mutex);

	//ft_print_actions(philo, 1);
	//usleep(100000);
	if ((*philo).id % 2 != 0)
	{
		ft_print_actions(philo, 1);
		usleep(philo->data->time_to_eat / 2);
	}
	pthread_mutex_lock(philo->left_fork);
	ft_print_actions(philo, 3);
	pthread_mutex_lock(philo->right_fork);
	ft_print_actions(philo, 3);
	ft_print_actions(philo, 2);
	usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	ft_print_actions(philo, 4);
	usleep(philo->data->time_to_sleep);
	return (NULL);
}
