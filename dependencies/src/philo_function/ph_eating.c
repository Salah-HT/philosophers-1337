/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:06:01 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/11 23:43:50 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

// Function representing the philosopher's eating action
void philo_eating(t_ph *_ph) 
{
    // Print an eating message using the print_message function
    print_msg(_ph, ET);

    // Lock the eating mutex to ensure mutual exclusion
    if (pthread_mutex_lock(&_ph->inf_ph->allow_eat) != 0) {
        return; // Return if mutex lock fails
    }

    // Record the time of the last meal and increment the number of meals eaten
    _ph->final_eat = take_time();
    _ph->total_eat++;

    // Check if the philosopher has reached the required number of meals
    if (_ph->total_eat == _ph->inf_ph->nbr_t_eat) {
        _ph->inf_ph->stop_eat; // Increment the finish_ate counter
    }

    // Unlock the eating mutex to allow other philosophers to eat
    if (pthread_mutex_unlock(&_ph->inf_ph->allow_eat) != 0) {
        return; // Return if mutex unlock fails
    }

    // Sleep for the specified time to simulate eating
    sleep_time(_ph->inf_ph->t_die);
}
