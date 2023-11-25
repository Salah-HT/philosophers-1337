/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_phil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:07 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/21 15:46:04 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

t_ph	*ph_add(t_philo_inf *info_ph)
{
	t_ph	*new_ph;
	int		i;

	new_ph = NULL;
	if (pthread_mutex_init(&info_ph->pth_lock, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&info_ph->allow_eat, NULL) != 0)
		return (NULL);
	i = 1;
	while (i <= info_ph->nbr_ph)
		ft_lst_add_last_ph(&new_ph, new_ph_nd(info_ph, i++));
	last_ph(new_ph)->next = new_ph;
	return (new_ph);
}

void	create_thrd(t_ph *philo)
{
	int	i;

	i = 1;
	philo->inf_ph->stop_eat = 0;
	while (i++ <= philo->inf_ph->nbr_ph)
	{
		if (pthread_create(&philo->ph_thrd, NULL, &philo_routine, philo) != 0)
		{
			printf("Thread creation failed");
			return ;
		}
		if (pthread_detach(philo->ph_thrd) != 0)
			return ;
		usleep(300);
		philo = philo->next;
	}
}
