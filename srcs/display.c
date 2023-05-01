/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:21 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/01 11:35:53 by arurangi         ###   ########.fr       */
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
	if (!other_died(philo) || type == DEATH_CURRENT)
	{
		pthread_mutex_lock(&philo->shared_data->lock_stdio);
		printf(CGRAY"%s%s\033[0m \033[30m%.5ld ms\033[m philo %.3d %s%s\033[0m\n",
			color, symbol, ft_calc_timestamp(philo), philo->number, color, msg);
		pthread_mutex_unlock(&philo->shared_data->lock_stdio);
	}
}
