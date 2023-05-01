/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:28:06 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/01 15:25:20 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_uniq	*init_data(int arg_count, char **arg_list)
{
	t_common	*shared_data;
	t_uniq		*philo;
	int			counter;

	if (!valid_user_input(arg_count, arg_list))
		return (NULL);
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

void	init_philo(t_uniq *philo, t_common *shared_data,
	char **arg_list, int counter)
{
	philo->number = counter + 1;
	philo->time_to_die = ft_atoi(arg_list[2]);
	philo->time_to_eat = ft_atoi(arg_list[3]);
	philo->time_to_sleep = ft_atoi(arg_list[4]);
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->lock_time_access, NULL);
	pthread_mutex_init(&philo->lock_meals_eaten, NULL);
	philo->time_of_last_meal = 0;
	philo->shared_data = shared_data;
	philo->meals_eaten = 0;
}

t_common	*init_shared_data(int arg_count, char **arg_list)
{
	t_common	*data;

	data = malloc(sizeof(t_common));
	if (!data)
		return (NULL);
	data->nbr_of_philo = ft_atoi(arg_list[1]);
	if (data->nbr_of_philo == 1)
	{
		printf("0 1 has taken a fork [RIGHT]\n");
		printf("%ld 1 died\n", ft_atoi(arg_list[2]));
		return (NULL);
	}
	if (arg_count == 6)
		data->nbr_of_meals = ft_atoi(arg_list[5]);
	else
		data->nbr_of_meals = -1;
	data->nbr_of_deaths = 0;
	pthread_mutex_init(&data->lock_meals, NULL);
	pthread_mutex_init(&data->lock_deaths, NULL);
	pthread_mutex_init(&data->lock_stdio, NULL);
	data->start_time = ft_get_time();
	return (data);
}
