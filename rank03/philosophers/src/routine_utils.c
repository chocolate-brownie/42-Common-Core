/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:28:15 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/11 01:24:12 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	grabbing_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		safe_mutex_handle(&philo->settings->mtx_fork[philo->id - 1], LOCK);
		print_message(philo->settings, philo->id, FORK);
		safe_mutex_handle(&philo->settings->mtx_fork[philo->id
			% philo->settings->phils], LOCK);
		print_message(philo->settings, philo->id, FORK);
	}
	else if (philo->id % 2 != 0)
	{
		safe_mutex_handle(&philo->settings->mtx_fork[philo->id
			% philo->settings->phils], LOCK);
		print_message(philo->settings, philo->id, FORK);
		safe_mutex_handle(&philo->settings->mtx_fork[philo->id - 1], LOCK);
		print_message(philo->settings, philo->id, FORK);
	}
	return (true);
}

bool	philo_dead(t_setup *settings)
{
	bool	is_dead;

	safe_mutex_handle(settings->mtx_dead, LOCK);
	is_dead = settings->died;
	safe_mutex_handle(settings->mtx_dead, UNLOCK);
	return (is_dead);
}

bool	philo_starved(t_philo *philo)
{
	unsigned int	time_since_meal;

	safe_mutex_handle(philo->settings->mtx_meal, LOCK);
	time_since_meal = get_time(&philo->settings->last_meal[philo->id - 1]);
	safe_mutex_handle(philo->settings->mtx_meal, UNLOCK);
	if (time_since_meal > philo->settings->time_to_die)
	{
		safe_mutex_handle(philo->settings->mtx_dead, LOCK);
		philo->settings->died = true;
		safe_mutex_handle(philo->settings->mtx_dead, UNLOCK);
		print_message(philo->settings, philo->id, DIED);
		return (true);
	}
	return (false);
}
