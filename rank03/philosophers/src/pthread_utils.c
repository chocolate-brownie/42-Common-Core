/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:37:25 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/28 14:31:06 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	handle_mutex_error(int status, t_mutexcode code)
{
if (status == 0)
		return ;
	if (status == EINVAL && (code == LOCK || code == UNLOCK))
		error_exit(RED "[MUTEX]" RESET ": The mutex has not been "
			"properly initialized.");
	else if (status == EDEADLK)
		error_exit(RED "[MUTEX]" RESET ": The mutex is already locked by the "
			"calling thread (``error checking'' mutexes only).");
	else if (status == EPERM)
		error_exit(RED "[MUTEX]" RESET ":The calling thread does not own the "
			"mutex (``error checking'' mutexes only).");
	else if (status == EBUSY)
		error_exit(RED "[MUTEX]" RESET "The mutex is currently locked.");
	else if (status == ENOMEM)
		error_exit(RED "[MUTEX]" RESET "The process cannot allocate enough "
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

static void	handle_thread_error(int status, t_threadcode code)
{
	if (status == 0)
		return ;
	if (status == EAGAIN && code == CREATE)
		error_exit(RED "[THREAD]" RESET ": Insufficient resources to "
			"create another thread.");
	else if (status == EPERM && code == CREATE)
		error_exit(RED "[THREAD]" RESET ": No permission to set the "
			"scheduling policy and parameters specified in attr.");
	else if (status == EINVAL)
		error_exit(RED "[THREAD]" RESET ": Invalid settings in attr or "
			"thread is not a joinable thread.");
	else if (status == EDEADLK)
		error_exit(RED "[THREAD]" RESET ": A deadlock was detected");
	else if (status == ESRCH)
		error_exit(RED "[THREAD]" RESET ": No thread with the ID thread could "
			"be found.");
	else
		error_exit(RED "Error" RESET ": wrong operation code for threads");
}

void	safe_thread(pthread_t *thread, void *(*func)(void *), void *data,
		t_threadcode code)
{
	if (code == CREATE)
		handle_thread_error(pthread_create(thread, NULL, func, data), code);
	else if (code == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), code);
	else if (code == DETACH)
		handle_thread_error(pthread_detach(*thread), code);
	else
		error_exit(RED "Error" RESET ": wrong operation code for threads");
}
