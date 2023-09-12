/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_end_died.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:32:55 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/12 01:33:39 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../include/philo.h"

// Function to check if a philosopher has died
void has_died(t_ph *ph) 
{
    long long current_time_value = curr_time(ph);

    // Calculate the time since the last meal
    long long time_since_last_meal = current_time_value - ph->final_eat;

    // Check if the philosopher has exceeded the time to die
    if (time_since_last_meal > ph->inf_ph->t_die) {
        // Try to lock the philosopher's lock
        if (pthread_mutex_lock(&ph->inf_ph->pth_lock) != 0)
            return;

        // Print a message indicating that the philosopher has died
        printf("\e[0;94m%lld  THE [%d] PHILOSOPHER %s\n\033[0m", \
            current_time_value, ph->ph_id, DD);

        // Set the 'test' flag to false, indicating that the philosopher has died
        ph->inf_ph->check = false;

        // Unlock the philosopher's lock
        pthread_mutex_unlock(&ph->inf_ph->pth_lock);
    }
}


// Function to check if a philosopher has finished eating their required number of times
void has_ending_eat(t_ph *ph) 
{
    // Check if the philosopher has a specific number of meals they must eat
    if (ph->inf_ph->nbr_t_eat > 0) {
        // Check if all philosophers have finished eating
        if (ph->inf_ph->nbr_ph == ph->inf_ph->stop_eat) {
            // Try to lock the common lock
            if (pthread_mutex_lock(&ph->inf_ph->pth_lock) != 0)
                return;

            // Set the 'test' flag to false, indicating the simulation is complete
            ph->inf_ph->check = false;

            // Unlock the common lock
            pthread_mutex_unlock(&ph->inf_ph->pth_lock);
        }
    }
}

// Function to check if a philosopher has finished and control the simulation
void has_finished(t_ph *ph) 
{
    while (true) {
        // Try to lock the eat lock
        if (pthread_mutex_lock(&ph->final_eat) != 0)
            return;

        // Check if the philosopher has finished eating their required number of meals
        has_ending_eat(ph);

        // Check if the philosopher has died
        has_died(ph);

        // If the simulation is not running, break the loop
        if (!ph->inf_ph->check)
            break;

        // Unlock the eat lock
        if (pthread_mutex_unlock(&ph->final_eat) != 0)
            return;

        // Move to the next philosopher
        ph = ph->next;
    }
}