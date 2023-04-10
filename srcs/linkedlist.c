/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:54:47 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/10 11:48:06 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int count = 1;

// add node ad the end
t_philo	*add_philo(t_philo **last, int content)
{
	t_philo	*newnode;

	newnode = malloc(sizeof(t_philo));
	if (!newnode)
		return (0);
	newnode->number = content;
	if (!*last)
	{
		newnode->next = newnode;
		(*last) = newnode;
	}
	else
	{
		newnode->next = (*last)->next;
		(*last)->next = newnode;
		(*last) = newnode;
	}
	return (newnode);
}

// delete all nodes
void	del_list(t_philo **last)
{
	t_philo	*tmp;

	if (!*last)
		return ;
	while (*last)
	{
		tmp = *last;
		*last = (*last)->next;
		tmp->number = -1;;
		free(tmp);
	}
	*last = 0;
}

void	print_list(t_philo **last)
{
	t_philo	*tmp;

	if (!*last)
		return ;
	tmp = (*last)->next;
	while (tmp)
	{
		printf("number : %i\n", tmp->number);
		if (tmp->number == (*last)->number)
			break ;
		tmp = tmp->next;
	}
}
