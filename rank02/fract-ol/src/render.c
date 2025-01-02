/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:17:29 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 18:27:03 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * Draws the fractal on screen pixel by pixel
 */
int	render_frame(t_fractal *fractal)
{
	int	x;
	int	y;

	mlx_clear_window(fractal->mlx_ptr, fractal->win_ptr);
	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		y = -1;
		while (++y < WINDOW_HEIGHT)
			render_pixel(fractal, x, y);
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img.img_ptr, 0, 0);
	return (0);
}

/**
 * Picks which fractal to draw at each pixel
 */
static void	render_pixel(t_fractal *fractal, int x, int y)
{
	if (fractal->fractal_type == 1)
		render_mandelbrot(fractal, x, y);
	else if (fractal->fractal_type == 2)
		render_julia(fractal, x, y);
	else if (fractal->fractal_type == 3)
		render_burning_ship(fractal, x, y);
	else if (fractal->fractal_type == 4)
		render_mandelbrot3(fractal, x, y);
	else if (fractal->fractal_type == 5)
		render_mandelbrot4(fractal, x, y);
}

/**
 * Redraws the fractal when window needs updating
 */
int	handle_expose(t_fractal *fractal)
{
	render_frame(fractal);
	return (0);
}
