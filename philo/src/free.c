/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:18:36 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/21 17:55:12 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_clean_up(t_data *data, t_philo *philo)
{
	int i;

	i = 0;
	if (data)
	{
		if (data->forks)
		{
			while (i < data->n_philo)
			{
			pthread_mutex_destroy(&data.forks[i]);
			i++;
			}
			pthread_mutex_destroy(&data.forks);
		}
		if (data->init_mutex)
		{
			pthread_mutex_destroy(&data.stop_mutex);
			pthread_mutex_destroy(&data.print_mutex);
		}
	}
	if (philo)
	{
		free(philo);
	}
		
}
