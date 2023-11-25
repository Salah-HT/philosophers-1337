/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:54:38 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/22 16:40:31 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char **argv)
{
	t_philo_inf	*philo;
	t_ph		*ph;

	if (argc < 5 || argc > 6 || check_input(argc, argv))
	{
		display_error();
		return (1);
	}
	philo = malloc(sizeof(t_philo_inf));
	if (!philo)
	{
		display_error_msg(MEM_ERR);
		return (1);
	}
	take_input(philo, argc, argv);
	ph = philo_add(philo);
	if (!ph)
	{
		free(philo);
		display_error_msg(MEM_ERR);
		return (1);
	}
	create_thrd(ph);
	has_finished(ph);
	free_all_memory(ph, philo);
}
