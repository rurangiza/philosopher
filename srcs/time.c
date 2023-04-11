/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:56:38 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/11 11:57:27 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_gettime()
{
	struct timeval tv;

	long long	ms = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL);
	return ;
}