/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:23:33 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/14 16:07:54 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	count;
	int	res;

	res = 0;
	count = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		count = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (count == 1)
		return (-res);
	return (res);
}

int	ft_check_input(int ac, char **av, t_data *data)
{
	data->n_philo = ft_atoi(av[1]);
	data->n_fork = data->n_philo;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
	else
		data->n_eat = -1;
	if (data->n_philo < 1 || data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0 || (ac == 6 && data->n_eat <= 0))
		return (0);
	return (1);
}

void	ft_print_usage(void)
{
	printf("Usage: ./philo number_of_philosophers ");
	printf("time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}