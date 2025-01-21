/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:42:58 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/21 19:10:09 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <errno.h>
#include <stdbool.h>

// Enum for philosopher status (assuming this was defined as t_task)
typedef enum e_task
{
    THINKING,
    EATING,
    SLEEPING,
    FORK_TAKEN,
    DIED
}   t_task;

// Main setup structure for shared data
typedef struct s_setup
{
    // Basic simulation parameters
    __uint16_t      phils;            // Number of philosophers
    __uint32_t      time_to_die;      // Time until death (ms)
    __uint32_t      time_to_eat;      // Time to eat (ms)
    __uint32_t      time_to_sleep;    // Time to sleep (ms)
    __uint32_t      time_to_think;    // Time to think (ms)
    __uint16_t      must_eat_times;   // Optional eat count limit

    // Timing and state tracking
    struct timeval  start;            // Simulation start time
    int             died;             // Death flag for simulation
    __uint16_t      fulled_phils;     // Count of philosophers who've eaten enough
    struct timeval  *last_meal;       // Array of last meal times
    bool            error_flag;        // Track initialization errors

    // Mutexes for thread safety
    pthread_mutex_t *mtx_fork;        // Array of fork mutexes
    pthread_mutex_t *mtx_full;        // Protect fulled_phils counter
    pthread_mutex_t *mtx_dead;        // Protect died flag
    pthread_mutex_t *mtx_meal;        // Protect last_meal times
    pthread_mutex_t *mtx_print;       // Prevent mixed message output
}   t_setup;

// Individual philosopher structure
typedef struct s_philo
{
    int             id;               // Philosopher number (1 to N)
    t_task          status;          // Current philosopher state
    __uint16_t      num_meals;       // Times this philosopher has eaten
    int             is_full;         // Has eaten required times
    int             left_fork;       // Left fork index
    int             right_fork;      // Right fork index
    pthread_t       thread;          // Philosopher's thread ID
    t_setup         *setting;        // Pointer to shared data
}   t_philo;

// Optional: Monitor structure for death checking
typedef struct s_monitor
{
    t_setup         *setup;          // Pointer to setup
    t_philo         *philos;         // Array of philosophers
    pthread_t       thread;          // Monitor thread ID
}   t_monitor;
#endif
