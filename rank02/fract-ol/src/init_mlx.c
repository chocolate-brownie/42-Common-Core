/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 03:03:19 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/03 20:15:33 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	clean_mlx(t_fractal *fractal, int error_stage)
{
	if (error_stage >= 2)
	{
		if (fractal->img[0].img_ptr)
		{
			mlx_destroy_image(fractal->conn, fractal->img[0].img_ptr);
			fractal->img[0].img_ptr = NULL;
		}
		if (fractal->img[1].img_ptr)
		{
			mlx_destroy_image(fractal->conn, fractal->img[1].img_ptr);
			fractal->img[1].img_ptr = NULL;
		}
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

static int	init_image_buffers(t_fractal *fractal)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		fractal->img[i].img_ptr = mlx_new_image(fractal->conn, WIDTH, HEIGHT);
		if (!fractal->img[i].img_ptr)
			return (0);
		fractal->img[i].pix_ptr = mlx_get_data_addr(fractal->img[i].img_ptr,
				&fractal->img[i].bpp, &fractal->img[i].line_len,
				&fractal->img[i].endian);
		if (!fractal->img[i].pix_ptr)
			return (0);
		i++;
	}
	fractal->curr_img = 0;
	return (1);
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
/* void	data_init(t_fractal *fractal)
{
	fractal->math.shift_x = 0;
	fractal->math.shift_y = 0;
	fractal->math.hypotenuse = 4.0;
	fractal->math.zoom = fractal->math.hypotenuse / WIDTH;
	fractal->math.iterations = 100;
	if (fractal->param.is_julia && !fractal->param.julia_x
		&& !fractal->param.julia_y)
	{
		fractal->param.julia_x = -0.4;
		fractal->param.julia_y = 0.6;
	}
} */
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
	init_image_buffers(fractal);
	// data_init(fractal);
}
