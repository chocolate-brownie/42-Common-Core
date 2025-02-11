/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:03:36 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/11 02:36:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	thinking(t_philo *philo)
{
	print_message(philo->settings, philo->id, THINKING);
	if (philo->settings->phils % 2 == 0)
		usleep(2000);
	philo->status = EATING;
}

static void	eating(t_philo *philo)
{
	if (grabbing_forks(philo) && !philo_dead(philo->settings))
	{
		print_message(philo->settings, philo->id, EATING);
		safe_mutex_handle(philo->settings->mtx_meal, LOCK);
		gettimeofday(&philo->settings->last_meal[philo->id - 1], NULL);
		safe_mutex_handle(philo->settings->mtx_meal, UNLOCK);
		philo->num_meals++;
		if (philo->settings->must_eat_times > 0
			&& philo->num_meals >= philo->settings->must_eat_times)
		{
			safe_mutex_handle(philo->settings->mtx_full, LOCK);
			philo->is_full = true;
			philo->settings->fulled_phils++;
			safe_mutex_handle(philo->settings->mtx_full, UNLOCK);
		}
		usleep(philo->settings->time_to_eat * 1000);
		safe_mutex_handle(&philo->settings->mtx_fork[philo->id - 1], UNLOCK);
		safe_mutex_handle(&philo->settings->mtx_fork[philo->id
			% philo->settings->phils], UNLOCK);
		philo->status = SLEEPING;
	}
}

static void	sleeping(t_philo *philo)
{
	print_message(philo->settings, philo->id, SLEEPING);
	usleep(philo->settings->time_to_sleep * 1000);
	philo->status = THINKING;
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(2000);
	while (1)
	{
		if (philo_dead(philo->settings) || philo_starved(philo))
			break ;
		if (philo->settings->must_eat_times > 0
			&& philo->settings->fulled_phils == philo->settings->phils)
			break ;
		if (philo->status == THINKING)
			thinking(philo);
		else if (philo->status == EATING)
			eating(philo);
		else if (philo->status == SLEEPING)
			sleeping(philo);
	}
	return NULL;
}
