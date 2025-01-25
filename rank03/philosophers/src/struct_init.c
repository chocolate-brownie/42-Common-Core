/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:03:19 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/25 23:57:07 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void struct_init(t_data *data)
{
	data->end_simulation = false;
	data->philos = safe_malloc(data->philo_nbr);
	return;
}

