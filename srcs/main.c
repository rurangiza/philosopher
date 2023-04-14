/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/14 15:07:19 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/

#include "../includes/philo.h"

int	main(int arg_count, char **arg_list)
{
	t_common	*shared_data;
	t_uniq		*tail;
	t_uniq		*head;

	/* *************************** CHECKER **********************************
	** - Description : check for valtid user input
	*/
	if (!valid_user_input(arg_count, arg_list))
		return (EXIT_FAILURE);

	/* ************************** INITIALIZER *******************************
	** - Description : initialize the structures (philo and guests)
	*/
	tail = init_data(arg_count, arg_list);
	head = tail->next;
	shared_data = tail->shared_data;

	/* ***************************** CREATE ********************************
	** - Description : create the threads for each philo
	*/
	print_hud();
	for (int i = 0; i < shared_data->nbr_of_philo; i++)
	{
		pthread_create(&head->tid, NULL, &start_routine, (void *) head);
		usleep(100);
		head = head->next;
	}

	/* ************************** WAIT (Delay) *****************************
	** - Description : wait for all threads to be created
	*/

	/* **************************** MONITOR ********************************
	** - Description : check the state of each threads
	*/

	/* ************************ WAIT (Parenting) ***************************
	** - Description : wait for the thrads to finish their tasks
	*/
	head = tail->next;
	for (int j = 0; j < shared_data->nbr_of_philo; j++)
	{
		pthread_join(head->tid, NULL);
		head = head->next;
	}

	/* ***************************** DISPLAY *******************************
	** - Description : show results
	*/

	/* ************************ DESTORY ALL ASSETS *************************
	** - mutex  : lock, forks
	** - malloc :  
	*/
	pthread_mutex_destroy(&shared_data->lock);
	head = tail->next;
	for (int i = 0; i < shared_data->nbr_of_philo; i++)
		pthread_mutex_destroy(&head->fork);
	return (EXIT_SUCCESS);
}
