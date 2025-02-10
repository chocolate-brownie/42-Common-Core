/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:03:36 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/10 18:57:04 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	philo_dead(t_philo *philo); // TODO:

static bool grabbing_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		safe_mutex_handle(&philo->settings->mtx_fork[philo->id - 1], LOCK);
		print_message(philo->settings, philo->id, FORK);
		safe_mutex_handle(&philo->settings->mtx_fork[philo->id % philo->settings->phils], LOCK);
		print_message(philo->settings, philo->id, FORK);
	}
	else if (philo->id % 2 != 0)
	{
		safe_mutex_handle(&philo->settings->mtx_fork[philo->id % philo->settings->phils], LOCK);
		print_message(philo->settings, philo->id, FORK);
		safe_mutex_handle(&philo->settings->mtx_fork[philo->id - 1], LOCK);
		print_message(philo->settings, philo->id, FORK);

	}
	return true;
}

static void	thinking(t_philo *philo)
{
	print_message(philo->settings, philo->id, THINKING);
	if (philo->settings->phils % 2 == 0)
		usleep(2000);
	philo->status = EATING;
}

/* HACK:
 * For the EATING state, there's more to do than just printing. Think about
 * A philosopher needs TWO forks to eat
 * They need to lock the mutexes for those forks
 * They need to update their last meal time
 * They need to wait for time_to_eat duration
 * They need to release the forks
 * They need to increment their meal count*/
static void	eating(t_philo *philo)
{
	if (grabbing_forks(philo)) {
		print_message(philo->settings, philo->id, EATING);

	}
}

void	philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(2000);
	while (1)
	{
		/* FIX: OR when all philos have eaten enough times */
		/* if (philo_dead(philo->settings->died)) */
		/* 	break ; */
		if (philo->status == THINKING)
			thinking(philo);
		else if (philo->status == EATING)
		{
			print_message(philo->settings, philo->id, EATING);
		}
	}
}
