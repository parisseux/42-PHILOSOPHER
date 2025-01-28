/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:15:50 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/28 16:49:08 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_stop_simulation(t_philo *philo)
{
    int i;
    int all_philo_full;

    all_philo_full = 1;
    
    if (philo->data->n_eat > 0)
    {
        i = 0;
        while (i < philo->data->n_philo)
        {
            pthread_mutex_lock(&philo[i].count_meal);
            if (philo[i].n_meal < philo->data->n_eat) 
            {
                all_philo_full = 0; 
                pthread_mutex_unlock(&philo[i].count_meal);
                break ;
            }
            pthread_mutex_unlock(&philo[i].count_meal);
            i++;
        }
        
    }
    if (all_philo_full)
    {
        pthread_mutex_lock(&philo->data->stop_mutex);
        philo->data->stop = 1;
        pthread_mutex_unlock(&philo->data->stop_mutex);
        return (1);
    }
    return (0);
}

void *ft_monitor(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        if (ft_stop_simulation(philo))
            break ;
        usleep(1000);
    }
    return (NULL);
}