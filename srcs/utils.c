/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:29:49 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/02 10:24:34 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_uniq *philo)
{
	if (philo->number < philo->next->number)
	{
		pthread_mutex_lock(&philo->fork);
		print_msg(philo, "has taken the RIGHT fork", 0);
		pthread_mutex_lock(&philo->next->fork);
		print_msg(philo, "has taken the LEFT fork", 0);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		print_msg(philo, "has taken the LEFT fork", 0);
		pthread_mutex_lock(&philo->fork);
		print_msg(philo, "has taken the RIGHT fork", 0);
	}
}

void	drop_forks(t_uniq *philo)
{
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	update_time_of_last_meal(t_uniq *philo)
{
	pthread_mutex_lock(&philo->lock_time_access);
	philo->time_of_last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->lock_time_access);
	pthread_mutex_lock(&philo->lock_meals_eaten);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->lock_meals_eaten);
}
