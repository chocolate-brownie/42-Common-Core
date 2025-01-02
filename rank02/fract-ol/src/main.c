/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:14:34 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 18:17:09 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "fractol.h"

/**
 * Sets up starting values for the fractal program
 */
static void	initialize_fractal(t_fractal *fractal, char *type)
{
	char	*real_part;
	char	*imag_part;

	fractal->center_x = 0.0;
	fractal->center_y = 0.0;
	fractal->complex_real = 0.0;
	fractal->complex_imag = 0.0;
	fractal->zoom_level = 4.0 / WINDOW_WIDTH;
	fractal->max_iterations = 50;
	fractal->color_palette = 1;
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	fractal->img.pixel_data = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bits_per_pixel, &fractal->img.line_size,
			&fractal->img.endian);
	fractal->fractal_type = is_valid_fractal(type);
	if (fractal->fractal_type == 2)
		get_julia_parameters(fractal, &real_part, &imag_part);
}

/**
 * Gets Julia set special numbers from user
 */
static void	get_julia_parameters(t_fractal *fractal, char **real, char **imag)
{
	ft_printf("Input real part (float): ");
	*real = get_next_line(FD_STDIN);
	ft_printf("Input imaginary part (float): ");
	*imag = get_next_line(FD_STDIN);
	fractal->complex_real = ft_atof(*real);
	fractal->complex_imag = ft_atof(*imag);
	free(*real);
	free(*imag);
}

/**
 * Sets up all keyboard and mouse controls
 */
static void	setup_hooks(t_fractal *fractal)
{
	mlx_loop_hook(fractal->mlx_ptr, render_frame, fractal);
	mlx_hook(fractal->win_ptr, EVENT_KEY_PRESS, 1L << 0, handle_keypress,
		fractal);
	mlx_hook(fractal->win_ptr, EVENT_MOUSE_PRESS, 1L << 2, handle_zoom,
		fractal);
	mlx_hook(fractal->win_ptr, EVENT_WINDOW_CLOSE, 1L << 2, handle_window_close,
		fractal);
	mlx_expose_hook(fractal->win_ptr, handle_expose, fractal);
}

/**
 * Starts the program and sets up everything
 */
int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (argc != 2 || !is_valid_fractal(argv[1]))
		print_usage_error();
	fractal.mlx_ptr = mlx_init();
	if (!fractal.mlx_ptr)
		print_mlx_error(argv[1]);
	initialize_fractal(&fractal, argv[1]);
	fractal.win_ptr = mlx_new_window(fractal.mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, argv[1]);
	setup_hooks(&fractal);
	mlx_loop(fractal.mlx_ptr);
	handle_close(&fractal);
	return (0);
}
