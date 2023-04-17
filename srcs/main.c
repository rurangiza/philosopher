/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/17 10:39:08 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/

#include "../includes/philo.h"

int	main(int arg_count, char **arg_list)
{
	t_uniq		*tail;

	if (!valid_user_input(arg_count, arg_list))
		return (EXIT_FAILURE);
	tail = init_data(arg_count, arg_list);
	print_hud();
	start_simulation(tail->next, tail->shared_data);
	end_simulation(tail->next);
	return (EXIT_SUCCESS);
}

int	start_simulation(t_uniq *philo, t_common *shared_data)
{
	t_uniq	*ptr;

	ptr = philo;
	for (int i = 0; i < shared_data->nbr_of_philo; i++)
	{
		if (pthread_create(&ptr->tid, NULL, &start_routine, (void *) ptr))
			return (error_msg("pthread_create()", "can't create thread", EXIT_FAILURE));
		//usleep(100);
		ptr = ptr->next;
	}
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
	head = philo;
	for (int i = 0; i < philo->shared_data->nbr_of_philo; i++)
		pthread_mutex_destroy(&head->fork);
}