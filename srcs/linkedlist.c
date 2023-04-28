/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:54:47 by arurangi          #+#    #+#             */
/*   Updated: 2023/04/28 12:05:15 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// add node ad the end
t_uniq	*add_node_to_cllist(t_uniq **last)
{
	t_uniq	*newnode;

	newnode = malloc(sizeof(t_uniq));
	if (!newnode)
		return (0);
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
void	del_list(t_uniq **last)
{
	t_uniq	*tmp;

	if (!*last)
		return ;
	while (*last)
	{
		tmp = *last;
		*last = (*last)->next;
		free(tmp);
	}
	*last = 0;
}

void	print_list(t_uniq **last)
{
	t_uniq	*tmp;

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
