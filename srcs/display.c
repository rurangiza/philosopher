/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:21 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/01 15:08:55 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Visual display of program's state
*/

#include "../includes/philo.h"

int	print_msg(t_uniq *philo, char *msg, unsigned int type)
{
	if (!other_died(philo) || type == DEATH_CURRENT)
	{
		pthread_mutex_lock(&philo->shared_data->lock_stdio);
		printf("%ld %d %s\n", ft_calc_timestamp(philo), philo->number, msg);
		pthread_mutex_unlock(&philo->shared_data->lock_stdio);
		return (0);
	}
	return (1);
}
