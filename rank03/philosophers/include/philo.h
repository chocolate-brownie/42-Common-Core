/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:42:58 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/03 11:44:48 by mgodawat         ###   ########.fr       */
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
}		t_task;

typedef enum s_controls
{
	CREATE,
	JOIN,
	DETACH,
	INIT,
	LOCK,
	UNLOCK,
	DESTROY
}		t_controls;

typedef struct s_philo
{
	int id;                  // Each philosopher needs a unique identifier
	t_task status;           // Current state (eating/thinking/sleeping)
	unsigned int num_meals;  // Track meals for optional "must eat X times"
	int is_full;             // Flag for when philosopher has eaten enough
	struct s_setup *setting; // Access to shared resources and settings
}		t_philo;

typedef struct s_setup
{
	// Time parameters
	unsigned int phils;         // Total number of philosophers
	unsigned int time_to_die;   // Max time without eating
	unsigned int time_to_eat;   // How long eating takes
	unsigned int time_to_sleep; // How long sleeping takes

	// Time tracking
	struct timeval start;      // When simulation started
	struct timeval *last_meal; // When each philosopher last ate

	// Status flags
	int died;                  // Has anyone died?
	unsigned int fulled_phils; // How many are done eating?

	// Mutexes for synchronization
	pthread_mutex_t *mtx_fork;  // Protect access to forks
	pthread_mutex_t *mtx_full;  // Protect full status updates
	pthread_mutex_t *mtx_dead;  // Protect death status
	pthread_mutex_t *mtx_meal;  // Protect meal time updates
	pthread_mutex_t *mtx_print; // Prevent mixed up messages
								//
}		t_setup;

void	error_exit(const char *error);
void	*safe_malloc(size_t size);
void	safe_mutex_handle(pthread_mutex_t *ptr_mutex, t_controls opcode);

bool	init_setup(int argc, char **argv, t_setup *setup);

#endif
