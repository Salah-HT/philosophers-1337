/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:53:41 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/09 18:04:58 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long   take_time(void)
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long   curr_time(t_ph *phil)
{
    return (take_time() - phil->inf_ph->t_start);
}

void    slp_time(long long time)
{
    long long srt_time;

    srt_time = take_time();
    while (take_time() < time + srt_time)
        usleep(100);
}
