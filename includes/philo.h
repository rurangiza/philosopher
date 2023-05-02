/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupin <lupin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:28 by Arsene            #+#    #+#             */
/*   Updated: 2023/05/02 18:08:10 by lupin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* -------------------------------- INCLUDES -------------------------------- */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

/* --------------------------------- MACROS --------------------------------- */

# define ARG_ERROR 0
# define ARG_SUCCESS 1
# define TRUE 1
# define FALSE 0
# define ERR_EXISTANCE -1
# define DEATH_CURRENT 1
# define DEATH_OTHER 2
# define QUIT 1
# define CONTINUE 0

# define EINVAL 22
# define EBUSY 16

/* ------------------------------- STRUCTURES ------------------------------- */

typedef struct s_common {
	int				nbr_of_philo;
	int				nbr_of_meals;
	int				nbr_of_deaths;
	long			start_time;
	pthread_mutex_t	lock_meals;
	pthread_mutex_t	lock_deaths;
	pthread_mutex_t	lock_stdio;
}	t_common;

typedef struct s_uniq {
	pthread_t		tid;
	unsigned int	number;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	long			time_of_last_meal;
	long			start_time;
	pthread_mutex_t	lock_time_access;
	int				meals_eaten;
	pthread_mutex_t	lock_meals_eaten;
	pthread_mutex_t	fork;
	t_common		*shared_data;
	struct s_uniq	*next;
}	t_uniq;

/* --------------------------------- COLORS --------------------------------- */
# define CGRAY     "\x1b[30m"
# define CRED     "\x1b[31m"
# define CGREEN   "\x1b[32m"
# define CYELLOW  "\x1b[33m"
# define CBLUE    "\x1b[34m"
# define CMAGENTA "\x1b[35m"
# define CCYAN    "\x1b[36m"
# define CWHITE    "\x1b[37m"
# define CBOLD   "\x1b[1m"
# define CRESET   "\x1b[0m"

# define NC	"\e[0m"
# define YELLOW	"\e[1;33m"

/* ------------------------------- INITIALIZER ------------------------------ */
void			save_user_input(t_common *global, int arg_count,
					char **arg_list);
t_uniq			*init_data(int arg_count, char **arg_list);
t_common		*init_shared_data(int arg_count, char **arg_list);
void			init_philo(t_uniq *philo, t_common *shared_data,
					char **arg_list, int counter);

/* -------------------------------- EXECUTION ------------------------------- */
int				start_simulation(t_uniq *philo, t_common *shared_data);
void			end_simulation(t_uniq *philo);
int				monitoring(t_uniq *philo, t_common *shared_data);
void			*start_routine(void *data);

/* --------------------------------- ROUTINE -------------------------------- */
int				eating(t_uniq *philo);
void			drop_forks(t_uniq *philo);
void			take_forks(t_uniq *philo);
void			update_time_of_last_meal(t_uniq *philo);

int				sleeping(t_uniq *philo);
int				thinking(t_uniq *philo);

/* --------------------------------- CHECKER -------------------------------- */
// Input
int				valid_user_input(int arg_count, char **arg_list);
int				ft_is_only_digits(char *str);
int				ft_isdigit(char ch);
// Other
int				other_died(t_uniq *philo);
int				is_dead(t_uniq *philo);
int				is_full(t_common *shared_data, int meals_count);

/* --------------------------------- ERRORS --------------------------------- */
int				error_msg(char *type, char *msg, int code);
int				err_user(int arg_count);
void			print_err_msg(char **data, int arg_count, int index);

void			destroy_mutex_trio(pthread_mutex_t *uno,
					pthread_mutex_t *dos, pthread_mutex_t *tres);

/* --------------------------------- DISPLAY -------------------------------- */
int				print_msg(t_uniq *philo, char *msg, unsigned int type);

/* --------------------------------- LIBRARY -------------------------------- */
long			ft_atoi(const char *str);
unsigned int	ft_strlen(const char *str);

/* -------------------------- CIRCULAR LINKED LIST -------------------------- */
t_uniq			*add_node_to_cllist(t_uniq **last);
void			del_list(t_uniq **last);
void			print_list(t_uniq **last);

/* --------------------------------- CALCUL --------------------------------- */
long			ft_get_time(void);
long			ft_calc_timestamp(t_uniq *philo);
void			timer(t_uniq *philo, time_t sleep_time);
void			msleep(time_t time, char *msg);

#endif