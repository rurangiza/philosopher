/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:21 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/17 15:12:42 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Visual display of program's state
*/

#include "../includes/philo.h"

void	counterfn(void);

// void	display(void)
// {	
// 	char *text[] = {
// 		"Starting simulation .  ",
// 		"Starting simulation .. ",
// 		"Starting simulation ...",
// 		"Starting simulation .  ",
// 		"Starting simulation .. ",
// 		"Starting simulation ..."};
// 	int i = 0;
// 	write(1, "\n", 1);
// 	while (i < 6)
// 	{
// 		if (i == 0)
// 			write(1, text[i], ft_strlen(text[i]));
// 		else
// 		{
// 			write(1, "\033[19D", 20);
// 			write(1, text[i], ft_strlen(text[i]));
// 		}
// 		i++;
// 		usleep(1000000);
// 	}
// 	printf("\n");
// }


void	counterfn(void)
{
	printf(CBOLD"\nCount down :  \n"CRESET);
	usleep(500000);
	// printf("3\n");
	// usleep(1000000);
	// printf("2\n");
	// usleep(1000000);
	// printf("1\n");
	// usleep(1000000);
	// printf("0\n");
	int counter = 3;
	while (counter >= 0)
	{
		printf(CRED"\b%i\n"CRESET, counter);
		counter--;
		usleep(1000000);
	}
	write(1, "\n", 1);
	usleep(500000);
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
	if (!any_death(philo->shared_data)
		|| (any_death(philo->shared_data) && philo->is_alive == FALSE))
	{
		printf(CGRAY"%s%s\033[0m %.5ld\033[m ms | philo #%.3d %s%s\033[0m\n",
			color, symbol, ft_calc_timestamp(philo), philo->number, color, msg);
	}
	pthread_mutex_unlock(&philo->shared_data->lock_stdio);
}

void	print_hud(void)
{
	write(STDOUT_FILENO, "┏------------------------------------------------┓\n", 55);
	write(STDOUT_FILENO, "|   TIME   |   PHILOSOPHER   |       EVENT       |\n", 51);
	write(STDOUT_FILENO, "┗------------------------------------------------┛\n", 55);
	usleep(2000000);
}