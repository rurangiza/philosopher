/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:28 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/14 14:55:57 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ARG_ERROR 0
# define ARG_SUCCESS 1
# define TRUE 1
# define FALSE 0
# define ERR_EXISTANCE -1

# define MODE 0

/* ~~~~~~~~~~~~~~~~~~~~~~~ STRUCTURES ~~~~~~~~~~~~~~~~~~~~~~~ */

typedef	enum e_error_types {
	ERR_USER = 1
}	t_error_types;

typedef struct s_common {
	int				nbr_of_philo;
	int				nbr_of_meals;
	int				nbr_of_deaths;
	long			start_time;
	pthread_mutex_t	lock;
}	t_common;

typedef struct s_uniq {
	pthread_t		tid;
	unsigned int	number;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	long			time_of_last_meal;
	long			start_time;
	pthread_mutex_t	fork;
	struct s_uniq	*next;
	t_common		*shared_data;
}	t_uniq;


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ COLORS ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ INITIALIZER ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void	save_user_input(t_common *global, int arg_count, char **arg_list);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ CHECKERS ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int		valid_user_input(int arg_count, char **arg_list);
int		ft_is_only_digits(char *str);
int		ft_isdigit(char ch);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ ERRORS ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int		error_msg(char *type, char *msg, int code);
int		err_user(int arg_count);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ DISPLAY ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void	display(t_common *data);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ LIBRARY ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
long	ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);


//t_uniq	*init_philo(t_common *data);
t_uniq	*add_node_to_cllist(t_uniq **last);
void	del_list(t_uniq **last);
void	print_list(t_uniq **last);


void		*start_routine(void *data);
t_uniq		*init_data(int arg_count, char **arg_list);
t_common	*init_shared_data(int arg_count, char **arg_list);
void		init_philo(t_uniq *philo, t_common *shared_data,
				char **arg_list, int counter);

void	start_eating(t_uniq *philo);
void	start_sleeping(t_uniq *philo);
void	start_thinking(t_uniq *philo);

long	ft_get_time(void);
long	ft_calc_timestamp(t_uniq *philo);

int		someone_died(t_uniq *philo);

void	print_msg(t_uniq *philo, char *msg);
void	print_hud(void);

#endif