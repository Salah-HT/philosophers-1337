/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:17:54 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/09 17:19:42 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdint.h>

// struct part :
typedef struct philo_info
{
    long long   nbr_ph;
    long long   nbr_t_eat;
    long long   t_start;
    long long   t_eat;
    long long   t_sleep;
    long long   t_die;
    int         stop_eat;
    bool        check;
    pthread_mutex_t pth_lock;
    pthread_mutex_t allow_eat;
} philo_inf;

typedef struct philo
{
    int ph_id;
    int total_eat;
    long long final_eat;
    struct philo *next;
    philo_inf *inf_ph;
    pthread_mutex_t forks;
    pthread_t ph_thrd;
}t_ph;

//libft_function 
int	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif