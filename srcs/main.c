/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/11 12:04:06 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/


#include "../includes/philo.h"

void	*routine(void *data)
{
	return (NULL);
}

int	main(int arg_count, char **arg_list)
{
	t_guests	data;
	t_philo		*tail;
	t_philo		*head;
	
	/* CHECKER
	** - Description : check for valid user input
	*/
	if (!valid_user_input(arg_count, arg_list))
		return (EXIT_FAILURE);
	
	/* INIT
	** - Description : initialize the structures (philo and guests)
	*/
	save_user_input(&data, arg_count, arg_list);
	tail = init_philo(&data);

	/* CREATE
	** - Description : create the threads for each philo
	*/
	head = tail->next;
	for (int i = 0; i < data.nbr_of_philo; i++)
	{
		pthread_create(&head->id, NULL, &routine, &data);
		head = head->next;
	}

	/* MONITOR
	** - Description : check the state of each threads
	*/

	/* WAIT
	** - Description : wait for the thrads to finish their tasks
	*/
	head = tail->next;
	for (int j = 0; j < data.nbr_of_philo; j++)
	{
		pthread_join(head->id, NULL);
		head = head->next;
	}

	return (EXIT_SUCCESS);
}
