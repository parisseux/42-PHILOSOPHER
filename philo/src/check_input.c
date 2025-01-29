/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:23:33 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/29 17:40:40 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	return (res);
}

int	ft_is_positiv_number(char **av, int ac)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		if (av[j][0] == '+')
			i++;
		while (av[j][i])
		{
			if (!(av[j][i] >= '0' && av[j][i] <= '9'))
			{
				ft_print_usage();
				return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_check_input(t_data data, int ac)
{
	if (data.n_philo < 1 || data.n_philo > 200)
	{
		printf("Error: Invalid number of philosophers.\n");
		printf("Must be greater than 0 and smaller than 200.\n");
		return (0);
	}
	if ((data.time_to_die <= 0) || (data.time_to_die > 60000)
		|| (data.time_to_eat <= 0) || (data.time_to_eat > 60000)
		|| (data.time_to_sleep <= 0) || (data.time_to_sleep > 60000))
	{
		printf("Error: Times must be betweem 0 ms and 1 min.\n");
		return (0);
	}
	if (ac == 6 && (data.n_eat <= 0 || data.n_eat > 200))
	{
		printf("Error: Invalid meal count (%d).\n", data.n_eat);
		printf("Must be greater than 0 and smaller than 200.\n");
		return (0);
	}
	return (1);
}

void	ft_print_usage(void)
{
	printf("Usage: ./philo number_of_philosophers ");
	printf("time_to_die time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
	exit (1);
}
