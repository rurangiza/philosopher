/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arsene <Arsene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:13 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/04 08:14:07 by Arsene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*
 * arguments
 * [0] program_name
 * [1] number_of_philosophers
 * [2] time_to_die
 * [3] time_to_eat
 * [4] time_to_sleep
 * [5] number_of_times_each_philosopher_must_eat
*/

#include "philo.h"

int main(int arg_count, char **arg_list)
{
    int status;
    
    status = ft_check_arguments(arg_count, arg_list);
    if (status == ARG_ERROR)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}