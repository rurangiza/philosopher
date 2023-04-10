/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/10 14:45:18 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/


#include "../includes/philo.h"

void	*routine()
{
	int	*number = malloc(sizeof(int));
	number[0] = 264;
	return ((void *) number);
}

int	main(int arg_count, char **arg_list)
{
	t_guests	data;
	t_philo		*tail;
	t_philo		*head;

	// Check user input
	if (!valid_user_input(arg_count, arg_list))
		return (EXIT_FAILURE);
	save_user_input(&data, arg_count, arg_list);
	tail = init_philo(&data);

	head = tail->next;
	for (int i = 0; i < data.nbr_of_philo; i++)
	{
		pthread_create(&head->id, NULL, &routine, NULL);
		head = head->next;
	}

	head = tail->next;
	for (int j = 0; j < data.nbr_of_philo; j++)
	{
		pthread_join(head->id, NULL);
		head = head->next;
	}



	// t_philo *tmp = tail->next;
	// while (tmp)
	// {
	// 	printf("At philo (%d)\n", tmp->number);
	// 	tmp = tmp->next;
	// }
	//print_list(&tail);
	return (EXIT_SUCCESS);
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