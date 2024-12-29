/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:58:10 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/29 22:42:38 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Parse arguments and initialize fractol structure
 * Initialize MLX
 * Create window
 * Create image
 * Initialize default view parameters
 * Setup event hooks
 * Initial render
 * Start MLX loop
 */

int	main(int argc, char *argv[])
{
	t_fractol	*fractol;

	fractol = control_args(argc, argv);
	init_mlx(fractol);
	mlx_loop(fractol->connection);
	return (0);
}
