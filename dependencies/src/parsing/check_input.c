/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:04:09 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/13 14:47:46 by shamsate         ###   ########.fr       */
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


