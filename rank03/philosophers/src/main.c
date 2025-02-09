/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:06:55 by mgodawat          #+#    #+#             */
/*   Updated: 2025/02/09 15:11:47 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_setup	setup;

	if (!init_setup(argc, argv, &setup))
		error_exit(RED "[Error]" RESET " : initializing setup structure");
	if (!create_phils(&setup))
	{
		clean_up(); 
		error_exit(RED "[Error]" RESET " : creating philosophers");
	}
	return (0);
}
