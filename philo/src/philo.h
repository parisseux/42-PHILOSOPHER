/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parissachatagny <parissachatagny@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:20:28 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/14 16:03:17 by parissachat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_data
{
	int	n_philo;
	int	n_fork;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_eat;
}	t_data;

//check input
void	ft_print_usage(void);
int		ft_atoi(const char *str);
int		ft_check_input(int ac, char **av, t_data *data);


#endif