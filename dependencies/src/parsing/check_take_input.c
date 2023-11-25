/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_take_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:08:18 by shamsate          #+#    #+#             */
/*   Updated: 2023/11/21 14:38:10 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/philo.h"

int	check_input(int ac, char **str)
{
	int	num_ph;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	num_eat;

	num_ph = ft_atoi(str[1]);
	if ((num_ph < 1 || num_ph > 200) || !is_all_digit(str[1]))
		return (display_error_msg(NBR_PH));
	t_die = ft_atoi(str[2]);
	if (t_die < 60 || !is_all_digit(str[2]))
		return (display_error_msg(T_DIE));
	t_eat = ft_atoi(str[3]);
	if (t_eat < 60 || !is_all_digit(str[3]))
		return (display_error_msg(T_EAT));
	t_sleep = ft_atoi(str[4]);
	if (t_sleep < 60 || !is_all_digit(str[4]))
		return (display_error_msg(T_SLP));
	if (ac == 6)
	{
		num_eat = ft_atoi(str[5]);
		if (num_eat < 1 || !is_all_digit(str[5]))
			return (display_error_msg(NBR_EAT));
	}
	return (0);
}

// Function to parse command-line arguments and initialize t_inf_ph struct
void	take_input(t_philo_inf *philo, int ac, char **s)
{
	if (ac > 4)
	{
		philo->nbr_ph = ft_atoi(s[1]);
		philo->t_die = ft_atoi(s[2]);
		philo->t_eat = ft_atoi(s[3]);
		philo->t_sleep = ft_atoi(s[4]);
		philo->t_start = take_time();
		philo->check = true;
		philo->nbr_t_eat = -1;
		if (ac == 6)
			philo->nbr_t_eat = ft_atoi(s[5]);
	}
}
