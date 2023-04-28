/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitored.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:23:00 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/28 15:04:07 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_routine_mt(void *data)
{
	t_uniq			*philo = (t_uniq *) data;
	unsigned int	mode = INFINIT_BANQUET;

	// init starting time
	pthread_mutex_lock(&philo->lock_time_access);
	philo->start_time = ft_get_time();
	philo->time_of_last_meal = philo->start_time;
	pthread_mutex_unlock(&philo->lock_time_access);

	// set the eating mode
	if (philo->shared_data->nbr_of_meals != -1)
		mode = LIMITED_MEALS;

	// start routine
	while (!other_died(philo) && !is_full(philo, mode))
	{
		if ((eating_mt(philo) * sleeping_mt(philo) * thinking_mt(philo)) == QUIT)
			break ;
		if (mode == LIMITED_MEALS)
			philo->meals_eaten++;
	}
	return (NULL);
}

// void	*start_monitoring(void *data)
// {
// 	t_uniq	*philo = (t_uniq *) data;
// 	int		time_to_die;

// 	pthread_mutex_lock(&philo->lock_time_access);
// 	time_to_die = philo->time_to_die;
// 	pthread_mutex_lock(&philo->lock_time_access);
// 	timer(time_to_die);
// 	while (philo)
// 	{
// 		if (is_dead(philo))
// 			return (NULL);
// 		philo = philo->next;
// 	}
// 	return (NULL);
// }

/* ************************************************************************** */

unsigned int	eating_mt(t_uniq *philo)
{
	take_forks(philo);
	if (other_died(philo) || is_dead(philo))
	{
		drop_forks(philo);
		return (QUIT);
	}
	print_msg(philo, "has taken the forks 🍴", 0);
	print_msg(philo, "is eating 🥘", 0);
	timer(philo->time_to_eat);
	drop_forks(philo);
	if (other_died(philo) || is_dead(philo))
		return (QUIT);
	else
		update_time_of_last_meal(philo);
	return (CONTINUE);
}

unsigned int	sleeping_mt(t_uniq *philo)
{
	if (other_died(philo))
		return (QUIT);
	print_msg(philo, "is sleeping 💤", 0);
	timer(philo->time_to_sleep);
	return (CONTINUE);
}

unsigned int	thinking_mt(t_uniq *philo)
{
	if (other_died(philo))
		return (QUIT);
	print_msg(philo, "is thinking 💭", 0);
	return (CONTINUE);
	
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

void	update_time_of_last_meal(t_uniq *philo)
{
	philo->time_of_last_meal = ft_get_time(); // maybe add mutex
}