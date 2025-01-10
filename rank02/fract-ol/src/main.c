/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:03:30 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/07 04:58:30 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	process_julia(t_fractal *fractal)
{
	char	*julia_real;
	char	*julia_imag;

	ft_printf("\nAvailable parameters examples:\n\n");
	ft_printf(" * julia_x = -0.70176, julia_y = -0.3842\n");
	ft_printf(" * julia_x = 0.285, julia_y = 0.01\n");
	ft_printf(" * julia_x = -0.8, julia_y = 0.156\n");
	ft_printf(" * julia_x = 0.355, julia_y = 0.355\n");
	ft_printf(" * julia_x = -0.4, julia_y = 0.6\n");
	ft_printf(" * julia_x = -0.54, julia_y = 0.54\n");
	ft_printf(" * julia_x = -0.7269, julia_y = 0.1889\n");
	ft_printf(" * julia_x = 0.279, julia_y = 0.008\n");
	ft_printf(" * julia_x = -0.835, julia_y = -0.2321\n\n");
	julia_real = get_valid_input("julia x (real): ", fractal);
	julia_imag = get_valid_input("julia y (imaginary): ", fractal);
	fractal->julia_real = ft_atof(julia_real);
	fractal->julia_imag = ft_atof(julia_imag);
	free(julia_real);
	free(julia_imag);
}

void	struct_init(t_fractal *fractal, char *type)
{
	fractal->center_x = 0.0;
	fractal->center_y = 0.0;
	fractal->window_ptr = NULL;
	fractal->zoom_level = 4.0 / SIZE_W;
	fractal->julia_real = 0.0;
	fractal->julia_imag = 0.0;
	fractal->max_iterations = 50;
	fractal->palette_number = 1;
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_ptr, SIZE_W, SIZE_H);
	fractal->image.pixel_addr = mlx_get_data_addr(fractal->image.image_ptr,
			&fractal->image.bits_per_pixel, &fractal->image.line_size,
			&fractal->image.endianness);
	fractal->fractal_type = fractal_type(type);
	if (fractal->fractal_type == 2)
		process_julia(fractal);
}

int	fractal_type(char *argv)
{
	if (ft_strcmp(argv, F1) == 0)
		return (1);
	if (ft_strcmp(argv, F2) == 0)
		return (2);
	if (ft_strcmp(argv, F3) == 0)
		return (3);
	if (ft_strcmp(argv, F4) == 0)
		return (4);
	return (0);
}

int	rendering(t_fractal *vars)
{
	int	x;
	int	y;

	mlx_clear_window(vars->mlx_ptr, vars->window_ptr);
	x = -1;
	while (++x < SIZE_W)
	{
		y = -1;
		while (++y < SIZE_H)
		{
			if (vars->fractal_type == 1)
				draw_mandelbrot(vars, x, y);
			else if (vars->fractal_type == 2)
				draw_julia(vars, x, y);
			else if (vars->fractal_type == 3)
				draw_burning_ship(vars, x, y);
			else if (vars->fractal_type == 4)
				draw_tricorn(vars, x, y);
		}
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->window_ptr,
		vars->image.image_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc != 2 || !fractal_type(argv[1]))
		error_print_usage();
	fractal.mlx_ptr = mlx_init();
	if (!fractal.mlx_ptr)
		error_mlx(argv[1]);
	struct_init(&fractal, argv[1]);
	fractal.window_ptr = mlx_new_window(fractal.mlx_ptr, SIZE_W, SIZE_H,
			argv[1]);
	print_manual();
	mlx_loop_hook(fractal.mlx_ptr, rendering, &fractal);
	mlx_hook(fractal.window_ptr, KEY_PRESS, 1L << 0, key_hook, &fractal);
	mlx_hook(fractal.window_ptr, CLOSE_BUTTON, 1L << 2, btnclose_hook,
		&fractal);
	mlx_hook(fractal.window_ptr, MOUSE_PRESS, 1L << 2, zoom, &fractal);
	mlx_expose_hook(fractal.window_ptr, expose, &fractal);
	mlx_loop(fractal.mlx_ptr);
	destroy(&fractal);
	return (0);
}
