/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:43:21 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/22 22:36:55 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// Function to print a message with proper synchronization
void	print_msg(t_ph *_ph, char *s)
{
	pthread_mutex_t	*p_lock;

	p_lock = &_ph->inf_ph->pth_lock;
	if (pthread_mutex_lock(p_lock) != 0)
		return ;
	printf("\e[0;93m%30lld ms  %d  %s\n\033[0m",
		curr_time(_ph), _ph->ph_id, s);
	if (_ph->inf_ph->check)
	{
		if (pthread_mutex_unlock(p_lock) != 0)
			return ;
	}
}
