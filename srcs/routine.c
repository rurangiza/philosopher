/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:13 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/13 12:08:08 by arurangi         ###   ########.fr       */
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
	
	philo->time_of_last_meal = ft_gettime();
	printf("Time %ld sec\n", philo->time_of_last_meal);
	while (index > 0)
	{
		/* ~~~~~~~~~~~ */
		// Check for deaths
		pthread_mutex_unlock(&philo->shared_data->lock);
		if (philo->shared_data->nbr_of_deaths > 0)
			exit(1);
		pthread_mutex_unlock(&philo->shared_data->lock);
		// Check for last meal
		//long time = (ft_gettime() - philo->time_of_last_meal);
		long time = ft_gettime();
		printf("New meal %ld sec\n", time);
		printf("Last (%ld) - New (%ld) = %ld micro seconds\n",
			philo->time_of_last_meal, time, time - philo->time_of_last_meal);
			// if ((gettime() - last_meal) < time_to_die) -> nbr_deaths = 1

		/* ~~~~~~~~~~~ */

		// Eat
		pthread_mutex_lock(&philo->next->fork); // Release the fork
		printf("|_ Philo [%d] has taken a fork\n", philo->number); 
		printf("|_ Philo [%d] is eating\n", philo->number); // eat for [time_to_eat]
		// save meal time
		pthread_mutex_unlock(&philo->next->fork); // Take the fork

		/* ~~~~~~~~~~~ */
		// eat for (philo->shared_data->time_to_eat)
		printf("|_ Philo [%d] is sleeping\n", philo->number);
		printf("|_ Philo [%d] is thinking\n\n", philo->number);
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
