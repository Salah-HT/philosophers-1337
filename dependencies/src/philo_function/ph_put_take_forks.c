/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_put_take_forks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:05:57 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/21 16:12:42 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

// Function representing the philosopher putting down forks
void	philo_puts_forks(t_ph *_ph)
{
	if (pthread_mutex_unlock(&_ph->forks) != 0)
		return ;
	if (pthread_mutex_unlock(&_ph->next->forks) != 0)
		return ;
}

void	philo_take_forks(t_ph *_ph)
{
	if (pthread_mutex_lock(&_ph->forks) != 0)
		return ;
	print_msg(_ph, R_FORKS);
	if (pthread_mutex_lock(&_ph->next->forks) != 0)
		return ;
	print_msg(_ph, L_FORKS);
}
