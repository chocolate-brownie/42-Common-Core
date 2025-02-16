/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:26:38 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/16 17:21:09 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/** A philosopher could die if they havent eaten within time_to_die
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

static bool	grabbing_forks(t_philo *philo)
{
	safe_mutex_handle(&philo->settings->mtx_fork[philo->first_fork], LOCK);
	if (someone_died(philo->settings))
	{
		safe_mutex_handle(&philo->settings->mtx_fork[philo->first_fork],
			UNLOCK);
		return (false);
	}
	print_message(philo->settings, philo->id, FORK);
	safe_mutex_handle(&philo->settings->mtx_fork[philo->second_fork], LOCK);
	if (someone_died(philo->settings))
	{
		safe_mutex_handle(&philo->settings->mtx_fork[philo->first_fork],
			UNLOCK);
		safe_mutex_handle(&philo->settings->mtx_fork[philo->second_fork],
			UNLOCK);
		return (false);
	}
	print_message(philo->settings, philo->id, FORK);
	return (true);
}

bool	forks_grabbed(t_philo *philo)
{
	/* printf(BLUE "[Ongoing]" RESET " : forks_grabbed()"); */
	if (!grabbing_forks(philo))
		return (false);
	/* printf(GREEN "[Success]" RESET " : forks_grabbed()"); */
	return (true);
}
