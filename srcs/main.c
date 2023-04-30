/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/30 11:36:24 by lupin            ###   ########.fr       */
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
		usleep(1000);
	}
	if (monitoring(philo, shared_data))
		end_simulation(philo);
	return (EXIT_SUCCESS);
}

void	end_simulation(t_uniq *philo)
{
	t_uniq	*head;
	t_uniq	*ptr;

	ptr = philo;
	// join all threads
	//printf("|_ join all threads\n");
	for (int j = 0; j < philo->shared_data->nbr_of_philo; j++)
	{
		if (pthread_join(ptr->tid, NULL))
			error_msg("pthread_join()", "can't join thread", EXIT_FAILURE);
		ptr = ptr->next;
	}
	// COMMON: destroy mutexes & free ressources
	//printf("|_ destroy COMMON data\n");
	pthread_mutex_destroy(&philo->shared_data->lock_meals);
	pthread_mutex_destroy(&philo->shared_data->lock_deaths);
	pthread_mutex_destroy(&philo->shared_data->lock_stdio);
	// UNIQ: destroy mutexes & free ressources
	//printf("|_ destroy UNIQ data\n");
	head = philo;
	for (int i = 0; i < head->shared_data->nbr_of_philo; i++)
	{
		pthread_mutex_destroy(&head->fork);
		pthread_mutex_destroy(&head->lock_time_access);
		pthread_mutex_destroy(&head->lock_meals_eaten);
	}
	free(philo->shared_data);
	//del_list(&philo);
}

int	monitoring(t_uniq *philo, t_common *shared_data)
{
	int index;
	int	meals_count;

	while (TRUE)
	{
		index = 0;
		meals_count = 0;
		while (index < philo->shared_data->nbr_of_philo)
		{
			if (is_dead(philo))
				return (1);
			pthread_mutex_lock(&philo->lock_meals_eaten);
			meals_count += philo->meals_eaten;
			pthread_mutex_unlock(&philo->lock_meals_eaten);
			if (is_full(shared_data, meals_count))
				return (1);
			philo = philo->next;
			index++;
		}
		usleep(100);
	}
}
