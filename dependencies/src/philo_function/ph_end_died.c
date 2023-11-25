/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_end_died.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:32:55 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/22 17:34:59 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

void	has_died(t_ph *ph)
{
	if (take_time() > ph->inf_ph->t_die + ph->final_eat)
	{
		if (pthread_mutex_lock(&ph->inf_ph->pth_lock) != 0)
			return ;
		printf("\e[0;91m%30lld ms  %d  %s\n\033[0m",
			curr_time(ph), ph->ph_id, DD);
		ph->inf_ph->check = false;
	}
}

// Funct check if a philo has finished eating their required number of times
void	has_ending_eat(t_ph *ph)
{
	if (ph->inf_ph->nbr_ph == ph->inf_ph->stop_eat)
	{
		if (pthread_mutex_lock(&ph->inf_ph->pth_lock) != 0)
			return ;
		ph->inf_ph->check = false;
	}
}

// Function to check if a philosopher has finished and control the simulation
void	has_finished(t_ph *ph)
{
	while (1)
	{
		if (pthread_mutex_lock(&ph->inf_ph->allow_eat) != 0)
			return ;
		has_ending_eat(ph);
		has_died(ph);
		if (!ph->inf_ph->check)
			break ;
		if (pthread_mutex_unlock(&ph->inf_ph->allow_eat) != 0)
			return ;
		ph = ph->next;
	}
}
