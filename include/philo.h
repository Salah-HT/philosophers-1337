/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:17:54 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/11 17:22:46 by shamsate         ###   ########.fr       */
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


# define ET "\e[1;35mStart Eating 🥘.\033[0m"
# define TK "\e[1;32mStart Thinking 🧘.\033[0m"
# define SlP "\e[1;33mStart Sleeping 🛌.\033[0m"
# define DD "\e[1;31mDied 🆘 .\033[0m"

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

//handling time ..
long long	take_time(void);
long long	curr_time(t_ph *phil);
void	slp_time(long long time);


//libft_function 
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		is_all_digit(char *str);

//lst utils (create node - add last )
t_ph	*new_ph_nd(philo_inf *phil, int id_ph);
t_ph	*last_ph(t_ph *phil);
void	ft_lst_add_last_ph(t_ph **lst, t_ph *nw_ph);

#endif
