/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:06:55 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/01 22:42:57 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char *argv[])
{
	t_setup setup;
	if (!init_setup(argc, argv, &setup))
		error_exit(RED"[ERROR]"RESET" : initializing setup");
	return 0;
}
