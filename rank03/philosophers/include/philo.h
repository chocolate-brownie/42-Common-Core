/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:42:58 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/16 01:31:02 by mgodawat         ###   ########.fr       */
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
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

typedef enum e_task
{
	THINKING,
	EATING,
	SLEEPING,
	FORK,
	DIED
}					t_task;

typedef enum s_controls
{
	CREATE,
	JOIN,
	DETACH,
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
}					t_controls;

typedef struct s_philo
{
	int id;                 
	t_task status;          
	unsigned int num_meals; 
	bool is_full;           
	unsigned int	first_fork;
	unsigned int	second_fork;
	struct s_setup *settings; 
}					t_philo;

typedef struct s_setup
{
	// Time parameters
	unsigned int phils;          // Total number of philosophers NOTE: OK
	unsigned int time_to_die;    // Max time without eating  NOTE: OK
	unsigned int time_to_eat;    // How long eating takes  NOTE: OK
	unsigned int time_to_sleep;  // How long sleeping takes  NOTE: OK
	unsigned int must_eat_times; // 6th optional argument  NOTE: OK

	// Time tracking
	struct timeval start;      // When simulation started  NOTE: OK
	struct timeval *last_meal; // When each philosopher last ate  NOTE: OK

	// Status flags
	bool died;                 // 	Has anyone died  NOTE: OK
	unsigned int fulled_phils; // How many done eating?  NOTE: OK

	// Mutexes for synchronization
	pthread_mutex_t *mtx_fork;  // Protect access to forks  NOTE: OK
	pthread_mutex_t *mtx_full;  // Protect full status updates   NOTE: OK
	pthread_mutex_t *mtx_dead;  // Protect death status  NOTE: OK
	pthread_mutex_t *mtx_meal;  // Protect meal time updates  NOTE: OK
	pthread_mutex_t *mtx_print; // Prevent mixed up messages  NOTE: OK

	pthread_t *threads; // threads NOTE: Not OK

}					t_setup;

void				error_exit(const char *error);
void				*safe_malloc(size_t size);
void				safe_mutex_handle(pthread_mutex_t *ptr_mutex,
						t_controls opcode);
void				safe_thread_handle(pthread_t *ptr_thread,
						void *(*function)(void *), void *data,
						t_controls opcode);
unsigned int		get_time(struct timeval *ref);
void				clean_up(t_setup *setup);
void				ft_usleep(unsigned int time, t_setup *settings);

bool				init_setup(int argc, char **argv, t_setup *setup);
bool				create_phils(t_setup *setup);

void				*philo_routine(void *arg);
void				thinking(t_philo *philo);
void				eating(t_philo *philo);
void				sleeping(t_philo *philo);
bool				someone_died(t_setup *settings);
void				print_message(t_setup *settings, int philo_id,
						t_task action);
bool				forks_grabbed(t_philo *philo);

// FIX: delete these function
void				debug_print_setup(t_setup *setup);

#endif
