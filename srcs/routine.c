/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:23:00 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/02 20:25:45 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_routine(void *data)
{
	t_uniq	*philo;

	philo = (t_uniq *) data;
	if (philo->number % 2 == 0)
		msleep(1, "odd & even eat seperatly");
	while (TRUE)
	{
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}

/* ************************************************************************** */

int	eating(t_uniq *philo)
{
	take_forks(philo);
	if (print_msg(philo, "is eating", 0))
		return (QUIT);
	timer(philo, philo->time_to_eat);
	update_time_of_last_meal(philo);
	drop_forks(philo);
	return (CONTINUE);
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
