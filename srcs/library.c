/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:59:11 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/24 14:56:18 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;	
	}
	return (len);
}

long	ft_atoi(const char *str)
{
	long		i;
	int			sign;
	long		result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (sign * result);
}

int	ft_delay(t_uniq *philo, long time)
{
	int	index = 0;
	
	while (index < time)
	{
		if (ft_get_time() - philo->time_of_last_meal > philo->time_to_die)
		{
			printf("[index = %d /  %ld ]\n", index, ft_get_time() - philo->time_of_last_meal);
			//print_msg(philo, "starving", DEATH);
			return (1);
		}
		timer(1);
		index++;
	}
	return (0);
}

void	timer(long milliseconds)
{
	usleep(milliseconds * 1000);
}







