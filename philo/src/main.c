/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:14:51 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/14 16:07:37 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
 
int main(int ac, char **av)
{
	t_data *data;

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
	free(data);
	return (0);
}