/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_init_ph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:52:02 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/21 15:53:31 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

// Function to add philosophers to the dining simulation
t_ph	*philo_add(t_philo_inf *inf_ph)
{
	t_ph	*new_ph;
	int		i;

	i = 1;
	new_ph = NULL;
	if (pthread_mutex_init(&inf_ph->pth_lock, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&inf_ph->allow_eat, NULL) != 0)
	{
		pthread_mutex_destroy(&inf_ph->pth_lock);
		return (NULL);
	}
	while (i <= inf_ph->nbr_ph)
		ft_lst_add_last_ph(&new_ph, new_ph_nd(inf_ph, i++));
	last_ph(new_ph)->next = new_ph;
	return (new_ph);
}
