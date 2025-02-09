/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:03:36 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/09 19:20:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	print_message(t_setup *setup, int phil_id, t_task action)
{
	safe_mutex_handle(setup->mtx_print, LOCK);
	if (action == THINKING)
		printf("%05u %2d is thinking\n", get_time(&setup->start), phil_id);
	else if (action == EATING)
		printf("%05u %2d is eating\n", get_time(&setup->start), phil_id);
	else if (action == SLEEPING)
		printf("%05u %2d is sleeping\n", get_time(&setup->start), phil_id);
	else if (action == FORK)
		printf("%05u %2d has taken a fork\n", get_time(&setup->start), phil_id);
	else if (action == DIED)
		printf("%05u %2d has died\n", get_time(&setup->start), phil_id);
	safe_mutex_handle(setup->mtx_print, UNLOCK);
}

/* HACK:
 * For the EATING state, there's more to do than just printing. Think about
 * A philosopher needs TWO forks to eat
 * They need to lock the mutexes for those forks
 * They need to update their last meal time
 * They need to wait for time_to_eat duration
 * They need to release the forks
 * They need to increment their meal count*/

void	philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(2000);
	while (1)
	{
		/* FIX: OR when all philos have eaten enough times */
		if (check_if_dead(philo->settings))
			break ;
		if (philo->status == THINKING)
		{
			print_message(philo->settings, philo->id, THINKING);
			if (philo->settings->phils % 2 == 0)
				usleep(2000);
			philo->status = EATING;
		}
		else if (philo->status == EATING)
		{
			print_message(philo->settings, philo->id, EATING);
		}
	}
}
