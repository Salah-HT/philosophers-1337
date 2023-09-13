/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_&_take_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:26:17 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/13 15:26:20 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

int check_input(int ac, char **str)
{
    // Check the number of philosophers
    int num_ph = ft_atoi(str[1]);
    if (num_ph < 1 || num_ph > 200 || !is_all_digit(str[1]))
    {
        return ft_error_arg(NBR_PH);
    }

    // Check the time to die
    int t_die = ft_atoi(str[2]);
    if (t_die < 60 || !is_all_digit(str[2]))
    {
        return ft_error_arg(T_DIE);
    }

    // Check the time to eat
    int t_eat = ft_atoi(str[3]);
    if (t_eat < 60 || !is_all_digit(str[3]))
    {
        return ft_error_arg(T_EAT);
    }

    // Check the time to sleep
    int t_sleep = ft_atoi(str[4]);
    if (t_sleep < 60 || !is_all_digit(str[4]))
    {
        return ft_error_arg(T_SLP);
    }

    // If there is a 6th argument, check the number of times each philosopher must eat
    if (ac == 6)
    {
        int num_eat = ft_atoi(str[5]);
        if (num_eat < 1 || !is_all_digit(str[5]))
        {
            return ft_error_arg(NBR_EAT);
        }
    }

    return 0; // All checks passed
}

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
