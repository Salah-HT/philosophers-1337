/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:53 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/21 16:14:29 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

// Routine function for a philosopher's thread
void	*philo_routine(void *argv)
{
	t_ph	*_ph;

	_ph = (t_ph *)argv;
	while (true)
	{
		philo_take_forks(_ph);
		philo_eating(_ph);
		philo_puts_forks(_ph);
		ph_think(_ph);
	}
	return (NULL);
}
