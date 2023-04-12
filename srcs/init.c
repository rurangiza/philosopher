/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:28:06 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/12 17:00:19 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	save_user_input(t_common *data, int arg_count, char **arg_list)
{
	data->nbr_of_philo = ft_atoi(arg_list[1]);
	data->time_to_die = ft_atoi(arg_list[2]);
	data->time_to_eat = ft_atoi(arg_list[3]);
	data->time_to_sleep = ft_atoi(arg_list[4]);
	if (arg_count == 6)
		data->nbr_of_meals = ft_atoi(arg_list[5]);
	else
		data->nbr_of_meals = -1;
	pthread_mutex_init(&data->lock, NULL);
}

t_uniq	*init_philo(t_common *data)
{
	int		index;
	t_uniq	*last;

	last = NULL;
	index = 0;

	while (index < data->nbr_of_philo)
	{
		add_philo(&last, index + 1);
		pthread_mutex_init(&last->fork, NULL);
		last->shared_data = data;
		index++;
	}
	return (last);
}
