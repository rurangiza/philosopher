/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/12 11:46:17 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/

#include "../includes/philo.h"



int	main(int arg_count, char **arg_list)
{
	t_common	shared_data;
	t_uniq		*tail;
	t_uniq		*head;
	int			status;

	/* CHECKER
	** - Description : check for valtid user input
	*/
	if (!valid_user_input(arg_count, arg_list))
		return (EXIT_FAILURE);

	/* INITIALIZER
	** - Description : initialize the structures (philo and guests)
	*/
	save_user_input(&shared_data, arg_count, arg_list);
	tail = init_philo(&shared_data);
	//tid = malloc(shared_data.nbr_of_philo * sizeof(pthread_t)); // add protection

	/* CREATE
	** - Description : create the threads for each philo
	*/
	counter = 0;
	pthread_mutex_init(&lock, NULL);
	head = tail->next;
	for (int i = 0; i < shared_data.nbr_of_philo; i++)
	{
		status = pthread_create(&head->tid, NULL, &start_routine, (void *) head);
		if (status > 0)
			return (error_msg("pthread_create", "can't create thread", EXIT_FAILURE));
		printf("Main: Creation du thread [%d]\n", head->number);
		//usleep(1000);
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
	for (int j = 0; j < shared_data.nbr_of_philo; j++)
	{
		status = pthread_join(head->tid, NULL);
		if (status > 0)
			return (error_msg("pthread_join", "can't wait for thread", EXIT_FAILURE));
		head = head->next;
	}

	/* DISPLAY
	** - Description : show results
	*/
	printf("Counter = %d\n", counter);
	return (EXIT_SUCCESS);
}
