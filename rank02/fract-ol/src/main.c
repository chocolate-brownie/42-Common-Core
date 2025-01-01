/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:58:10 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/01 18:47:35 by mgodawat         ###   ########.fr       */
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
	t_fractol	*mlx;

	mlx = control_args(argc, argv);
	init_mlx(mlx);
	init_view(mlx);
	setup_hooks(mlx);
	mlx_loop(mlx->connection);
	return (0);
}
