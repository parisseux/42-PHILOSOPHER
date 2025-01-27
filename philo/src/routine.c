/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:23:27 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/27 11:16:00 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	if (!arg)
	{
		printf("error: Null pointer passed to thread routine\n");
		pthread_exit(NULL);
	}
	philo = (t_philo *)arg;
	printf("Thread started for philo %d.\n", philo->id);
	printf("philo %d is eating.\n", (*philo).id);
	printf("philo %d is sleeping.\n", (*philo).id);
	printf("philo %d is thinking.\n", (*philo).id);
	return (NULL);
}
