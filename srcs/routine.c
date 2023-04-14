/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:13 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/14 11:39:49 by arurangi         ###   ########.fr       */
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
	int		meal_counter;
	
	
	pthread_mutex_lock(&philo->shared_data->lock);
	if (philo->shared_data->nbr_of_meals != -1)
	{
		meal_counter = philo->shared_data->nbr_of_meals;
		pthread_mutex_unlock(&philo->shared_data->lock);

		philo->time_of_last_meal = ft_gettime(); // Save time: beginning of simulation
		while (meal_counter > 0)
		{
			if (someone_died(philo))
				exit(1);
			start_eating(philo);
			start_sleeping(philo);
			start_thinking(philo);
			meal_counter--;
		}
	}
	else
	{
		while (TRUE)
		{
			if (someone_died(philo) > 0)
				exit(1);
			start_eating(philo);
			start_sleeping(philo);
			start_thinking(philo);
		}
	}
	
	return (NULL);
}

int	someone_died(t_uniq *philo)
{
	/* Other philo */ // Critical!!
	pthread_mutex_lock(&philo->shared_data->lock);
	if (philo->shared_data->nbr_of_deaths > 0)
	{
		pthread_mutex_unlock(&philo->shared_data->lock);
		print_msg(philo->number, "other died");
		return (1);
	}
	pthread_mutex_unlock(&philo->shared_data->lock);
	
	/* Current philo */
	if (ft_gettime() - philo->time_of_last_meal > philo->time_to_die)
	{
		pthread_mutex_lock(&philo->shared_data->lock);
		philo->shared_data->nbr_of_deaths++;
		pthread_mutex_unlock(&philo->shared_data->lock);
		print_msg(philo->number, "died");
		return (1);
	}
	return (0);
}

void	start_eating(t_uniq *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->next->fork);

	print_msg(philo->number, "has taken a fork");
	print_msg(philo->number, "is eating");
	usleep(philo->time_to_eat);

	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);

	philo->time_of_last_meal = ft_gettime();
}

void	start_sleeping(t_uniq *philo)
{
	print_msg(philo->number, "is sleeping");
	usleep(philo->time_to_sleep);
}

void	start_thinking(t_uniq *philo)
{
	print_msg(philo->number, "is thinking");
}