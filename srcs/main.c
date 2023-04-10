/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/10 15:44:18 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Program to discover multi-threading
*/


#include "../includes/philo.h"

void	*routine(void *data)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	// int	*number = malloc(sizeof(int));
	// number[0] = 264;
	//return ((void *) number);
	t_guests *cdata = (t_guests *) data;
	long long	ms = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL);
	pthread_mutex_lock(&cdata->lock);
	printf("%lldms [%d] has taken a fork\n", ms, 1);
	printf("%lldms [%d] is eating\n", ms, 1);
	printf("%lldms [%d] is sleeping\n", ms, 1);
	printf("%lldms [%d] is thinking\n\n", ms, 1);
	pthread_mutex_unlock(&cdata->lock);
	return (NULL);
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
		pthread_create(&head->id, NULL, &routine, &data);
		head = head->next;
	}

	// Monitoring

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