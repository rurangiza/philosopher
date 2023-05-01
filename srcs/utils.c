/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:29:49 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/01 13:43:42 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	update_time_of_last_meal(t_uniq *philo)
{
	pthread_mutex_lock(&philo->lock_meals_eaten);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->lock_meals_eaten);
	pthread_mutex_lock(&philo->lock_time_access);
	philo->time_of_last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->lock_time_access);
}
