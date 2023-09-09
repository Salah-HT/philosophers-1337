/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_all_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:28:04 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/09 17:29:11 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
