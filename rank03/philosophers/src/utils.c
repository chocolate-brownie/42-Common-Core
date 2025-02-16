/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:39:03 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/15 02:13:13 by mgodawat         ###   ########.fr       */
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

void	ft_usleep(unsigned int time, t_setup *settings)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	while (get_time(&current) < time)
	{
		if (someone_died(settings))
			break ;
		usleep(100);
	}
}
