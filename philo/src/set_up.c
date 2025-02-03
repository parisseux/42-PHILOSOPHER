/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:17:40 by pchatagn          #+#    #+#             */
/*   Updated: 2025/02/03 17:28:46 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	ft_setup_data(int ac, char **av)
{
	t_data	data;

	if (ft_is_positiv_number(av, ac) == 0)
		exit(1);
	data.n_philo = (int)ft_atol(av[1]);
	data.time_to_die = (int)ft_atol(av[2]);
	data.time_to_eat = (int)ft_atol(av[3]);
	data.time_to_sleep = (int)ft_atol(av[4]);
	if (ac == 6)
		data.n_eat = (int)ft_atol(av[5]);
	else
		data.n_eat = -1;
	data.stop = 0;
	data.fork_init = 0;
	data.philo_ready = 0;
	data.time_start = 0;
	pthread_mutex_init(&data.start_mutex, NULL);
	pthread_mutex_init(&data.stop_mutex, NULL);
	pthread_mutex_init(&data.print_mutex, NULL);
	return (data);
}

t_philo	*ft_setup_philo(t_data *data, pthread_mutex_t *forks)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!philo)
	{
		printf("Error: Memory allocation for philosophers failed\n");
		return (NULL);
	}
	i = 0;
	while (i < data->n_philo)
	{
		philo[i].id = i + 1;
		philo[i].n_meal = 0;
		philo[i].time_last_meal = data->time_start;
		philo[i].data = data;
		philo[i].right_fork = &forks[i];
		if (i == 0)
			philo[i].left_fork = &forks[data->n_philo - 1];
		else
			philo[i].left_fork = &forks[i - 1];
		pthread_mutex_init(&philo[i].count_meal, NULL);
		pthread_mutex_init(&philo[i].last_meal, NULL);
		i++;
	}
	return (philo);
}

pthread_mutex_t	*ft_setup_forks(t_data *data)
{
	int				i;
	int				j;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!forks)
	{
		printf("Error: allocation of forks failed.\n");
		return (NULL);
	}
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("Error: Mutex initialization failed for fork %d.\n", i);
			j = 0;
			while (j < i)
			{
				pthread_mutex_destroy(&forks[j]);
				j++;
			}
			free(forks);
			return (NULL);
		}
		i++;
	}
	data->fork_init = 1;
	return (forks);
}

pthread_t	*ft_setup_threads(t_data *data)
{
	pthread_t	*philo_threads;

	philo_threads = malloc(sizeof(pthread_t) * data->n_philo);
	if (!philo_threads)
	{
		printf("Error: Threads allocation failed.\n");
		return (NULL);
	}
	return (philo_threads);
}

void	ft_create_threads(t_philo *philo, pthread_t *philo_threads, pthread_t *monitor_thread)
{
	int	i;
	
	i = 0;
	while (i < philo->data->n_philo)
	{
		pthread_create(&philo_threads[i], NULL, ft_monitor_start, (void *)&philo[i]);
		pthread_mutex_lock(&philo[i].data->start_mutex);
		philo->data->philo_ready++;
		pthread_mutex_unlock(&philo[i].data->start_mutex);
		i++;
	}
	pthread_create(monitor_thread, NULL, ft_monitor, (void *)philo);
}

void ft_join_threads(t_philo *philo, pthread_t *philo_threads, pthread_t monitor_thread)
{
	int i;

	i = 0;
	while (i < philo->data->n_philo)
	{
		pthread_join(philo_threads[i], NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	
}

int	ft_setup(t_data *data, t_philo **philo,
			pthread_mutex_t **forks, pthread_t **philo_threads)
{
	pthread_t monitor_thread;

	*forks = ft_setup_forks(data);
	if (!*forks)
		return (0);
	*philo = ft_setup_philo(data, *forks);
	if (!*philo)
		return (0);
	*philo_threads = ft_setup_threads(data);
	if (!*philo_threads)
		return (0);
	ft_create_threads(*philo, *philo_threads, &monitor_thread);
	ft_join_threads(*philo, *philo_threads, monitor_thread);
	return (1);
}
