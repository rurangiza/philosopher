/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mgmnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:24:14 by lupin             #+#    #+#             */
/*   Updated: 2023/05/02 20:28:46 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_mutex_trio(pthread_mutex_t *uno,
			pthread_mutex_t *dos, pthread_mutex_t *tres)
{	
	int				index;
	pthread_mutex_t	*tab[3];
	int				status;

	tab[0] = uno;
	tab[1] = dos;
	tab[2] = tres;
	index = 0;
	status = 0;
	while (index < 3)
	{
		status = pthread_mutex_destroy(tab[index]);
		if (status != 0)
		{
			printf("Status = %d\n", status);
			if (status == EINVAL)
				error_msg("thread",
					"can't destroy mutex: invalid mutex value", 0);
			else if (status == EBUSY)
				error_msg("thread",
					"can't destroy mutex: mutex is locked", 0);
		}
		index++;
	}
}
