/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:31:31 by arurangi          #+#    #+#             */
/*   Updated: 2023/05/01 13:32:08 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Check for valid user_input
*/

#include "../includes/philo.h"

int	valid_user_input(int arg_count, char **arg_list)
{
	int		index;

	if (arg_count < 5 || arg_count > 6)
		return (err_user(arg_count));
	index = 1;
	while (index < arg_count && arg_list[index])
	{
		if (!ft_is_only_digits(arg_list[index]))
			return (error_msg("user input", "non valid arguments", FALSE));
		index++;
	}
	return (TRUE);
}

////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

int	ft_isdigit(char ch)
{
	if (ch && (ch >= 48 && ch <= 57))
		return (TRUE);
	return (FALSE);
}
