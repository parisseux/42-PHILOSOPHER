/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:20:28 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/20 18:33:41 by pchatagn         ###   ########.fr       */
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
	int stop;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	print_mutex;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			id_left_fork;
	int			id_right_fork;
	long long	t_last_meal;
	int				n_meal;
	pthread_t			thread_id;
}	t_philo;

typedef struct s_fork
{
	int	id;
}	t_fork;

//check input
void	ft_print_usage(void);
int		ft_atoi(const char *str);
int		ft_check_input(int ac, char **av, t_data *data);
int		ft_is_positiv_number(char *s);

void	ft_clean_up(t_data *data);

#endif