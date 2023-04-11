/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/11 17:10:42 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/

#include "../includes/philo.h"



int	main(int arg_count, char **arg_list)
{
	t_guests	data;
	t_philo		*tail;
	t_philo		*head;
	int			status;
	pthread_t	*id;

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
	id = malloc(data.nbr_of_philo * sizeof(pthread_t));

	/* CREATE
	** - Description : create the threads for each philo
	*/
	head = tail->next;
	for (int i = 0; i < data.nbr_of_philo; i++)
	{
		status = pthread_create(&id[i], NULL, &routine, (void *) head);
		if (status > 0)
			return (error_msg("pthread_create", "couldn't create thread", EXIT_FAILURE));
		usleep(100000);
		head = head->next;
	}

	/* WAIT (Delay)
	** - Description : wait for all threads to be created
	*/
	//for (int i = 0; i < 1000000000; i++) { /* ... */}

	/* MONITOR
	** - Description : check the state of each threads
	*/

	/* WAIT (Parenting)
	** - Description : wait for the thrads to finish their tasks
	*/
	head = tail->next;
	for (int j = 0; j < data.nbr_of_philo; j++)
	{
		status = pthread_join(id[j], NULL);
		if (status > 0)
			return (error_msg("pthread_join", "couldn't wait for thread", EXIT_FAILURE));
		head = head->next;
	}
	return (EXIT_SUCCESS);
}
