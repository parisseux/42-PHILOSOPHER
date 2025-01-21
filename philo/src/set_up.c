/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:17:40 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/21 17:58:58 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *ft_setup_philo(t_data *data, pthread_mutex_t *forks)
{
    int i;
    t_philo	*philo;

    i = 0;
    philo = malloc(sizeof(t_philo) * data->n_philo);
    if (!philo)
        return (NULL);
    while (i < data->n_philo)
    {
        philo[i].id = i + 1;
        philo[i].n_meal = 0;
        philo[i].time_last_meal = data->time_start;
        philo[i].data = data;
        philo[i].right_fork = &forks[i];
        if (i == 0)
            philo[i].left_fork = &forks[data->n_philo -1];
        else 
            philo[i].left_fork = &forks[i -1];
        i++;
    }
    return (philo);
}

pthread_mutex_t *ft_setup_forks(t_data *data)
{
    int i;
    pthread_mutex_t *forks;
    
    i = 0;
    forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
    if (!forks)
        return (NULL);
    while (i < data->n_philo)
    {
        pthread_mutex_init(&forks[i], NULL);
		i++;
    }
    return (forks);
}

t_data  ft_setup_data(int ac, char **av)
{
    int	i;
    t_data data;

	i = 1;
	while (i < ac)
	{
		if (ft_is_positiv_number(av[i]) == 0)
			exit(1);
		i++;
	}
    data.n_philo = ft_atoi(av[1]);
	data.n_fork = data.n_philo;
	data.time_to_die = ft_atoi(av[2]);
	data.time_to_eat = ft_atoi(av[3]);
	data.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data.n_eat = ft_atoi(av[5]);
	else
		data.n_eat = -1;
    data.stop = 0;
    pthread_mutex_init(&data.stop_mutex, NULL);
	pthread_mutex_init(&data.print_mutex, NULL);
    pthread_mutex_init(data.forks, NULL);
    return (data);
}

int	ft_setup(t_data *data, t_philo **philo, pthread_mutex_t **forks)
{
    *forks = ft_setup_forks(data);
    if (!*forks)
        return (0);
    *philo = ft_setup_philo(data, *forks);
    if (!*philo)
    {
        free(forks);
        return (0);
    }
    return (1);   
}
