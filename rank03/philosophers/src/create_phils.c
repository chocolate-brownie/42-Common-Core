/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_phils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:49:42 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/11 02:35:56 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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
	while (++i < setup->phils)
	{
		init_philo(&philos[i], i + 1, setup);
		safe_thread_handle(&setup->threads[i], philo_routine, &philos[i], CREATE);
	}
	return (true);
}



