/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:56:38 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/01 16:19:49 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

time_t	ft_calc_timestamp(t_uniq *philo)
{
	return (ft_get_time() - philo->start_time);
}

void	timer(t_uniq *philo, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = ft_get_time() + sleep_time;
	while (ft_get_time() < wake_up)
	{
		if (other_died(philo))
			break ;
		usleep(100);
	}
}

void	msleep(time_t time, char *msg)
{
	(void)msg;
	usleep(time * 1000);
}
