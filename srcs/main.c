/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/06 15:49:43 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/


#include "../includes/philo.h"

int	mails = 0;

void	*routine()
{
	for (int i = 0; i < 1500; i++)
		mails++;
	return (NULL);
}

int	main(int arg_count, char **arg_list)
{
	t_global	global;
	pthread_t	t1, t2;

	if (MODE)
	{
		if (!valid_user_input(arg_count, arg_list))
			return (EXIT_FAILURE);
		store_input(&global, arg_count, arg_list);
	}
	

	if (pthread_create(&t1, NULL, &routine, NULL))
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL))
		return (2);
	
	if (pthread_join(t1, NULL))
		return (1);
	if (pthread_join(t2, NULL))
		return (1);

	printf("Numbers of mails: %d\n", mails);
	
	// pid_t pid = fork();
	// if (pid < 0)
	// 	return (1);
	// printf("Process ID [%i]\n", getpid());
	// if (pid > 0)
	// 	wait(NULL);
	
	return (EXIT_SUCCESS);
}
