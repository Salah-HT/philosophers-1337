/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_error_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:46:38 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/17 17:33:34 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

void    display_error() 
{
    //Display an error message in red
    printf("\033[91mError: Invalid Arguments\n\033[0m");
    // Provide usage information in pink and yellow
    printf("\033[95mUsage: ./philo \033[93m<number_of_philosophers> ");
    printf("\033[97;1m<time_to_die> <time_to_eat> <time_to_sleep> ");
    printf("\033[97;1m|| [number_of_times_each_philosopher_must_eat]\n\033[0m");
}

int display_error_msg(const char *errorMessage){
    // Display the error message in light blue

    printf("\033[96;1mError: %s\n\033[0m", errorMessage);
    
    // Return an error code to indicate failure
    return 1;
}
