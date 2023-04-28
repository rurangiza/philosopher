/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/28 17:09:54 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/

#include "../includes/philo.h"

int	main(int arg_count, char **arg_list)
{
	t_uniq	*guests;

	guests = init_data(arg_count, arg_list);
	if (guests == NULL)
		return (EXIT_FAILURE);
	start_simulation(guests->next, guests->shared_data);
	return (EXIT_SUCCESS);
}

int	start_simulation(t_uniq *philo, t_common *shared_data)
{
	t_uniq	*ptr;

	ptr = philo;
	for (int i = 0; i < shared_data->nbr_of_philo; i++)
	{
		if (pthread_create(&ptr->tid, NULL, &start_routine_mt, (void *) ptr))
			return (error_msg("pthread_create()", "can't create thread", EXIT_FAILURE));
		ptr = ptr->next;
		usleep(100);
	}
	if (monitoring(philo))
	{
		printf("--- ending\n");
		end_simulation(philo);
	}
	return (EXIT_SUCCESS);
}

void	end_simulation(t_uniq *philo)
{
	t_uniq	*head;
	t_uniq	*ptr;

	ptr = philo;
	// join all threads
	for (int j = 0; j < philo->shared_data->nbr_of_philo; j++)
	{
		if (pthread_join(ptr->tid, NULL))
			error_msg("pthread_join()", "can't join thread", EXIT_FAILURE);
		ptr = ptr->next;
	}
	// COMMON: destroy mutexes & free ressources
	pthread_mutex_destroy(&philo->shared_data->lock_meals);
	pthread_mutex_destroy(&philo->shared_data->lock_deaths);
	pthread_mutex_destroy(&philo->shared_data->lock_stdio);
	free(philo->shared_data);
	// UNIQ: destroy mutexes & free ressources
	head = philo;
	for (int i = 0; i < head->shared_data->nbr_of_philo; i++)
	{
		pthread_mutex_destroy(&head->fork);
		pthread_mutex_destroy(&head->lock_time_access);
	}
	del_list(&philo);
}

int	monitoring(t_uniq *philo)
{
	int index;

	while (1)
	{
		index = 0;
		while (index < philo->shared_data->nbr_of_philo)
		{
			if (is_dead(philo))
				return (1);
			philo = philo->next;
			index++;
		}
		usleep(100);
	}
}