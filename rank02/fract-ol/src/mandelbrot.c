/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:22:43 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 18:26:59 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Draws basic Mandelbrot set at pixel (x,y)
 */
void	render_mandelbrot(t_fractal *fractal, int x, int y)
{
	int		i;
	double	tmp;
	double	cx;
	double	cy;

	i = 0;
	fractal->julia_real = 0.0;
	fractal->julia_imag = 0.0;
	cx = fractal->center_x + (x - WINDOW_WIDTH / 2) * fractal->zoom_level;
	cy = fractal->center_y + (y - WINDOW_HEIGHT / 2) * fractal->zoom_level;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->julia_real * fractal->julia_real - fractal->julia_imag
			* fractal->julia_imag + cx;
		fractal->julia_imag = 2 * fractal->julia_real * fractal->julia_imag
			+ cy;
		fractal->julia_real = tmp;
		if (fractal->julia_real * fractal->julia_real + fractal->julia_imag
			* fractal->julia_imag >= 4.)
			break ;
	}
	set_pixel_color(fractal, x, y, i);
}

/**
 * Draws Julia set at pixel (x,y)
 */
void	render_julia(t_fractal *fractal, int x, int y)
{
	int		i;
	double	tmp;

	i = 0;
	fractal->julia_real = fractal->center_x + (x - WINDOW_WIDTH / 2)
		* fractal->zoom_level;
	fractal->julia_imag = fractal->center_y + (y - WINDOW_HEIGHT / 2)
		* fractal->zoom_level;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->julia_real;
		fractal->julia_real = fractal->julia_real * fractal->julia_real
			- fractal->julia_imag * fractal->julia_imag + fractal->complex_real;
		fractal->julia_imag = 2 * fractal->julia_imag * tmp
			+ fractal->complex_imag;
		if (fractal->julia_real * fractal->julia_real + fractal->julia_imag
			* fractal->julia_imag >= 4.)
			break ;
	}
	set_pixel_color(fractal, x, y, i);
}

/**
 * Sets color based on iteration count
 */
static void	set_pixel_color(t_fractal *fractal, int x, int y, int iterations)
{
	if (iterations == fractal->max_iterations)
		set_pixel(&fractal->img, x, y, create_color(0, 11, 5, 0));
	else
		set_pixel(&fractal->img, x, y, get_color_palette(iterations,
				fractal->color_palette));
}
