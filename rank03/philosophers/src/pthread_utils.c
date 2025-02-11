/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:54:54 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/11 02:36:00 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	handle_mutex_error(int status, t_controls opcode)
{
	if (status == 0)
		return ;
	if (opcode == INIT && status == EINVAL)
		error_exit(RED "Mutex init failed" RESET ": Invalid value specified");
	else if (opcode == INIT && status == EAGAIN)
		error_exit(RED "Mutex init failed" RESET ": System lacked resources");
	else if (opcode == LOCK && status == EINVAL)
		error_exit(RED "Mutex lock failed" RESET ": Invalid mutex");
	else if (opcode == LOCK && status == EDEADLK)
		error_exit(RED "Mutex lock failed" RESET ": Deadlock detected");
	else if (opcode == UNLOCK && status == EINVAL)
		error_exit(RED "Mutex unlock failed" RESET ": Invalid mutex");
	else if (opcode == UNLOCK && status == EPERM)
		error_exit(RED "Mutex unlock failed" RESET ": Current thread does"
						"not own mutex");
	else if (opcode == DESTROY && status == EINVAL)
		error_exit(RED "Mutex destroy failed" RESET ": Invalid mutex");
	else if (opcode == DESTROY && status == EBUSY)
		error_exit(RED "Mutex destroy failed" RESET ": Mutex is"
						"currently locked");
	else
		error_exit(RED "Unknown mutex error occurred" RESET);
}

void	safe_mutex_handle(pthread_mutex_t *ptr_mutex, t_controls opcode)
{
	if (opcode == INIT)
		handle_mutex_error(pthread_mutex_init(ptr_mutex, NULL), opcode);
	else if (opcode == LOCK)
		handle_mutex_error(pthread_mutex_lock(ptr_mutex), opcode);
	else if (opcode == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(ptr_mutex), opcode);
	else if (opcode == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(ptr_mutex), opcode);
	else
		error_exit(RED"Wrong opcode"RESET": Use INIT, LOCK, UNLOCK or DETACH");
}

void handle_thread_error(int status, t_controls opcode)
{
   if (status == 0)
       return;
   if (opcode == CREATE && status == EAGAIN)
       error_exit(RED"Thread create failed"RESET": Insufficient resources");
   else if (opcode == CREATE && status == EINVAL)
       error_exit(RED"Thread create failed"RESET": Invalid attributes");
   else if (opcode == JOIN && status == EDEADLK)
       error_exit(RED"Thread join failed"RESET": Deadlock detected");
   else if (opcode == JOIN && status == EINVAL)
       error_exit(RED"Thread join failed"RESET": Thread not joinable");
   else if (opcode == JOIN && status == ESRCH)
       error_exit(RED"Thread join failed"RESET": No thread found");
   else if (opcode == DETACH && status == EINVAL)
       error_exit(RED"Thread detach failed"RESET": Invalid thread");
   else if (opcode == DETACH && status == ESRCH)
       error_exit(RED"Thread detach failed"RESET": No thread found");
   else
       error_exit(RED"Unknown thread error"RESET": Unexpected error code");
}

void	safe_thread_handle(pthread_t *ptr_thread, void *(*function)(void *),
		void *data, t_controls opcode)
{
	if (opcode == CREATE)
		handle_thread_error(pthread_create(ptr_thread, NULL, function, data),
			opcode);
	else if (opcode == JOIN)
		handle_thread_error(pthread_join(*ptr_thread, NULL), opcode);
	else if (opcode == DETACH)
		handle_thread_error(pthread_detach(*ptr_thread), opcode);
	else
		error_exit(RED"Wrong opcode"RESET": Use CREATE, JOIN or DETACH");
}
