/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:53 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/12 02:09:21 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

// Routine function for a philosopher's thread
void *philo_routin(void *arg)
 {
    t_ph *_ph = (t_ph *)arg;

    while (true) {
        // Call the function to simulate a philosopher's actions
        philo_take_forks(_ph);
        philo_eating(_ph);
        philo_puts_forks(_ph);
        ph_think(_ph);
    }
    return NULL;
}
