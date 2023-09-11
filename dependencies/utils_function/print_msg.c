/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:43:21 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/11 15:56:17 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// Function to print a message with proper synchronization
void print_message(t_ph *_ph, char *s) {
    pthread_mutex_t *p_lock = &_ph->inf_ph->pth_lock; // Get a reference to the philosopher's mutex

    // Attempt to acquire the philosopher's mutex lock
    if (pthread_mutex_lock(p_lock) != 0) {
        // If lock acquisition fails, return (no printing)
        return;
    }

    // Print the message with proper formatting
    printf("\e[0;94m%lld  THE [%d] PHILOSOPHER IS %s\n\033[0m",
           curr_time(_ph), _ph->ph_id, s);

    // Check if testing mode is enabled, and if so, release the lock
    if (_ph->inf_ph->check) {
        if (pthread_mutex_unlock(p_lock) != 0) {
            // If unlock fails, return (no additional action)
            return;
        }
    }
}