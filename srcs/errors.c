/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:11:27 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/05 10:25:47 by arurangi         ###   ########.fr       */
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
