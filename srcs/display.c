/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:21 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/26 12:00:44 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Visual display of program's state
*/

#include "../includes/philo.h"

void	print_msg(t_uniq *philo, char *msg, unsigned int type)
{
	char	*color;
	char	*symbol;

	if (type == DEATH_CURRENT)
	{
		color = CRED;
		symbol = "✘";
	}
	else if (type == DEATH_OTHER)
	{
		color = CYELLOW;
		symbol = "•";
	}
	else
	{
		color = CGREEN;
		symbol = "‣";
	}
	pthread_mutex_lock(&philo->shared_data->lock_stdio);
	if (!other_died(philo) || is_dead(philo))
	{
		printf(CGRAY"%s%s\033[0m %.5ld\033[m ms | philo #%.3d %s%s\033[0m\n",
			color, symbol, ft_calc_timestamp(philo), philo->number, color, msg);
	}
	pthread_mutex_unlock(&philo->shared_data->lock_stdio);
}
