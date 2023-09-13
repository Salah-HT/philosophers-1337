/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:04 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/13 15:21:07 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

// Function to parse command-line arguments and initialize t_inf_ph struct
void take_input(philo_inf *philo, int ac, char **s) {
    if (ac > 4) {
        philo->nbr_ph = ft_atoi(s[1]);         // Parse and store the number of philosophers
        philo->t_die = ft_atoi(s[2]);       // Parse and store the time to die
        philo->t_eat = ft_atoi(s[3]);       // Parse and store the time to eat
        philo->t_sleep = ft_atoi(s[4]);     // Parse and store the time to sleep
        philo->t_start = take_time();        // Initialize the start time (you need to define 'get_time' function)
        philo->check= true;                    // Set 'test' to true
        philo->nbr_t_eat = -1;              // Initialize the number of times a philosopher must eat

        if (ac == 6) {
            philo->nbr_t_eat = ft_atoi(s[5]);  // If there is a 6th argument, parse and store it as the number of times to eat
        }
    }
}