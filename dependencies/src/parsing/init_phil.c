/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_phil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:07 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/13 15:21:47 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

t_ph *ph_add(philo_inf *info_ph)
{
    t_ph *new_ph;
    int i;

    // Initialize a new philosopher pointer.
    new_ph = NULL;

    // Initialize the mutex for protecting philosopher data.
    if (pthread_mutex_init(&info_ph->pth_lock, NULL) != 0)
        return (NULL);

    // Initialize the mutex for limiting concurrent eating.
    if (pthread_mutex_init(&info_ph->allow_eat, NULL) != 0)
        return (NULL);

    // Create and link philosopher nodes.
    i = 1;
    while (i <= info_ph->nbr_ph)
    {
        // Create a new philosopher node and add it to the end of the list.
        ft_lst_add_last_ph(&new_ph, new_ph_nd(info_ph, i++));
    }

    // Connect the last philosopher to the first one, forming a circular linked list.
    last_ph(new_ph)->next = new_ph;

    return (new_ph);
}

void create_thrd(t_ph *philo)
{
    int i = 1;
    philo->inf_ph->stop_eat = 0;

    // Create threads for each philosopher
    while (i++ <= philo->inf_ph->nbr_ph)
    {
        if (pthread_create(&philo->ph_thrd, NULL, &philo_routine, philo) != 0)
        {
            printf("Thread creation failed");
            return;
        }

        // Detach the thread to allow it to clean up automatically when it exits.
        if (pthread_detach(philo->ph_thrd) != 0)
            return;

        // Introduce a small delay to stagger thread execution.
        usleep(300);

        // Move to the next philosopher in the list.
        philo = philo->next;
    }
}
