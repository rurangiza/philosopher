/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:28:06 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/13 14:13:59 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	init_common(t_common *data, int arg_count, char **arg_list)
// {
// 	//data->nbr_of_philo = ft_atoi(arg_list[1]);
// 	data->time_to_die = ft_atoi(arg_list[2]);
// 	data->time_to_eat = ft_atoi(arg_list[3]);
// 	data->time_to_sleep = ft_atoi(arg_list[4]);

// 	if (arg_count == 6)
// 		data->nbr_of_meals = ft_atoi(arg_list[5]);
// 	else
// 		data->nbr_of_meals = -1;
// 	data->nbr_of_deaths = 0;
// 	pthread_mutex_init(&data->lock, NULL);
// }

// t_uniq	*init_philo(t_common *data)
// {
// 	int		index;
// 	t_uniq	*last;

// 	last = NULL;
// 	index = 0;

// 	while (index < data->nbr_of_philo)
// 	{
// 		add_philo(&last, index + 1);
// 		pthread_mutex_init(&last->fork, NULL);
// 		last->shared_data = data;
// 		index++;
// 	}
// 	return (last);
// }

int	init_shared(t_common *shared_data, int arg_count, char **arg_list)
{
	shared_data = malloc(sizeof(t_common));
	if (!shared_data)
		return (1);
	shared_data->nbr_of_philo = ft_atoi(arg_list[1]);
	if (arg_count == 6)
		shared_data->nbr_of_meals = ft_atoi(arg_list[5]);
	else
		shared_data->nbr_of_meals = -1;
	shared_data->nbr_of_deaths = 0;
	pthread_mutex_init(&shared_data->lock, NULL);
	return (0);
}

t_uniq	*init_data(int arg_count, char **arg_list)
{
	t_common	shared_data;
	t_uniq		*philo;
	int			index;
	
	if (init_shared(&shared_data, arg_count, arg_list))
		return (NULL);
	index = 0;
	philo = NULL;
	while (index < shared_data.nbr_of_philo)
	{
		add_node(&philo);
		philo->number = index+1;
		philo->time_to_die = ft_atoi(arg_list[2]);
		philo->time_to_eat = ft_atoi(arg_list[3]);
		philo->time_to_sleep = ft_atoi(arg_list[4]);
		pthread_mutex_init(&philo->fork, NULL);
		philo->shared_data = &shared_data;
		index++;
	}
	return (philo);
}

