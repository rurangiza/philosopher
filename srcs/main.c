/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/05/01 13:48:40 by arurangi         ###   ########.fr       */
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
	int		i;

	ptr = philo;
	i = 0;
	while (i < shared_data->nbr_of_philo)
	{
		if (pthread_create(&ptr->tid, NULL, &start_routine, (void *) ptr))
			return (error_msg("pthread_create()", "can't create thread",
					EXIT_FAILURE));
		ptr = ptr->next;
		usleep(1000);
		i++;
	}
	if (monitoring(philo, shared_data))
		end_simulation(philo);
	return (EXIT_SUCCESS);
}

void	*start_routine(void *data)
{
	t_uniq	*philo;

	philo = (t_uniq *) data;
	pthread_mutex_lock(&philo->lock_time_access);
	philo->start_time = ft_get_time();
	philo->time_of_last_meal = philo->start_time;
	pthread_mutex_unlock(&philo->lock_time_access);
	while (TRUE)
	{
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
		if (!thinking(philo))
			break ;
	}
	return (NULL);
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
	pthread_mutex_destroy(&philo->shared_data->lock_meals);
	pthread_mutex_destroy(&philo->shared_data->lock_deaths);
	pthread_mutex_destroy(&philo->shared_data->lock_stdio);
	head = philo;
	i = 0;
	while (i < head->shared_data->nbr_of_philo)
	{
		pthread_mutex_destroy(&head->fork);
		pthread_mutex_destroy(&head->lock_time_access);
		pthread_mutex_destroy(&head->lock_meals_eaten);
		i++;
	}
	free(philo->shared_data);
}
