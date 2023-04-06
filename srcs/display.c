/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:21 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/06 13:27:17 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Visual display of program's state
*/

#include "../includes/philo.h"

void	display(t_global global)
{
	printf("Number of philosophers = %i\n", global.nbr_of_philo);
	printf("Fasting time = %i\n", global.fasting_time);
	printf("Eating time = %i\n", global.eating_time);
	printf("Sleep time = %i\n", global.sleep_time);
	printf("Max meals = %i\n", global.max_meals);
}