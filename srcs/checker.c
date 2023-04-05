/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:13:48 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/05 11:23:56 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(char ch)
{
	if (ch && (ch >= 48 && ch <= 57))
		return (TRUE);
	return (FALSE);
}

int	ft_is_only_digits(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (ERR_EXISTANCE);
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (FALSE);
		index++;
	}
	return (TRUE);
}

int	ft_check_arguments(int arg_count, char **arg_list)
{
	int	index;

	if (arg_count < 5 || arg_count > 6)
		return (error_msg("Usage",
				"nbr_of_philo lifeTime eatingTime sleepTime (totalEatingTime)",
				0));
	index = 1;
	while (index < arg_count && arg_list[index])
	{
		if (!ft_is_only_digits(arg_list[index]))
			return (error_msg("user input", "non digit arguments", ARG_ERROR));
		index++;
	}
	return (ARG_SUCCESS);
}
