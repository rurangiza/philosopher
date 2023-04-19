/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:13:48 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/19 17:33:45 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
 * Check for valid user_input
*/

int	valid_user_input(int arg_count, char **arg_list)
{
	int		index;

	if (arg_count < 5 || arg_count > 6)
		return (err_user(arg_count));
	index = 1;
	while (index < arg_count && arg_list[index])
	{
		if (!ft_is_only_digits(arg_list[index]))
			return (error_msg("user input", "non valid arguments", FALSE));
		index++;
	}
	return (TRUE);
}

/////////////////////////////////////////////////////////////////////////////////

int	ft_is_only_digits(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (ERR_EXISTANCE);
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (FALSE);
		index++;
	}
	return (TRUE);
}

int	ft_isdigit(char ch)
{
	if (ch && (ch >= 48 && ch <= 57))
		return (TRUE);
	return (FALSE);
}

int	someone_died(t_uniq *philo)
{
	pthread_mutex_lock(&philo->shared_data->lock_deaths);
	if (philo->shared_data->nbr_of_deaths > 0)
	{
		pthread_mutex_unlock(&philo->shared_data->lock_deaths);
		return (TRUE);
	}
	else if (ft_get_time() - philo->time_of_last_meal > philo->time_to_die)
	{
		philo->shared_data->nbr_of_deaths++;
		pthread_mutex_unlock(&philo->shared_data->lock_deaths);
		philo->is_alive = FALSE;
		print_msg(philo, "died", DEATH);
		return (TRUE);
	}
	pthread_mutex_unlock(&philo->shared_data->lock_deaths);
	return (FALSE);
}

int	any_death(t_common *shared_data)
{
	pthread_mutex_lock(&shared_data->lock_deaths);
	if (shared_data->nbr_of_deaths > 0)
	{
		pthread_mutex_unlock(&shared_data->lock_deaths);
		return (1);
	}
	pthread_mutex_unlock(&shared_data->lock_deaths);
	return (0);
}
