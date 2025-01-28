/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:42:58 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/28 01:15:27 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

struct	s_data;

typedef enum e_mutexcode
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
}					t_mutexcode;

typedef enum e_threadcode
{
	CREATE,
	EXIT,
	JOIN,
	DETACH
}					t_threadcode;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;

}					t_fork;

typedef struct s_philo
{
	int				philo_id;
	long			meals_counter;
	bool			full;
	long			last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	thread_id;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	long			philo_nbr;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_limit_meals;
	long			start_simulation;
	bool			end_simulation;
	t_fork			*forks;
	t_philo			*philos;
}					t_data;

void				error_exit(const char *message);
void				parsing(t_data *data, char **argv);
void				struct_init(t_data *data);
void				*safe_malloc(size_t bytes);
void				safe_thread(pthread_t *thread, void *(*func)(void *),
						void *data, t_threadcode code);
void				safe_mutex(pthread_mutex_t *mutex, t_mutexcode code);

/*WARNING: Delete these functions before the last push (debugging)*/
void				print_structure(t_data *data);

#endif
