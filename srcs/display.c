/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:21 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/17 10:22:16 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Visual display of program's state
*/

#include "../includes/philo.h"

void	display(t_common *data)
{	
	printf("\n* *****************************\n");
	printf("* Number of philosophers = %i\n", data->nbr_of_philo);
	printf("* Max meals = %i\n", data->nbr_of_meals);
	printf("* *****************************\n\n");
}

void	print_msg(t_uniq *philo, char *msg)
{
	char	*color;
	char	*symbol;

	if (ft_strncmp("died", msg, 4) == 0)
	{
		color = CRED;
		symbol = "✘";
	}
	else if (ft_strncmp("other died", msg, 10) == 0)
	{
		color = CYELLOW;
		symbol = "⦿";
	}
	else
	{
		color = CGREEN;
		symbol = "⦿";
	}
	pthread_mutex_lock(&philo->shared_data->lock_stdio);
	printf(CGRAY"%s%s\033[0m %ld\033[m ms | philo #%.3d %s%s\033[0m\n",
		color, symbol, ft_calc_timestamp(philo), philo->number, color, msg);
	pthread_mutex_unlock(&philo->shared_data->lock_stdio);
	// printf("   %.7ld          #%d         %s\n",
	// 	ft_calc_timestamp(philo), philo->number, msg);
}

void	print_hud(void)
{
	write(STDOUT_FILENO, "┏------------------------------------------------┓\n", 55);
	write(STDOUT_FILENO, "|   TIME   |   PHILOSOPHER   |       EVENT       |\n", 51);
	write(STDOUT_FILENO, "┗------------------------------------------------┛\n", 55);
}