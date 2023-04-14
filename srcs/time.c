/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:56:38 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/14 14:32:46 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_get_time(void)
{
	struct timeval tv;
	long	time_sec;

	gettimeofday(&tv, NULL);
	//time_sec = tv.tv_usec;
	//long long	time = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
	return (time_sec);
}

long	ft_calc_timestamp(t_uniq *philo)
{
	return (ft_get_time() - philo->start_time);
}