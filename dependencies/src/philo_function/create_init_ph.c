/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_init_ph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:52:02 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/13 15:54:08 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

// Function to add philosophers to the dining simulation
t_ph *philo_add(philo_inf *inf_ph) 
{
    t_ph *new_ph = NULL;
    int i = 1;

    // Initialize the mutex for philosopher data access
    if (pthread_mutex_init(&inf_ph->pth_lock, NULL) != 0) {
        return NULL;
    }

    // Initialize the mutex for limiting concurrent eating
    if (pthread_mutex_init(&inf_ph->allow_eat, NULL) != 0) {
        pthread_mutex_destroy(&inf_ph->pth_lock); // Clean up the previously initialized mutex
        return NULL;
    }

    // Add philosophers to the list
    while (i <= inf_ph->nbr_ph) {
        ft_lst_add_last_ph(&new_ph, new_ph_nd(inf_ph, i++));
    }

    // Connect the last philosopher's next pointer to the beginning to form a circular list
    last_ph(new_ph)->next = new_ph;

    return new_ph;
}

