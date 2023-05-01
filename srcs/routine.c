/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:23:00 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/01 15:10:21 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eating(t_uniq *philo)
{
	take_forks(philo);
	if (print_msg(philo, "is eating", 0))
		return (QUIT);
	timer(philo, philo->time_to_eat);
	drop_forks(philo);
	update_time_of_last_meal(philo);
	return (CONTINUE);
}

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

/* ************************************************************************** */

int	sleeping(t_uniq *philo)
{
	if (print_msg(philo, "is sleeping", 0))
		return (QUIT);
	timer(philo, philo->time_to_sleep);
	return (CONTINUE);
}

/* ************************************************************************** */

int	thinking(t_uniq *philo)
{
	if (print_msg(philo, "is thinking", 0))
		return (QUIT);
	return (CONTINUE);
}
