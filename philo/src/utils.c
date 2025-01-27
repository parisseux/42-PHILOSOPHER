/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:15:51 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/27 18:38:27 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_actions(t_philo *philo, int c)
{
	long long	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	time = ft_get_simulation_time(philo->data);
	if (c == 1)
		printf("\033[90m%04lld\033[0m Philo %d is \033[32mthinking\033[0m\n", time, philo->id);
	else if (c == 2)
	{
		philo->n_meal++;
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
