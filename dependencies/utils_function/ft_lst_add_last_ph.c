/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_last_ph.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:42:54 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/09 18:26:15 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

t_ph    *new_ph_nd(philo_inf *phil, int id_ph)
{
    t_ph    *ph;

    ph = (t_ph *)ft_calloc(1, sizeof(t_ph));
    if (!ph)
        return (ph);
    ph->ph_id = id_ph;
    ph->final_eat = take_time();
    if (pthread_mutex_init(&ph->forks, NULL) != 0)
        return (NULL);
    ph->total_eat = 0;
    ph->inf_ph = phil;
    ph->next = NULL;
    return (ph);
}

t_ph    *last_ph(t_ph *phil)
{
    if(!phil)
        return (phil);
    while (phil->next)
        phil = phil->next;
    return (phil);
}

void    ft_lst_add_last_ph(t_ph **lst, t_ph *nw_ph)
{
    t_ph *phil;

    phil = *lst;
    if (!nw_ph)
        return ;
    if (!(*lst))
    {
        *lst = nw_ph;
        return ;
    }
    phil = last_ph(*lst);
    phil->next = nw_ph;
}
