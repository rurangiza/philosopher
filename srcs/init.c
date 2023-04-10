/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:28:06 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/10 14:47:12 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	save_user_input(t_guests *data, int arg_count, char **arg_list)
{
	data->nbr_of_philo = (int) ft_atoi(arg_list[1]);
	data->fasting_time = (int) ft_atoi(arg_list[2]);
	data->eating_time = (int) ft_atoi(arg_list[3]);
	data->sleep_time = (int) ft_atoi(arg_list[4]);
	if (arg_count == 6)
		data->max_meals = (int) ft_atoi(arg_list[5]);
	else
		data->max_meals = -1;
}

t_philo	*init_philo(t_guests *data)
{
	int		index;
	t_philo	*last;

	last = NULL;
	index = 0;
	while (index < data->nbr_of_philo)
	{
		add_philo(&last, index+1);
		pthread_mutex_init(&last->fork, NULL);
		index++;
	}
	return (last);
}
