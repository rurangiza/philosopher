/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:28:06 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/17 19:18:51 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_uniq	*init_data(int arg_count, char **arg_list)
{
	t_common	*shared_data;
	t_uniq		*philo;
	int			counter;
	
	shared_data = init_shared_data(arg_count, arg_list);
	if (!shared_data)
		return (NULL);
	counter = 0;
	philo = NULL;
	while (counter < shared_data->nbr_of_philo)
	{
		add_node_to_cllist(&philo);
		init_philo(philo, shared_data, arg_list, counter);
		counter++;
	}
	return (philo);
}

void	init_philo(t_uniq *philo, t_common *shared_data, char **arg_list, int counter)
{
	philo->number = counter+1;
	philo->time_to_die = ft_atoi(arg_list[2]);
	philo->time_to_eat = ft_atoi(arg_list[3]);
	philo->time_to_sleep = ft_atoi(arg_list[4]);
	pthread_mutex_init(&philo->fork, NULL);
	philo->is_alive = TRUE;
	philo->time_of_last_meal = 0;
	philo->start_time = 0;
	philo->shared_data = shared_data;
}

t_common	*init_shared_data(int arg_count, char **arg_list)
{
	t_common	*data;

	data = malloc(sizeof(t_common));
	if (!data)
		return (NULL);
	data->nbr_of_philo = ft_atoi(arg_list[1]);
	if (arg_count == 6)
		data->nbr_of_meals = ft_atoi(arg_list[5]);
	else
		data->nbr_of_meals = -1;
	data->nbr_of_deaths = 0;
	pthread_mutex_init(&data->lock_meals, NULL);
	pthread_mutex_init(&data->lock_deaths, NULL);
	pthread_mutex_init(&data->lock_stdio, NULL);
	return (data);
}
