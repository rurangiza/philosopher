/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/25 13:58:27 by arurangi         ###   ########.fr       */
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
	system("leaks philo");
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
	}
	printf("---> All thread were created\n");
	
	ptr = philo;
	for (int j = 0; j < shared_data->nbr_of_philo; j++)
	{
		if (pthread_join(ptr->tid, NULL))
			return (error_msg("pthread_join()", "can't join thread", EXIT_FAILURE));
		ptr = ptr->next;
	}

	pthread_t	pid_monitoring;
	ptr = philo;
	if (pthread_create(&pid_monitoring, NULL, &start_monitoring, (void *) ptr))
			return (error_msg("pthread_create()", "can't create thread", EXIT_FAILURE));
	if (pthread_join(pid_monitoring, NULL))
			return (error_msg("pthread_join()", "can't join thread", EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

void	end_simulation(t_uniq *philo)
{
	t_uniq	*head;

	pthread_mutex_destroy(&philo->shared_data->lock_meals);
	pthread_mutex_destroy(&philo->shared_data->lock_deaths);
	pthread_mutex_destroy(&philo->shared_data->lock_stdio);
	head = philo;
	for (int i = 0; i < philo->shared_data->nbr_of_philo; i++)
		pthread_mutex_destroy(&head->fork);
	free(philo->shared_data);
	del_list(&philo);
}
