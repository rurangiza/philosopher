/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitored.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:23:00 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/01 12:40:22 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_routine_mt(void *data)
{
	t_uniq			*philo = (t_uniq *) data;

	// init starting time
	pthread_mutex_lock(&philo->lock_time_access);
	philo->start_time = ft_get_time();
	philo->time_of_last_meal = philo->start_time;
	pthread_mutex_unlock(&philo->lock_time_access);

	// start routine
	while (TRUE)
	{
		if (!eating_mt(philo))
			break ;
		if (!sleeping_mt(philo))
			break ;
		if (!thinking_mt(philo))
			break ;
	}
	return (NULL);
}

/* ************************************************************************** */

int	eating_mt(t_uniq *philo)
{
	if (other_died(philo))
			return (QUIT);
	take_forks(philo);
	print_msg(philo, "is eating...........🥘", 0);
	timer(philo, philo->time_to_eat);
	drop_forks(philo);
	update_time_of_last_meal(philo);
	return (CONTINUE);
}

int	sleeping_mt(t_uniq *philo)
{
	if (other_died(philo))
			return (QUIT);
	print_msg(philo, "is sleeping.........💤", 0);
	timer(philo, philo->time_to_sleep);
	return (CONTINUE);
}

int	thinking_mt(t_uniq *philo)
{
	if (other_died(philo))
			return (QUIT);
	print_msg(philo, "is thinking.........💭", 0);
	return (CONTINUE);
}

/* ************************************************************************** */

void	take_forks(t_uniq *philo)
{
	if (philo->number < philo->next->number)
	{
		pthread_mutex_lock(&philo->fork);
		print_msg(philo, "has taken the RIGHT fork 🍴", 0);
		pthread_mutex_lock(&philo->next->fork);
		print_msg(philo, "has taken the LEFT fork 🍴", 0);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		print_msg(philo, "has taken the LEFT fork 🍴", 0);
		pthread_mutex_lock(&philo->fork);
		print_msg(philo, "has taken the RIGHT fork 🍴", 0);
	}
}

void	drop_forks(t_uniq *philo)
{
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	update_time_of_last_meal(t_uniq *philo)
{
	pthread_mutex_lock(&philo->lock_meals_eaten);
	philo->meals_eaten++; // mutex add ???
	pthread_mutex_unlock(&philo->lock_meals_eaten);

	pthread_mutex_lock(&philo->lock_time_access);
	philo->time_of_last_meal = ft_get_time(); // maybe add mutex
	pthread_mutex_unlock(&philo->lock_time_access);
}