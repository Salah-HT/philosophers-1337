/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thinking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:58 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/21 16:15:27 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

// Function for the philosopher to sleep and think
void	ph_think(t_ph *_ph)
{
	print_msg(_ph, SLP);
	slp_time(_ph->inf_ph->t_sleep);
	print_msg(_ph, TK);
}
