/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:54:38 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/17 17:32:54 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int main(int argc, char **argv)
 {
    philo_inf *philo;
    t_ph  *ph;

    // Check the number of arguments
    if (argc < 5 || argc > 6) {
        display_error();
        return 1;
    }

    // Check the validity of command-line arguments
    if (check_input(argc, argv)) {
        return 1;
    }

    // Allocate memory for the 'philo' structure
    philo = malloc(sizeof(philo_inf));
    if (!philo) {
        display_error_msg(MEM_ERR);
        return 1;
    }

    // Get command-line arguments and populate 'philo'
    take_input(philo, argc, argv);

    // Add 'philo' to 'ph'
    ph = philo_add(philo);
    if (!ph) {
        free(philo);
        display_error_msg(MEM_ERR);
        return 1;
    }

    // Create threads for philosophers
    create_thrd(ph);

    // Check if any philosopher has finished their task
    has_finished(ph);

    // Free allocated memory and resources
    freeAllMemory(ph, philo);

    return 0;
}
