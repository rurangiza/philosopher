/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:21 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/13 10:44:18 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Visual display of program's state
*/

#include "../includes/philo.h"

void	display(t_common data)
{	
	printf("\n* *****************************\n");
	printf("* Number of philosophers = %i\n", data.nbr_of_philo);
	printf("* time_to_die : %i\n", data.time_to_die);
	printf("* time_to_eat = %i\n", data.time_to_eat);
	printf("* time_to_sleep = %i\n", data.time_to_sleep);
	printf("* Max meals = %i\n", data.nbr_of_meals);
	printf("* *****************************\n\n");
}
