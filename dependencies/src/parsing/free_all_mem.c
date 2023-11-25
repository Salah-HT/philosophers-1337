/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:00:18 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/21 15:40:30 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

void	free_all_memory(t_ph *ph, t_philo_inf *philo)
{
	if (pthread_mutex_destroy(&ph->inf_ph->allow_eat) != 0)
	{
	}
	if (pthread_mutex_destroy(&ph->forks) != 0)
	{
	}
	if (pthread_mutex_destroy(&ph->inf_ph->pth_lock) != 0)
	{
	}
	free(philo);
	free(ph);
}
