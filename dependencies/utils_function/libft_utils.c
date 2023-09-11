/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:46:49 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/11 15:47:37 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int is_all_digit(char *str) 
{
    int i = 0;

    if (str[i] == '+') {
        i++;
    }

    while (str[i]) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
        i++;
    }

    return 1;
}

int	ft_atoi(const char *str)
{
	int sign;
	int	i;
	long long 	nbr;

	sign = 1;
	nbr = 0;
	i = 0;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13 ))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;	
	}

	while (str && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + str[i] -'0';
        if (nbr  * sign > INT_MAX)
            return (-1);
        else if (nbr * sign < INT_MIN)
            return (-1);
		i++;
	}
	return((int)nbr * sign);
}
