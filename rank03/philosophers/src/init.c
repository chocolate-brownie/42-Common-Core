/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:43:05 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/03 10:54:16 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
 * TODO: Implement an atol function
 * */

static void init_mutexes(t_setup *setup)
{
	setup->mtx_fork = safe_malloc(setup->phils * sizeof(pthread_mutex_t));
	int i = -1;
	while (++i < setup->phils)
		safe_mutex_handle(&setup->fork[i], INIT);

}

bool	init_setup(int argc, char **argv, t_setup *setup)
{
	if (argc == 5)
	{
		setup->phils = atol(argv[1]);
		setup->time_to_die = atol(argv[2]);
		setup->time_to_eat = atol(argv[3]);
		setup->time_to_sleep = atol(argv[4]);
		setup->last_meal = safe_malloc(setup->phils * sizeof(struct timeval));
		setup->died = false;
		setup->fulled_phils = false;
		init_mutexes(setup);
		gettimeofday(&setup->start, NULL); // reference point time 0
	}
	else
	{
		printf("Program execution as follows\n");
		printf("./philo number_of_philosophers time_to_die time_to_eat "
				"time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return false;
	}
	return (true);
}
