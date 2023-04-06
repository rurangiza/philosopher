/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arurangi <arurangi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:24:28 by Arsene            #+#    #+#             */
/*   Updated: 2023/04/06 15:49:47 by arurangi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define ARG_ERROR 0
# define ARG_SUCCESS 1
# define TRUE 1
# define FALSE 0
# define ERR_EXISTANCE -1

# define MODE 0

typedef	enum e_error_types {
	ERR_USER = 1
}	t_error_types;

typedef struct global {
	int	nbr_of_philo;
	int	fasting_time;
	int	eating_time;
	int	sleep_time;
	int	max_meals;
}	t_global;

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

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ INITIALIZER ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void	store_input(t_global *global, int arg_count, char **arg_list);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ CHECKERS ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int		valid_user_input(int arg_count, char **arg_list);
int		ft_is_only_digits(char *str);
int		ft_isdigit(char ch);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ ERRORS ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
int		error_msg(char *type, char *msg, int code);
int		err_user(int arg_count);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ DISPLAY ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void	display(t_global global);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~ LIBRARY ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
long	ft_atoi(const char *str);


#endif