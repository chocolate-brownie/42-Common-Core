/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:49:37 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/25 01:22:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/** Main function
 * 1) parsed() --> Error checking and filling the data of the program args
 * 2) data_init() --> Initiate the data of all the structures
 * 3) start_simulation() --> start the dining philo simulation */
int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		printf(GREEN "Success" RESET ": Arguments\n");
		parsing(&data, argv);
	}
	else
		error_exit(RED "Error" RESET ": Invalid arguments\n");
	return (0);
}
