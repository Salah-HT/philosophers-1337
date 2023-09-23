/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:17:54 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/23 22:43:07 by shamsate         ###   ########.fr       */
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

//function libft
int			ft_atoi(const char *str);
int			is_all_digit(char *str);
//function add node ....
void	    ft_lst_add_last_ph(t_ph **lst, t_ph *nw_ph);
t_ph		*new_ph_nd(philo_inf *phil, int id_ph);
t_ph		*last_ph(t_ph *phil);
void    	print_msg(t_ph *_ph, char *s);
//function for take the time
long long	take_time(void);
long long	curr_time(t_ph *phil);
void		slp_time(long long time);
//parsing check input 
int     	check_input(int ac, char **str);
void    	take_input(philo_inf *philo, int ac, char **s);
void    	display_error();
int 		display_error_msg(const char *errorMessage);
//create philo and threads
t_ph    	*ph_add(philo_inf *info_ph);
t_ph    	*philo_add(philo_inf *inf_ph);
void    	philo_eating(t_ph *_ph);
void    	philo_puts_forks(t_ph *_ph);
void    	philo_take_forks(t_ph *_ph);
void    	has_died(t_ph *ph);
void    	has_ending_eat(t_ph *ph);
void    	has_finished(t_ph *ph);
void    	ph_think(t_ph *_ph);
void    	*philo_routine(void *argv);
void    	create_thrd(t_ph *philo);
void 		freeAllMemory(t_ph *ph, philo_inf *philo);

//define Print_msg arguments..
# define ET "is eating"
# define TK "is thinking"
# define SLP "is Sleeping"
# define DD "is died :( "
# define L_FORKS "has taking The Left Fork"
# define R_FORKS "has taking The Right Fork"
#define NBR_PH "The number Of Philosophers Must Be > \
0 and < 200."
#define T_DIE "It's Time For Those Over 60 to Rest."
#define T_EAT "Sufficient Eating Time Required (More than 60)."
#define T_SLP "Adequate Sleep Time Needed (Greater than 60)."
#define NBR_EAT "Eating Time Must Be More Than 0."
# define MEM_ERR "Memory Allocation Failed."

#endif
