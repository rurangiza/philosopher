/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:21 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/26 08:01:39 by Arsene           ###   ########.fr       */
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
	printf("--- locking stdin (philo %d)\n", philo->number);
	pthread_mutex_lock(&philo->shared_data->lock_stdio);
	if (!other_died(philo) || is_dead(philo))
	{
		printf(CGRAY"%s%s\033[0m %.5ld\033[m ms | philo #%.3d %s%s\033[0m\n",
			color, symbol, ft_calc_timestamp(philo), philo->number, color, msg);
	}
	pthread_mutex_unlock(&philo->shared_data->lock_stdio);
	printf("--- unlocking stdin (philo %d)\n", philo->number);
}

void	print_hud(void)
{
	write(STDOUT_FILENO, "┏------------------------------------------------┓\n", 55);
	write(STDOUT_FILENO, "|   TIME   |   PHILOSOPHER   |       EVENT       |\n", 51);
	write(STDOUT_FILENO, "┗------------------------------------------------┛\n", 55);
	usleep(2000000);
}