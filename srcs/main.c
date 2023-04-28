/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/28 16:12:59 by arurangi         ###   ########.fr       */
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
	end_simulation(guests->next);
	//system("leaks philo");
	return (EXIT_SUCCESS);
}

int	start_simulation(t_uniq *philo, t_common *shared_data)
{
	t_uniq	*ptr;

	// Creatign threads
	ptr = philo;
	for (int i = 0; i < shared_data->nbr_of_philo; i++)
	{
		if (pthread_create(&ptr->tid, NULL, &start_routine_mt, (void *) ptr))
			return (error_msg("pthread_create()", "can't create thread", EXIT_FAILURE));
		ptr = ptr->next;
	}

	// Exiting threads
	ptr = philo;
	for (int j = 0; j < shared_data->nbr_of_philo; j++)
	{
		if (pthread_join(ptr->tid, NULL))
			return (error_msg("pthread_join()", "can't join thread", EXIT_FAILURE));
		ptr = ptr->next;
	}
	return (EXIT_SUCCESS);
}

void	end_simulation(t_uniq *philo)
{
	t_uniq	*head;

	pthread_mutex_destroy(&philo->shared_data->lock_meals);
	pthread_mutex_destroy(&philo->shared_data->lock_deaths);
	pthread_mutex_destroy(&philo->shared_data->lock_stdio);
	free(philo->shared_data);

	head = philo;
	for (int i = 0; i < head->shared_data->nbr_of_philo; i++)
	{
		pthread_mutex_destroy(&head->fork);
		pthread_mutex_destroy(&head->lock_time_access);
	}
	del_list(&philo);
}

/*

// pthread_create(&ptr->tid, NULL, &start_routine_mt, (void *) ptr);
	// pthread_join(ptr->tid, NULL);

	// Monitoring
	// int index = 0;
	// usleep(1000);
	// while (1)
	// {
	// 	ptr = philo;
	// 	int mortality = 0;
	// 	while (index < shared_data->nbr_of_philo)
	// 	{
	// 		pthread_mutex_lock(&philo->lock_time_access);
	// 		if (ptr->is_alive == FALSE)
	// 			mortality++;
	// 		pthread_mutex_unlock(&philo->lock_time_access);
	// 		ptr = ptr->next;
	// 		index++;
	// 	}
	// 	if (mortality == shared_data->nbr_of_philo)
	// 		break ;
	// 	usleep(1000);
	// }

*/