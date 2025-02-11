/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:43:05 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/10 21:27:42 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	print_usage(void)
{
	printf("Program execution as follows\n");
	printf("./philo number_of_philosophers time_to_die time_to_eat "
			"time_to_sleep [number_of_times_each_philosopher_must_eat]");
}

/* TODO: implement an ft_atol function
 * the function should check for valid inputs and pass within the atol function
 * it shoud grab the 42, from a scenario like this (^&*asd   a*&-42  @$%)
 * if the number is neg it print a usage message and error_exit. */

static void	init_mutexes(t_setup *setup)
{
	unsigned int	i;

	setup->mtx_fork = safe_malloc(setup->phils * sizeof(pthread_mutex_t));
	i = -1;
	while (++i < setup->phils)
		safe_mutex_handle(&setup->mtx_fork[i], INIT);
	setup->mtx_full = safe_malloc(sizeof(pthread_mutex_t));
	setup->mtx_dead = safe_malloc(sizeof(pthread_mutex_t));
	setup->mtx_meal = safe_malloc(sizeof(pthread_mutex_t));
	setup->mtx_print = safe_malloc(sizeof(pthread_mutex_t));
	safe_mutex_handle(setup->mtx_full, INIT);
	safe_mutex_handle(setup->mtx_dead, INIT);
	safe_mutex_handle(setup->mtx_meal, INIT);
	safe_mutex_handle(setup->mtx_print, INIT);
}

bool	init_setup(int argc, char **argv, t_setup *setup)
{
	unsigned int	i;

	if (argc == 5 || argc == 6)
	{
		setup->phils = atol(argv[1]);
		setup->time_to_die = atol(argv[2]);
		setup->time_to_eat = atol(argv[3]);
		setup->time_to_sleep = atol(argv[4]);
		setup->last_meal = safe_malloc(setup->phils * sizeof(struct timeval));
		setup->died = false;
		setup->fulled_phils = 0;
		init_mutexes(setup);
		gettimeofday(&setup->start, NULL);
		i = -1;
		while (++i < setup->phils)
			setup->last_meal[i] = setup->start;
		if (argc == 6)
			setup->must_eat_times = atol(argv[5]);
		else
			setup->must_eat_times = 0;
		debug_print_setup(setup);
	}
	else
	{
		print_usage();
		return (false);
	}
	return (true);
}
