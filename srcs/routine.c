/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:29:13 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/12 12:02:34 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* Description
** - this is the starting function of every thread 
** Arguments
** - philo : a structure containing all useful informations
** Return
*/
void	*start_routine(void *data)
{
	t_uniq	*philo = (t_uniq *) data;

	pthread_mutex_lock(&philo->shared_data->lock);

	printf("Thread [%d] : starts counting at %d\n",
			philo->number, counter);
	for (int i = 0; i < 100000; i++)
		counter++;
	printf("Thread [%d] : stopped at %d\n",
			philo->number, counter);

	pthread_mutex_unlock(&philo->shared_data->lock);

	return (NULL);
}
