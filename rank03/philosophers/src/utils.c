/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:39:03 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/02 00:18:10 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *safe_malloc(size_t size)
{
	void *ptr = malloc(size);
	if (!ptr)
		error_exit(RED"ERROR"RESET": malloc failed");
	return ptr;
}

void error_exit(const char *error)
{
	printf("%s\n", error);
	exit(1);
}
