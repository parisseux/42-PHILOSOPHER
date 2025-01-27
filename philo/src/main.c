/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:14:51 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/27 12:10:01 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data			data;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_t		*philo_threads;

	philo_threads = NULL;
	forks = NULL;
	philo = NULL;
	if (ac < 5 || ac > 6)
	{
		ft_print_usage();
		return (1);
	}
	data = ft_setup_data(ac, av);
	if (ft_check_input(data, ac) == 0)
	{
		ft_destroy_mutex(&data);
		return (1);
	}
	if (!ft_setup(&data, &philo, &forks, &philo_threads))
	{
		printf("Error: setup failed!\n");
		ft_clean_up(&data, &philo, forks);
		return (1);
	}
	ft_join_threads(data.n_philo, philo_threads);
	ft_clean_up(&data, &philo, forks);
	free(philo_threads);
	return (0);
}
