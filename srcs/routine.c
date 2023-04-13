/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:13 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/13 14:22:33 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* Description
** - this is the starting function of every thread 
** Arguments
** - philo : a structure containing all useful informations
** Return
*/


/*
 * stay alive & think
	- take fork
		- eats (time)
			- release fork
				- sleep, think
*/

void	*start_routine(void *data)
{
	t_uniq	*philo = (t_uniq *) data;
	//int		remaining_meals;

	// printf("Philo [%d] starts eating\n",
	// 		philo->number, philo->shared_data->nbr_of_meals);
	// pthread_mutex_lock(&philo->shared_data->lock);
	// remaining_meals = philo->shared_data->nbr_of_meals;
	// pthread_mutex_unlock(&philo->shared_data->lock);
	
	pthread_mutex_lock(&philo->shared_data->lock);
	int index = philo->shared_data->nbr_of_meals;
	pthread_mutex_unlock(&philo->shared_data->lock);
	
	// Save time: beginning of simulation
	philo->time_of_last_meal = ft_gettime(); //printf("Time %ld sec\n", philo->time_of_last_meal);
	
	while (index > 0)
	{
		/* Check for deaths */
		if (philo->shared_data->nbr_of_deaths > 0)
			exit(1);
		/* Take forks & eat */
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
		index--;
	}

	// while (1)
	// {
	// }
	// pthread_mutex_lock(&philo->shared_data->lock);
	// printf("Thread [%d] : stopped at %d\n",
	// 		philo->number, philo->shared_data->nbr_of_meals);
	// pthread_mutex_unlock(&philo->shared_data->lock);


	return (NULL);
}

void	is_eating(t_uniq *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);
	printf(CGRAY"%ld\033[m philo #%d has taken the fork\n",
				ft_gettime(), philo->number);
	printf(CGRAY"%ld\033[m philo #%d is eating\n",
				ft_gettime(), philo->number);
	usleep(philo->time_to_eat);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
}

void	is_sleeping(t_uniq *philo)
{
	usleep(philo->time_to_sleep);
}

void	is_thinking(t_uniq *philo)
{
	printf(CGRAY"%ld\033[m philo #%d is thinking\n",
				ft_gettime(), philo->number);
}