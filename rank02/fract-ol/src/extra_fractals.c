/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fractals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:23:13 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 18:26:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Draws Burning Ship fractal at pixel (x,y)
 */
void	render_burning_ship(t_fractal *fractal, int x, int y)
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
		fractal->julia_imag = fabs(2.0 * fractal->julia_real
				* fractal->julia_imag) + cy;
		fractal->julia_real = tmp;
		if (fractal->julia_real * fractal->julia_real + fractal->julia_imag
			* fractal->julia_imag >= 4.)
			break ;
	}
	set_pixel_color(fractal, x, y, i);
}

/**
 * Draws cubic Mandelbrot at pixel (x,y)
 */
void	render_mandelbrot3(t_fractal *fractal, int x, int y)
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
		tmp = fractal->julia_real * (fractal->julia_real * fractal->julia_real
				- 3 * fractal->julia_imag * fractal->julia_imag) + cx;
		fractal->julia_imag = fractal->julia_imag * (3 * fractal->julia_real
				* fractal->julia_real - fractal->julia_imag
				* fractal->julia_imag) + cy;
		fractal->julia_real = tmp;
		if (fractal->julia_real * fractal->julia_real + fractal->julia_imag
			* fractal->julia_imag >= 8.)
			break ;
	}
	set_pixel_color(fractal, x, y, i);
}

/**
 * Calculates next quartic iteration
 */
static void	calc_quartic(t_fractal *fractal, double cx, double cy)
{
	double	tmp;

	tmp = fractal->julia_real * fractal->julia_real * (fractal->julia_real
			* fractal->julia_real - 6 * fractal->julia_imag
			* fractal->julia_imag) + pow(fractal->julia_imag, 4) + cx;
	fractal->julia_imag = 4 * fractal->julia_real * fractal->julia_imag
		* (fractal->julia_real * fractal->julia_real - fractal->julia_imag
			* fractal->julia_imag) + cy;
	fractal->julia_real = tmp;
}

/**
 * Draws quartic Mandelbrot at pixel (x,y)
 */
void	render_mandelbrot4(t_fractal *fractal, int x, int y)
{
	int		i;
	double	cx;
	double	cy;

	i = 0;
	fractal->julia_real = 0.0;
	fractal->julia_imag = 0.0;
	cx = fractal->center_x + (x - WINDOW_WIDTH / 2) * fractal->zoom_level;
	cy = fractal->center_y + (y - WINDOW_HEIGHT / 2) * fractal->zoom_level;
	while (++i < fractal->max_iterations)
	{
		calc_quartic(fractal, cx, cy);
		if (fractal->julia_real * fractal->julia_real + fractal->julia_imag
			* fractal->julia_imag >= 16.)
			break ;
	}
	set_pixel_color(fractal, x, y, i);
}
