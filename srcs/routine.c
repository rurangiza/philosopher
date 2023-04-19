/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:13 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/19 17:56:44 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	*start_routine(void *data)
{
	t_uniq	*philo = (t_uniq *) data;
	int		meal_counter;

	philo->start_time = ft_get_time();
	philo->time_of_last_meal = philo->start_time;
	pthread_mutex_lock(&philo->shared_data->lock_meals);
	if (philo->shared_data->nbr_of_meals != -1)
	{
		meal_counter = philo->shared_data->nbr_of_meals;
		pthread_mutex_unlock(&philo->shared_data->lock_meals);

		while (meal_counter > 0)
		{
			if (someone_died(philo))
				return (NULL);
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
			meal_counter--;
		}
	}
	else
	{
		pthread_mutex_unlock(&philo->shared_data->lock_meals);
		while (TRUE)
		{
			if (someone_died(philo) > 0)
				exit(1);
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	
	return (NULL);
}

/*
** Eat: take two forks and ft eating
*/
void	ft_eat(t_uniq *philo)
{
	if (philo->number < philo->next->number)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(&philo->next->fork);
	}
	else
	{
		pthread_mutex_lock(&philo->next->fork);
		pthread_mutex_lock(&philo->fork);
	}
	if (any_death(philo->shared_data))
	{
		pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->fork);
		return ;
	}

	print_msg(philo, "has taken a fork [LEFT]", 0);

	print_msg(philo, "is eating", 0);
	//usleep(philo->time_to_eat * 1000);
	ft_delay(philo, philo->time_to_eat);
	
	philo->time_of_last_meal = ft_get_time();

	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);

}

/* 
** Sleep for specified amount of time
*/
void	ft_sleep(t_uniq *philo)
{
	if (any_death(philo->shared_data))
		return ;
	print_msg(philo, "is sleeping", 0);
	usleep(philo->time_to_sleep * 1000);
}

/*
** Think while waiting to eat
*/
void	ft_think(t_uniq *philo)
{
	if (any_death(philo->shared_data))
		return ;
	print_msg(philo, "is thinking", 0);
}