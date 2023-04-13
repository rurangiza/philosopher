/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:28 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/13 12:01:30 by arurangi         ###   ########.fr       */
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

unsigned int	counter;
pthread_mutex_t	lock;

/* ~~~~~~~~~~~~~~~~~~~~~~~ STRUCTURES ~~~~~~~~~~~~~~~~~~~~~~~ */

typedef	enum e_error_types {
	ERR_USER = 1
}	t_error_types;

typedef struct s_common {
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	pthread_mutex_t	lock;
	int				nbr_of_deaths;
}	t_common;

typedef struct s_uniq {
	pthread_t		tid;
	unsigned int	number;
	pthread_mutex_t	fork;
	long		time_of_last_meal;
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
void	display(t_common data);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ LIBRARY ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
long	ft_atoi(const char *str);


t_uniq	*init_philo(t_common *data);
t_uniq	*add_philo(t_uniq **last, int content);
void	del_list(t_uniq **last);
void	print_list(t_uniq **last);


void	*start_routine(void *data);

long	ft_gettime(void);

#endif