/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:26:38 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/15 02:25:16 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/** NOTE: A philosopher could die if they havent eaten within time_to_die
 * milliseconds
 * 1. since their last meal
 * 2. since the start of the simulation
 *
 * if (time since their last meal > time_to_die)
 *		print_message()
 *		died = true */

bool	someone_died(t_setup *settings)
{
	unsigned int	i;
	unsigned int	current_time;

	i = -1;
	while (++i < settings->phils)
	{
		safe_mutex_handle(settings->mtx_meal, LOCK);
		current_time = get_time(&settings->last_meal[i]);
		if (current_time > settings->time_to_die)
		{
			print_message(settings, i + 1, DIED);
			safe_mutex_handle(settings->mtx_dead, LOCK);
			settings->died = true;
			safe_mutex_handle(settings->mtx_dead, UNLOCK);
			safe_mutex_handle(settings->mtx_meal, UNLOCK);
			return (true);
		}
		safe_mutex_handle(settings->mtx_meal, UNLOCK);
	}
	return (false);
}

void	print_message(t_setup *settings, int philo_id, t_task action)
{
	safe_mutex_handle(settings->mtx_print, LOCK);
	if (action == THINKING)
		printf("%05u %2d is thinking\n", get_time(&settings->start), philo_id);
	else if (action == EATING)
		printf("%05u %2d is eating\n", get_time(&settings->start), philo_id);
	else if (action == SLEEPING)
		printf("%05u %2d is sleeping\n", get_time(&settings->start), philo_id);
	else if (action == FORK)
		printf("%05u %2d has taken a fork\n", get_time(&settings->start),
			philo_id);
	else if (action == DIED)
		printf("%05u %2d has died\n", get_time(&settings->start), philo_id);
	safe_mutex_handle(settings->mtx_print, UNLOCK);
}

/**
 * 1. Grab both forks using the forks_grabbed helper function
 *    - Even numbered philosophers grab right fork first
 *    - Odd numbered philosophers grab left fork first
 *    - if someone died during the fork grabbing session unlock forks and
 *		return false
 *    - For single philosopher case, returns false after fork grab attempt */

static void	assign_forks(unsigned int first_fork, unsigned int second_fork,
		t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		first_fork = philo->id % philo->settings->phils;
		second_fork = philo->id - 1;
	}
	else
	{
		first_fork = philo->id - 1;
		second_fork = philo->id % philo->settings->phils;
	}
}

bool	forks_grabbed(t_philo *philo)
{
	unsigned int	first_fork;
	unsigned int	second_fork;

	if (philo->settings->phils == 1)
	{
		safe_mutex_handle(&philo->settings->mtx_fork[0], LOCK);
		print_message(philo->settings, philo->id, FORK);
		ft_usleep(philo->settings->time_to_die + 10, philo->settings);
		safe_mutex_handle(&philo->settings->mtx_fork[0], UNLOCK);
		return (false);
	}
	assign_forks(first_fork, second_fork, philo);
	safe_mutex_handle(&philo->settings->mtx_fork[first_fork], LOCK);
	print_message(philo->settings, philo->id, FORK);
	return (true);
}
