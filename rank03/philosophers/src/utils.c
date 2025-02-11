/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:39:03 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/11 02:45:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

unsigned int	get_time(struct timeval *ref)
{
	struct timeval	current;
	unsigned int	diff;

	gettimeofday(&current, NULL);
	diff = (current.tv_sec - ref->tv_sec) * 1000;
	diff += (current.tv_usec - ref->tv_usec) / 1000;
	return (diff);
}

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		error_exit(RED "ERROR" RESET ": malloc failed");
	return (ptr);
}

void	error_exit(const char *error)
{
	printf("%s\n", error);
	exit(1);
}

void	print_message(t_setup *setup, int phil_id, t_task action)
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

