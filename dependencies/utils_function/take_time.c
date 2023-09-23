/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:53:41 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/20 17:17:31 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long take_time(void) {
    struct timeval time;
    gettimeofday(&time, NULL);

    return (long long)(time.tv_sec) * 1000 + (long long)(time.tv_usec) / 1000;
}

long long curr_time(t_ph *phil) {
    long long current_time = take_time(); // Get the current time in milliseconds
    long long start_time = phil->inf_ph->t_start; // Get the start time from your struct

    // Calculate the time difference and return it
    return (current_time - start_time);
}

// Function to sleep for a specified time in milliseconds
void slp_time(long long time_in_ms) {
    long long start_time = take_time(); // Get the current time in milliseconds
    long long end_time = start_time + time_in_ms; // Calculate the end time

    // Wait until the current time reaches or exceeds the end time
    while (take_time() < end_time) {
        usleep(100); // Sleep for 100 microseconds (0.1 milliseconds)
    }
}
