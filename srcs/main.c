/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/06 12:07:26 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/

#include "../includes/philo.h"

void	*routine()
{
	printf("Test from threads [1]\n");
	sleep(3);
	printf("Ending Thread [1]\n");
	return (NULL);
}

void	*routine2()
{
	printf("Test from threads [2]\n");
	sleep(2);
	printf("Ending Thread [2]\n");
	return (NULL);
}

// int	main(int argc, char *argv[])
// {
// 	// Store thread data
// 	pthread_t	t1, t2;
	
// 	(void)argc;
// 	(void)argv;
// 	// Initialize a thread
// 	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
// 		return (1);
// 	if (pthread_create(&t2, NULL, &routine2, NULL) != 0)
// 		return (2);
// 	// Equivalent of waitpid for threads
// 	if (pthread_join(t1, NULL) !=0)
// 		return (1);
// 	if (pthread_join(t2, NULL) != 0)
// 		return (2);
	
// 	return (0);
// }

void	init_data(t_global *global, int arg_count, char **arg_list)
{
	global->nbr_of_philo = ft_atoi(arg_list[1]);
	global->fasting_time = ft_atoi(arg_list[2]);
	global->eating_time = ft_atoi(arg_list[3]);
	global->sleep_time = ft_atoi(arg_list[4]);
	if (arg_count == 6)
		global->max_meals = ft_atoi(arg_list[5]);
	else
		global->max_meals = -1;
	
}

int	main(int arg_count, char **arg_list)
{
	t_global	global;
	if (!valid_user_input(arg_count, arg_list))
		return (EXIT_FAILURE);
	init_data(&global, arg_count, arg_list);
	
	return (EXIT_SUCCESS);
}

/*

When you create a thread,it executes whatever function you 

*/