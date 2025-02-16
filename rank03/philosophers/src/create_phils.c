/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_phils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:49:42 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/16 01:38:19 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (someone_died(philo->settings))
			break ;
		if (philo->status == THINKING)
			thinking(philo);
		if (philo->status == EATING)
			eating(philo);
		/* if (philo->status == SLEEPING) */
		/* 	sleeping(philo); */
	}
	return (NULL);
}


static void	assign_forks(unsigned int *first_fork, unsigned int *second_fork,
		t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		*first_fork = philo->id % philo->settings->phils;
		*second_fork = philo->id - 1;
	}
	else
	{
		*first_fork = philo->id - 1;
		*second_fork = philo->id % philo->settings->phils;
	}
}
static void	init_philo(t_philo *philo, unsigned int id, t_setup *setup)
{
	philo->id = id;
	philo->status = THINKING;
	philo->num_meals = 0;
	philo->is_full = false;
	philo->settings = setup;
	assign_forks(&philo->first_fork, &philo->second_fork, philo);
}

bool	create_phils(t_setup *setup)
{
	t_philo			*philos;
	unsigned int	i;

	setup->threads = safe_malloc(setup->phils * sizeof(pthread_t));
	philos = safe_malloc(setup->phils * sizeof(t_philo));
	i = -1;
	while (++i < setup->phils)
	{
		init_philo(&philos[i], i + 1, setup);
		safe_thread_handle(&setup->threads[i], philo_routine, &philos[i],
			CREATE);
	}
	return (true);
}
