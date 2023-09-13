/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:17:54 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/13 14:18:22 by shamsate         ###   ########.fr       */
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
int		ft_atoi(const char *str);
int		is_all_digit(char *str);
//lst utils (create node - add last )
t_ph	*new_ph_nd(philo_inf *phil, int id_ph);
t_ph	*last_ph(t_ph *phil);
void	ft_lst_add_last_ph(t_ph **lst, t_ph *nw_ph);
void    print_msg(t_ph *_ph, char *s);
//handling time ..
long long	take_time(void);
long long	curr_time(t_ph *phil);
void	slp_time(long long time);
//philo & mutex function 
t_ph *philo_add(philo_inf *inf_ph);
void philo_eating(t_ph *_ph);
void philo_puts_forks(t_ph *_ph);
void philo_take_forks(t_ph *_ph);
void has_died(t_ph *ph);
void has_ending_eat(t_ph *ph);
void has_finished(t_ph *ph);
void ph_think(t_ph *_ph);
void *philo_routine(void *arg);

//define Print_msg arguments..
# define ET "\e[1;35m-Start Eating 🥘-.\033[0m"
# define TK "\e[1;32m-Start Thinking 🧘-.\033[0m"
# define SLP "\e[1;33m-Start Sleeping 🛌-.\033[0m"
# define DD "\e[1;31m-Died 🆘-.\033[0m"
# define L_FORKS "\e[1;30m -THE LEFT FORK 🍴Taking-.\033[0m"
# define R_FORKS "\e[1;30m -THE RIGHT FORK 🍴 Taking-.\033[0m"
#define NBR_PH "\e[1;33mThe number of philosophers must be > \
0 and < 200.\033[0m"
#define T_DIE "\e[1;33mIt's Time for Those Over 60 to Rest.\033[0m"
#define T_EAT "\e[1;33mSufficient Eating Time Required (More than 60).\033[0m"
#define T_SLP "\e[1;33mAdequate Sleep Time Needed (Greater than 60).\033[0m"
#define NBR_EAT "\e[1;33mEating Time Must Be More Than 0.\033[0m"


#endif
