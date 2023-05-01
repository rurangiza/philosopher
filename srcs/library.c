/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:59:11 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/01 12:40:57 by arurangi         ###   ########.fr       */
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

void	timer(t_uniq *philo, time_t sleep_time)
{
	// Variable pour mesurer quand le philo doit se réveiller :
	time_t	wake_up;

	wake_up = ft_get_time() + sleep_time;
        // On boucle tant qu'on est pas arrivé au moment de réveil :
	while (ft_get_time() < wake_up)
	{
		// On vérifie si la simulation s'est arrêtée, et si oui, on
		// arrête la boucle (et donc cette fonction) immédiatement
		// pour passer à la suite :
		if (other_died(philo))
			break ;
		// Si la simulation ne s'est pas arrêtée, on usleep une petite valeur :
		usleep(100);
	}
}





