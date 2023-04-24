/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:13 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/24 14:55:35 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*start_routine(void *data)
{
	t_uniq		*philo = (t_uniq *) data;
	t_common 	*shared_data = philo->shared_data;

	philo->start_time = ft_get_time();
	philo->time_of_last_meal = philo->start_time;
	while (TRUE)
	{
		if (is_dead(philo) || other_died(shared_data))
			exit(QUIT);
		if ((eating(philo) * sleeping(philo) * thinking(philo)) == 0)
			exit(QUIT);
	}
	return (NULL);
}

int	eating(t_uniq *philo)
{
	// Take forks & avoid deadlocks by switching last philo
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
	// 
	print_msg(philo, "has taken the forks", 0);
	print_msg(philo, "is eating", 0);
	timer(philo->time_to_eat);
	// Release forks
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
	return (CONTINUE);
}

int	sleeping(t_uniq *philo)
{
	if (other_died(philo->shared_data))
		return (QUIT);
	print_msg(philo, "is sleeping", 0);
	timer(philo->time_to_sleep);
	return (CONTINUE);
}

int	thinking(t_uniq *philo)
{
	if (other_died(philo->shared_data))
		return (QUIT);
	print_msg(philo, "is thinking", 0);
	return (CONTINUE);
}