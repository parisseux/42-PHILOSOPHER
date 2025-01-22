/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:12:15 by pchatagn          #+#    #+#             */
/*   Updated: 2025/01/22 16:18:33 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long ft_get_starting_time()
{
    long long time;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    time =  tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return (time);
}