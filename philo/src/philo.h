/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:20:28 by parissachat       #+#    #+#             */
/*   Updated: 2025/01/27 18:15:47 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				n_philo;
	int				n_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_eat;
	int				stop;
	long long		time_start;
	pthread_mutex_t start_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	int				fork_init;
	int				philo_ready;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	long long		time_last_meal;
	int				n_meal;
	t_data			*data;
}	t_philo;

//setup and check input 
t_data			ft_setup_data(int ac, char **av);
int				ft_check_input(t_data data, int ac);
long			ft_atol(const char *str);
long long		ft_get_starting_time(void);
int				ft_is_positiv_number(char **av, int ac);
void			ft_print_usage(void);
int				ft_setup(t_data *data, t_philo **philo,
					pthread_mutex_t **forks, pthread_t **philo_threads);
pthread_mutex_t	*ft_setup_forks(t_data *data);
t_philo			*ft_setup_philo(t_data *data, pthread_mutex_t *forks);
pthread_t		*ft_setup_threads(t_data *data, t_philo *philo);
void ft_philo_ready(t_data *data);
void ft_monitor_start(t_data *data);
long long ft_get_simulation_time(t_data *data);

//routine
void			*ft_routine(void *arg);
void ft_print_actions(t_philo *philo, int c);

//end
void			ft_join_threads(int n, pthread_t *philo_threads);
void			ft_clean_up(t_data *data, t_philo **philo,
					pthread_mutex_t *forks);
void			ft_destroy_mutex(t_data *data);

#endif