/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:06:01 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/21 15:58:23 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

// Function representing the philosopher's eating action
void	philo_eating(t_ph *_ph)
{
	print_msg(_ph, ET);
	if (pthread_mutex_lock(&_ph->inf_ph->allow_eat) != 0)
		return ;
	_ph->final_eat = take_time();
	_ph->total_eat++;
	if (_ph->total_eat == _ph->inf_ph->nbr_t_eat)
		_ph->inf_ph->stop_eat++;
	if (pthread_mutex_unlock(&_ph->inf_ph->allow_eat) != 0)
		return ;
	slp_time(_ph->inf_ph->t_eat);
}
