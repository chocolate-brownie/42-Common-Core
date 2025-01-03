/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 03:03:19 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/03 04:20:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	clean_mlx(t_fractal *fractal, int error_stage)
{
	if (error_stage >= 2 && fractal->img.img_ptr)
	{
		mlx_destroy_image(fractal->conn, fractal->img.img_ptr);
		fractal->img.img_ptr = NULL;
	}
	if (error_stage >= 1 && fractal->win)
	{
		mlx_destroy_window(fractal->conn, fractal->win);
		fractal->win = NULL;
	}
	if (error_stage >= 0 && fractal->conn)
	{
		mlx_destroy_display(fractal->conn);
		free(fractal->conn);
		fractal->conn = NULL;
	}
}

void	error_exit(char *msg, t_fractal *fractal, int error_stage)
{
	if (fractal)
		clean_mlx(fractal, error_stage);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/**
 * @brief  Initializes fractal parameters with default values
 * Sets up zoom, position, iterations, and Julia set parameters
 */
void	data_init(t_fractal *fractal)
{
	fractal->math.shift_x = 0;
	fractal->math.shift_y = 0;
	fractal->math.zoom = 1.0;
	fractal->math.iterations = 100;
	fractal->math.hypotenuse = 4.0;
	if (fractal->param.is_julia && !fractal->param.julia_x
		&& !fractal->param.julia_y)
	{
		fractal->param.julia_x = -0.4;
		fractal->param.julia_y = 0.6;
	}
}

/**
 * @brief  Initializes MLX and creates window and image
 */
void	init_mlx(t_fractal *fractal)
{
	if (!fractal)
		error_exit("[ERROR]: Invalid fractal pointer", NULL, 0);
	fractal->conn = mlx_init();
	if (!fractal->conn)
		error_exit(ERR_MLX_INIT, fractal, 0);
	fractal->win = mlx_new_window(fractal->conn, WIDTH, HEIGHT,
			fractal->param.program_name);
	if (!fractal->win)
		error_exit(ERR_WIN_INIT, fractal, 1);
	fractal->img.img_ptr = mlx_new_image(fractal->conn, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
		error_exit(ERR_IMG_INIT, fractal, 2);
	fractal->img.pix_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	if (!fractal->img.pix_ptr)
		error_exit(ERR_ADDR_INIT, fractal, 2);
	data_init(fractal);
}
