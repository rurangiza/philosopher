/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:11:27 by Arsene            #+#    #+#             */
/*   Updated: 2023/05/01 13:35:56 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_msg(char *type, char *msg, int code)
{
	printf(CRED"• Error "CRESET);
	printf(CBOLD"(%s) "CRESET, type);
	printf("%s\n", msg);
	return (code);
}

int	err_user(int arg_count)
{
	char	*data[6];
	int		index;

	data[0] = "./philo";
	data[1] = "nbr_of_philo";
	data[2] = "time_to_die";
	data[3] = "time_to_eat";
	data[4] = "time_to_sleep";
	data[5] = "(Maximum_Meals)";
	printf(CRED"✘\033[0m Usage: ");
	index = 0;
	while (index < 6)
	{
		print_err_msg(data, arg_count, index);
		index++;
	}
	printf("\n");
	return (0);
}

void	print_err_msg(char **data, int arg_count, int index)
{
	if (index < arg_count)
	{
		if (index == 0)
			printf(CBOLD"%s "CRESET, data[index]);
		else
		{
			if (index % 2 == 0)
				printf(CGREEN CBOLD"%s "CRESET, data[index]);
			else
				printf(CGREEN"%s "CRESET, data[index]);
		}
	}
	else
		printf(CGRAY"%s "CRESET, data[index]);
}
