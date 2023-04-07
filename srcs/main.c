/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/07 19:08:54 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/


#include "../includes/philo.h"

int	mails = 0;

pthread_mutex_t mutex;

void	*routine2()
{
	// take a fork
	// eat
	// think
	// sleep
	// take a fork
	return (NULL);
}

void	*routine()
{
	int	*number = malloc(sizeof(int));
	number[0] = 264;
	return ((void *) number);
}

int	main(void)
{
	pthread_t	id;
	int			*number;

	//*number = 20;
	//printf("(before) Number = %d\n", *number);
	
	pthread_create(&id, NULL, &routine, NULL);
	pthread_join(id, (void **) &number);

	printf("(after) Number = %d\n", *number);
	free(number);

	system("leaks philo");
	return (EXIT_SUCCESS);
}



// int	main(int arg_count, char **arg_list)
// {
// 	t_global	global;
// 	pthread_t	*thread_id;

// 	// Check user input
// 	if (!valid_user_input(arg_count, arg_list))
// 		return (EXIT_FAILURE);
// 	store_input(&global, arg_count, arg_list);


// 	printf("Numbers of mails: %.d\n", mails);
// 	return (EXIT_SUCCESS);
// }