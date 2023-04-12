/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:21 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/12 11:22:53 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Visual display of program's state
*/

#include "../includes/philo.h"

void	display(t_common data)
{
	printf("Number of philosophers = %i\n", data.nbr_of_philo);
	printf("Fasting time = %i\n", data.fasting_time);
	printf("Eating time = %i\n", data.eating_time);
	printf("Sleep time = %i\n", data.sleep_time);
	printf("Max meals = %i\n", data.max_meals);
}
