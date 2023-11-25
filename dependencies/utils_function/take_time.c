/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:53:41 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/21 14:12:09 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

long long	take_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long long)(time.tv_sec) *1000 + (long long)(time.tv_usec) / 1000);
}

long long	curr_time(t_ph *phil)
{
	long long	current_time;
	long long	start_time;

	current_time = take_time();
	start_time = phil->inf_ph->t_start;
	return (current_time - start_time);
}

void	slp_time(long long time_in_ms)
{
	long long	start_time;
	long long	end_time;

	start_time = take_time();
	end_time = start_time + time_in_ms;
	while (take_time() < end_time)
		usleep(100);
}
