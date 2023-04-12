/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:13 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/12 17:09:45 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* Description
** - this is the starting function of every thread 
** Arguments
** - philo : a structure containing all useful informations
** Return
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
	while (index > 0)
	{
		printf("|_ Philo [%d] has taken a fork\n", philo->number);
		printf("|_ Philo [%d] is eating\n", philo->number);
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
