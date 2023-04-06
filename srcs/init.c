/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:28:06 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/06 14:33:53 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	store_input(t_global *global, int arg_count, char **arg_list)
{
	global->nbr_of_philo = ft_atoi(arg_list[1]);
	global->fasting_time = ft_atoi(arg_list[2]);
	global->eating_time = ft_atoi(arg_list[3]);
	global->sleep_time = ft_atoi(arg_list[4]);
	if (arg_count == 6)
		global->max_meals = ft_atoi(arg_list[5]);
	else
		global->max_meals = -1;
}