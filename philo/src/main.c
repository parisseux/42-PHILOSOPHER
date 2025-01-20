/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:14:51 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/20 18:29:14 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 5 || ac > 6)
	{
		ft_print_usage();
		return (1);
	}
	data = malloc(sizeof(t_data));
	memset(data, 0, sizeof(t_data));
	if (ft_check_input(ac, av, data) == 0)
	{
		ft_print_usage();
		free(data);
		return (1);
	}
	// if (!ft_init_philo_fork(data))
	// {
	// 	ft_clean_up(data);
	// 	return (1);
	// }
	ft_clean_up(data);
	return (0);
}
