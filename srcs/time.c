/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:56:38 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/13 12:07:17 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_gettime(void)
{
	struct timeval tv;
	long	time_sec;

	gettimeofday(&tv, NULL);
	time_sec = tv.tv_usec;
	//long long	time = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL);
	return (time_sec);
}