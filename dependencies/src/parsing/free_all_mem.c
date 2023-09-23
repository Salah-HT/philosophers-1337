/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:00:18 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/17 17:36:26 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

void freeAllMemory(t_ph *ph, philo_inf *philo) 
{
    // Attempt to destroy and free resources, checking for errors

    if (pthread_mutex_destroy(&ph->inf_ph->allow_eat) != 0) {
        // Handle error, or log it if necessary
        // Returning from this function is optional, depending on your error handling strategy
    }

    if (pthread_mutex_destroy(&ph->forks) != 0) {
        // Handle error, or log it if necessary
        // Returning from this function is optional, depending on your error handling strategy
    }

    if (pthread_mutex_destroy(&ph->inf_ph->pth_lock) != 0) {
        // Handle error, or log it if necessary
        // Returning from this function is optional, depending on your error handling strategy
    }

    // Free dynamically allocated memory
    free(philo);
    free(ph);
}
