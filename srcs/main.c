/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/05/02 20:44:21 by lupin            ###   ########.fr       */
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
	return (EXIT_SUCCESS);
}

int	start_simulation(t_uniq *philo, t_common *shared_data)
{
	t_uniq	*ptr;
	int		i;

	ptr = philo;
	i = 0;
	while (i < shared_data->nbr_of_philo)
	{
		ptr->start_time = shared_data->start_time;
		ptr->time_of_last_meal = ptr->start_time;
		if (pthread_create(&ptr->tid, NULL, &start_routine, (void *) ptr))
			return (error_msg("pthread_create()", "can't create thread",
					EXIT_FAILURE));
		ptr = ptr->next;
		i++;
	}
	msleep(1, "wait: init threads before monitoring");
	if (monitoring(philo, shared_data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	monitoring(t_uniq *philo, t_common *shared_data)
{
	int	index;
	int	meals_count;

	while (TRUE)
	{
		index = 0;
		meals_count = 0;
		while (index < philo->shared_data->nbr_of_philo)
		{
			if (is_dead(philo))
				return (QUIT);
			pthread_mutex_lock(&philo->lock_meals_eaten);
			meals_count += philo->meals_eaten;
			pthread_mutex_unlock(&philo->lock_meals_eaten);
			if (is_full(shared_data, meals_count))
				return (QUIT);
			philo = philo->next;
			index++;
		}
		msleep(1, "wait before checking again");
	}
}

void	end_simulation(t_uniq *philo)
{
	t_uniq	*head;
	int		i;

	head = philo;
	i = 0;
	while (i < philo->shared_data->nbr_of_philo)
	{
		if (pthread_join(head->tid, NULL))
			error_msg("pthread_join()", "can't join thread", EXIT_FAILURE);
		head = head->next;
		i++;
	}
	destroy_mutex_trio(&philo->shared_data->lock_meals,
		&philo->shared_data->lock_deaths, &philo->shared_data->lock_stdio);
	head = philo;
	i = 0;
	while (i < head->shared_data->nbr_of_philo)
	{
		pthread_mutex_unlock(&head->fork);
		destroy_mutex_trio(&head->fork,
			&head->lock_time_access, &head->lock_meals_eaten);
		head = head->next;
		i++;
	}
	free(philo->shared_data);
}
