/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:24:21 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/05 11:21:31 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Visual display of program's state
*/

#include "../includes/philo.h"

void	display_args(int arg_count, char **arg_list)
{
	printf(CBOLD"• ~~~ %s philosophers ~~~ •\n"CRESET, arg_list[1]);
	printf("|_ Lifetime : %sms\n", arg_list[2]);
	printf("|_ Eating time : %sms\n", arg_list[3]);
	printf("|_ Sleeping time : %sms\n", arg_list[4]);
	if (arg_count == 6)
		printf("|_ Maximum meals : %s\n", arg_list[5]);
}
