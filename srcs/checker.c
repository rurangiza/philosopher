/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:13:48 by Arsene            #+#    #+#             */
/*   Updated: 2023/05/01 14:34:01 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	other_died(t_uniq *philo)
{
	pthread_mutex_lock(&philo->shared_data->lock_deaths);
	if (philo->shared_data->nbr_of_deaths > 0)
	{
		pthread_mutex_unlock(&philo->shared_data->lock_deaths);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->shared_data->lock_deaths);
	return (FALSE);
}

int	is_dead(t_uniq *philo)
{
	pthread_mutex_lock(&philo->lock_time_access);
	if (ft_get_time() - philo->time_of_last_meal > philo->time_to_die)
	{
		pthread_mutex_unlock(&philo->lock_time_access);
		pthread_mutex_lock(&philo->shared_data->lock_deaths);
		philo->shared_data->nbr_of_deaths++;
		pthread_mutex_unlock(&philo->shared_data->lock_deaths);
		print_msg(philo, "died", DEATH_CURRENT);
		return (TRUE);
	}
	else
		pthread_mutex_unlock(&philo->lock_time_access);
	return (FALSE);
}

int	is_full(t_common *shared_data, int meals_count)
{
	if (shared_data->nbr_of_meals != -1)
	{
		if (meals_count >= (shared_data->nbr_of_philo
				* shared_data->nbr_of_meals))
		{
			pthread_mutex_lock(&shared_data->lock_deaths);
			shared_data->nbr_of_deaths++;
			pthread_mutex_unlock(&shared_data->lock_deaths);
			return (TRUE);
		}
		return (FALSE);
	}
	return (0);
}
