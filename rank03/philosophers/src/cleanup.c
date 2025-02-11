/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 02:44:26 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/11 02:47:27 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	clean_other_mtxes(t_setup *setup)
{
	if (setup->mtx_full)
	{
		safe_mutex_handle(setup->mtx_full, DESTROY);
		free(setup->mtx_full);
	}
	if (setup->mtx_dead)
	{
		safe_mutex_handle(setup->mtx_dead, DESTROY);
		free(setup->mtx_dead);
	}
	if (setup->mtx_meal)
	{
		safe_mutex_handle(setup->mtx_meal, DESTROY);
		free(setup->mtx_meal);
	}
	if (setup->mtx_print)
	{
		safe_mutex_handle(setup->mtx_print, DESTROY);
		free(setup->mtx_print);
	}
}

void	clean_up(t_setup *setup)
{
	unsigned int	i;

	if (setup->mtx_fork)
	{
		i = -1;
		while (++i < setup->phils)
			safe_mutex_handle(&setup->mtx_fork[i], DESTROY);
		free(setup->mtx_fork);
	}
	clean_other_mtxes(setup);
	if (setup->threads) 
		free(setup->threads);
	if (setup->last_meal)
		free(setup->last_meal);
}
