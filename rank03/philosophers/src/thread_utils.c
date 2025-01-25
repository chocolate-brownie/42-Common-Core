/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:37:25 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/26 00:13:19 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	handle_mutex_error(int status, t_mutexcode code)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (code == LOCK || code == UNLOCK))
		error_exit(RED "Error" RESET ": The mutex has not been "
			"properly initialized.");
	else if (status == EDEADLK)
		error_exit(RED "Error" RESET ": The mutex is already locked by the "
			"calling thread (``error checking'' mutexes only).");
	else if (status == EPERM)
		error_exit(RED "Error" RESET ":The calling thread does not own the "
			 "mutex (``error checking'' mutexes only).");
	else if (status == EBUSY)
		error_exit(RED "Error" RESET "The mutex is currently locked.");
	else if (status == ENOMEM)
		error_exit(RED "Error" RESET "The process cannot allocate enough "
			 "memory to create another mutex.");
}

void	safe_mutex(pthread_mutex_t *mutex, t_mutexcode code)
{
	if (code == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), code);
	else if (code == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), code);
	else if (code == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), code);
	else if (code == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), code);
	else
		error_exit(RED "Error" RESET ": wrong operation code for mutex");
}
