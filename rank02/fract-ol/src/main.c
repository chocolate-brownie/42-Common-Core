/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:58:10 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/25 22:18:13 by mgodawat         ###   ########.fr       */
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
	if (!fractol)
		return (clean_exit(NULL, "Failed to initialize the program!", 1));
	fractol->connection = mlx_init();
	if (!fractol->connection)
		return (clean_exit(fractol, "Failed to initialize the mlx!", 1));
	fractol->window = mlx_new_window(fractol->connection, WIDTH, HEIGHT,
			fractol->name);
	if (!fractol->window)
		return (clean_exit(fractol, "Failed to create a window!", 1));
	init_view(fractol);
	setup_hooks(fractol);
	render_fractal(fractol);
	mlx_loop(fractol->connection);
	return (0);
}
