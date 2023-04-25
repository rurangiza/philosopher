/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitored.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:23:00 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/25 14:00:11 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_routine_mt(void *data)
{
	t_uniq		*philo = (t_uniq *) data;

	usleep(2000);
	philo->start_time = ft_get_time();
	philo->time_of_last_meal = philo->start_time;
	while (TRUE)
	{
		eating_mt(philo);
		sleeping_mt(philo);
		thinking_mt(philo);
	}
	return (NULL);
}

void	*start_monitoring(void *data)
{
	t_uniq	*philo = (t_uniq *) data;
	
	philo = philo;
	while (philo)
	{
		if (is_dead(philo))
		{
			stop_threads(); // set nbr_of_deaths
			return (NULL);
		}
		philo = philo->next;
	}
}

/* ************************************************************************** */

void	eating_mt(t_uniq *philo)
{
	take_forks(philo);
	print_msg(philo, "has taken the forks", 0);
	print_msg(philo, "is eating", 0);
	timer(philo->time_to_eat);
	drop_forks(philo);
}

void	sleeping_mt(t_uniq *philo)
{
	print_msg(philo, "is sleeping", 0);
	timer(philo->time_to_sleep);
}

void	thinking_mt(t_uniq *philo)
{
	print_msg(philo, "is thinking", 0);
}

/* ************************************************************************** */

void	take_forks(t_uniq *philo)
{
	if (philo->number < philo->next->number)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->next->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		pthread_mutex_lock(&philo->fork);
	}
}

void	drop_forks(t_uniq *philo)
{
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}