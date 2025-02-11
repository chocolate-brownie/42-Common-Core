/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:06:55 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/11 02:41:44 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


int	main(int argc, char *argv[])
{
	t_setup			setup;
	unsigned int	i;

	if (!init_setup(argc, argv, &setup))
		error_exit(RED "[Error]" RESET " : initializing setup structure");
	if (!create_phils(&setup))
	{
		clean_up(&setup);
		error_exit(RED "[Error]" RESET " : creating philosophers");
	}
	i = -1;
	while (++i < setup.phils)
		safe_thread_handle(&setup.threads[i], NULL, NULL, JOIN);
	clean_up(&setup);
	return (0);
}
