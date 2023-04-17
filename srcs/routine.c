/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:13 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/17 10:44:15 by Arsene           ###   ########.fr       */
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

	philo->time_of_last_meal = ft_get_time(); // Save time: beginning of simulation
	pthread_mutex_lock(&philo->shared_data->lock_meals);
	if (philo->shared_data->nbr_of_meals != -1)
	{
		meal_counter = philo->shared_data->nbr_of_meals;
		pthread_mutex_unlock(&philo->shared_data->lock_meals);

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
		pthread_mutex_unlock(&philo->shared_data->lock_meals);
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
	pthread_mutex_lock(&philo->shared_data->lock_deaths);
	if (philo->shared_data->nbr_of_deaths > 0)
	{
		pthread_mutex_unlock(&philo->shared_data->lock_deaths);
		print_msg(philo, "other died");
		return (TRUE);
	}
	else if (ft_get_time() - philo->time_of_last_meal > philo->time_to_die)
	{
		philo->shared_data->nbr_of_deaths++;
		pthread_mutex_unlock(&philo->shared_data->lock_deaths);
		print_msg(philo, "died");
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->shared_data->lock_deaths);
	return (FALSE);
}

void	start_eating(t_uniq *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_msg(philo, "has taken a fork [RIGHT]");

	pthread_mutex_lock(&philo->next->fork);
	print_msg(philo, "has taken a fork [LEFT]");

	print_msg(philo, "is eating");
	usleep(philo->time_to_eat);

	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);

	philo->time_of_last_meal = ft_get_time();
}

void	start_sleeping(t_uniq *philo)
{
	print_msg(philo, "is sleeping");
	usleep(philo->time_to_sleep);
}

void	start_thinking(t_uniq *philo)
{
	print_msg(philo, "is thinking");
}