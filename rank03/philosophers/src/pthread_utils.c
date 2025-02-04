/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:54:54 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/03 11:52:33 by mgodawat         ###   ########.fr       */
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
		error_exit(RED"Wrong opcode"RESET": Use INIT LOCK UNLOCK or DETACH");
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
		error_exit()
}
