/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:15:50 by pchatagn          #+#    #+#             */
/*   Updated: 2025/02/03 18:19:46 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_stop_simulation(t_philo *philo)
{
	int	i;
	int	all_philo_full;

	all_philo_full = 1;
	if (philo->data->n_eat > 0)
	{
		i = 0;
		while (i < philo[0].data->n_philo)
		{
			pthread_mutex_lock(&philo[i].count_meal);
			if (philo[i].n_meal < philo[0].data->n_eat)
			{
				all_philo_full = 0;
				pthread_mutex_unlock(&philo[i].count_meal);
				break ;
			}
			pthread_mutex_unlock(&philo[i].count_meal);
			i++;
		}
	}
	else
		return (0);
	if (all_philo_full)
	{
		pthread_mutex_lock(&philo->data->stop_mutex);
		philo->data->stop = 1;
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (1);
	}
	return (0);
}

int	ft_stop_simulation2(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->n_philo)
	{
		pthread_mutex_lock(&philo[i].last_meal);
		if ((ft_get_simulation_time(philo[0].data) - philo[i].time_last_meal) >= philo[0].data->time_to_die)
		{
			ft_print_death(philo, i + 1);
			pthread_mutex_lock(&philo[0].data->stop_mutex);
			philo[0].data->stop = 1;
			pthread_mutex_unlock(&philo->data->stop_mutex);
			pthread_mutex_unlock(&philo[i].last_meal);
			return (1);
		}
		pthread_mutex_unlock(&philo[i].last_meal);
		i++;
	}
	return (0);
}

void	*ft_monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ft_stop_simulation(philo))
			return (NULL);
		if (ft_stop_simulation2(philo))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	ft_stop_loop(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->stop_mutex);
	i = data->stop;
	pthread_mutex_unlock(&data->stop_mutex);
	return (i);
}
