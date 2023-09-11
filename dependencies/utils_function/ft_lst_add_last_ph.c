/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_last_ph.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:42:54 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/11 15:22:35 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// t_ph    *new_ph_nd(philo_inf *phil, int id_ph)
// {
//     t_ph    *ph;

//     ph = (t_ph *)ft_calloc(1, sizeof(t_ph));
//     if (!ph)
//         return (ph);
//     ph->ph_id = id_ph;
//     ph->final_eat = take_time();
//     if (pthread_mutex_init(&ph->forks, NULL) != 0)
//         return (NULL);
//     ph->total_eat = 0;
//     ph->inf_ph = phil;
//     ph->next = NULL;
//     return (ph);
// }

t_ph* new_ph_nd(philo_inf* phil, int id_ph) {
    t_ph* ph = (t_ph*)malloc(sizeof(t_ph)); 

    if (!ph) {
        perror("Failed to allocate memory for t_ph");
        return NULL;
    }

    ph->ph_id = id_ph;
    ph->final_eat = take_time(); // Use take_time(NULL) to get the current time
    if (pthread_mutex_init(&ph->forks, NULL) != 0) {
        perror("Failed to initialize mutex");
        free(ph);
        return NULL;
    }

    ph->total_eat = 0;
    ph->inf_ph = phil;
    ph->next = NULL;

    return ph;
}

t_ph* last_ph(t_ph* phil) {
    if (!phil || !phil->next) {
        return phil;
    }
    return last_ph(phil->next);
}


// void    ft_lst_add_last_ph(t_ph **lst, t_ph *nw_ph)
// {
//     t_ph *phil;

//     phil = *lst;
//     if (!nw_ph)
//         return ;
//     if (!(*lst))
//     {
//         *lst = nw_ph;
//         return ;
//     }
//     phil = last_ph(*lst);
//     phil->next = nw_ph;
// }

void ft_lst_add_last_ph(t_ph **lst, t_ph *nw_ph) {
    if (!nw_ph)
        return;

    if (!(*lst)) {
        *lst = nw_ph;
        return;
    }

    t_ph *last = last_ph(*lst); // Use the last_ph function to find the last element
    last->next = nw_ph;
}
