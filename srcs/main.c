/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/10 11:55:30 by arurangi         ###   ########.fr       */
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

// int	main(void)
// {
// 	pthread_t	id;
// 	int			*number;

// 	//*number = 20;
// 	//printf("(before) Number = %d\n", *number);

// 	pthread_create(&id, NULL, &routine, NULL);
// 	pthread_join(id, (void **) &number);

// 	printf("(after) Number = %d\n", *number);
// 	free(number);

// 	system("leaks philo");
// 	return (EXIT_SUCCESS);
// }



int	main(int arg_count, char **arg_list)
{
	t_guests	data;
	t_philo		*last;

	// Check user input
	if (!valid_user_input(arg_count, arg_list))
		return (EXIT_FAILURE);
	save_user_input(&data, arg_count, arg_list);
	last = init_philo(&data);
	print_list(&last);
	return (EXIT_SUCCESS);
}