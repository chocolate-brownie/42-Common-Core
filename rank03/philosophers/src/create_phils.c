/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_phils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:49:42 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/13 22:14:38 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Thread for philo no: [%d] creating\n", philo->id); // FIX: debug state
	
	while (1)
	{
		if (someone_died(philo->settings))
			break;
		if (philo->status == THINKING)
			thinking(philo);
		/* if (philo->status == EATING) */
		/* 	eating(philo); */
		/* if (philo->status == SLEEPING) */
		/* 	sleeping(philo); */
	}
	return (NULL);
}

static void	init_philo(t_philo *philo, unsigned int id, t_setup *setup)
{
	philo->id = id;
	philo->status = THINKING;
	philo->num_meals = 0;
	philo->is_full = false;
	philo->settings = setup;
}

bool	create_phils(t_setup *setup)
{
	t_philo			*philos;
	unsigned int	i;

	setup->threads = safe_malloc(setup->phils * sizeof(pthread_t));
	philos = safe_malloc(setup->phils * sizeof(t_philo));
	i = -1;
	printf("\n=== Thread Verification ===\n");
	while (++i < setup->phils)
	{
		init_philo(&philos[i], i + 1, setup);
		safe_thread_handle(&setup->threads[i], philo_routine, &philos[i],
			CREATE);
	}
	return (true);
}
